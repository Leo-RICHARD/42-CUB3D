/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:26:38 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/05 18:29:29 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_res(t_args *args)
{
	args->xres = XRES;
	args->yres = YRES;
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
	static char	keyfound[6] = {0};

	if (!line)
		return (error("Missing key", -1, 0));
	n = 0;
	while (n < 6 && ft_strncmp(line, keys[n], 3 - (n > 3)))
		n++;
	if (n == 6)
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
	static char	*keys[] = {"NO ", "SO ", "EA ", "WE ", "F ", "C "};

	l = 0;
	n = 0;
	i = 0;
	while (i++ < 6)
	{
		n = get_key(file[l], keys, l + 1, args->file);
		if (!n || \
				(n < 5 && !get_texture(file[l], &(args->tx[n - 1]))) || \
				(n > 4 && !get_floor_and_ceiling(file[l], args, l + 1)))
			return (0);
		l++;
		skip_spaces_nl(file, &l, 1);
	}
	get_res(args);
	if (!get_map(args, l))
		return (0);
	if (!parse_map(args->map, args, l + 1) || \
		!no_empty_line(clearmap(args->file), l + 1) || !clearmap(args->file))
		return (0);
	return (1);
}
