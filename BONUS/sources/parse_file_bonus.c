/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:48:43 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/05 18:29:27 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_res(char *line, t_args *args, int l)
{
	int	i;
	int	side;

	i = 1;
	side = 0;
	while (line[i] && ++side < 3)
	{
		skip_spaces_nl(&line, &i, 0);
		if (line[i] && side == 1)
			args->xres = atoi_count(line, &i);
		else if (line[i] && side == 2)
			args->yres = atoi_count(line, &i);
	}
	if (line[i] || args->xres < 1 || args->yres < 1)
		return (error("Incorrect format/too large value for resolution", \
					l, args->file));
	if (args->xres > 5120)
		args->xres = 5120;
	if (args->yres > 2880)
		args->yres = 2880;
	return (1);
}

int	get_texture(char *line, char **tx)
{
	int	i;
	int	j;

	i = 2 - (*line != 'N' || !(*line == 'S' && *(line + 1) == 'O') || \
				*line != 'W' || *line != 'E');
	line += i;
	skip_spaces_nl(&line, &i, 0);
	if (!nmalloc((void **)tx, ft_strlen(line + i) + 1))
		return (error("Memory allocation failed", -1, 0));
	j = 0;
	while (line[i])
		(*tx)[j++] = line[i++];
	(*tx)[j] = 0;
	return (1);
}

int	get_floor_and_ceiling(char *line, t_args *args, int l)
{
	int	i;
	int	n;
	int	surf;
	int	col[2][4];

	if (*line == 'F')
		surf = 0;
	else
		surf = 1;
	n = 0;
	i = 1;
	line += skip_spaces_nl(&line, &i, 0);
	i = 0;
	while (++i < 4)
	{
		n = atoi_push(&line);
		if (n < 0 || n > 255 || \
			(i == 3 && *line) || \
			(i != 3 && *(line++) != ','))
			return (error("Incorrect format or RGB value", l, args->file));
		else
			col[surf][i] = n;
	}
	args->colors[surf] = get_trgb(0, col[surf][1], col[surf][2], col[surf][3]);
	return (1);
}

int	get_key(char *line, char **keys, int l, char **file)
{
	int			n;
	static char	keyfound[8] = {0};

	if (!line)
		return (error("Missing key", -1, 0));
	n = 0;
	while (n < 7 && ft_strncmp(line, keys[n], 3 - (n > 3)))
		n++;
	if (n == 7)
		return (error("Invalid key specified", l, file));
	if (keyfound[n])
		return (error("Same key found twice", l, file));
	keyfound[n] = 1;
	return (n + 1);
}

int	parse_file(char **file, t_args *args)
{
	int			i;
	int			l;
	int			n;
	static char	*keys[] = {"NO ", "SO ", "EA ", "WE ", "R ", "F ", "C "};

	l = 0;
	n = 0;
	i = 0;
	while (i++ < 7)
	{
		n = get_key(file[l], keys, l + 1, args->file);
		if (!n || \
				(n == 5 && !get_res(file[l], args, l + 1)) || \
				(n < 5 && !get_texture(file[l], &(args->tx[n - 1]))) || \
				(n > 5 && !get_floor_and_ceiling(file[l], args, l + 1)))
			return (0);
		l++;
		skip_spaces_nl(file, &l, 1);
	}
	if (!get_map(args, l))
		return (0);
	if (!parse_map(args->map, args, l + 1) || \
		!no_empty_line(clearmap(args->file), l + 1) || !clearmap(args->file))
		return (0);
	return (1);
}
