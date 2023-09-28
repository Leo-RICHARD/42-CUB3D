/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:33:24 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/27 20:44:12 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map(t_args *args, int l)
{
	int	i;
	int	len;
	int	lenmax;

	len = 0;
	lenmax = 0;
	i = l - 1;
	while (args->file[++i])
	{
		len = ft_strlen(args->file[i]);
		if (len > lenmax)
			lenmax = len;
	}
	i = l - 1;
	while (args->file[++i])
		if (!nealloc_abs((void **)(&args->file[i]), lenmax + 1))
			return ((char **)error("Memory allocation failed", -1, 0));
	args->maph -= (l + 1);
	args->mapw = lenmax;
	args->map = args->file + l;
	args->l = l + 1;
	return (args->map);
}

int	map_closed(char **map, int x, int y, t_args *args)
{
	if ((!map[y] && --args->l) || \
			(x > args->mapw || !map[y][x] || map[y][x] == ' ' || \
			((map[y][x] == '0' || map[y][x] == '2') && (!x || !y))))
		return (error("Map not closed", args->l + y, clearmap(args->file)));
	if (map[y][x] == '0' || map[y][x] == args->c)
	{
		if (map[y][x] == '0')
			map[y][x] = '*';
		if (!map_closed(map, x, y + 1, args) || \
				!map_closed(map, x - 1, y, args) || \
					!map_closed(map, x + 1, y, args) || \
						!map_closed(map, x, y - 1, args))
			return (0);
	}
	return (1);
}

void	get_spawn(char c, int x, int y, t_args *args)
{
	args->spawn[0] = x;
	args->spawn[1] = y;
	if (c == 'N')
		args->spawndir = PI_2;
	else if (c == 'S')
		args->spawndir = 3 * PI_2;
	else if (c == 'W')
		args->spawndir = PI;
	else if (c == 'E')
		args->spawndir = 0;
	args->c = c;
}

int	parse_map(char **map, t_args *args, int l)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			c = map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (args->spawn[0] != -1)
					return (error("Two spawn points detected", -1, 0));
				get_spawn(c, x, y, args);
			}
			else if (c != ' ' && c != '0' && c != '1')
				return (error("Unknown character in map description", l + y, \
							args->file));
		}
	}
	if (args->spawn[0] == -1)
		return (error("Missing spawn point in map description", -1, 0));
	return (map_closed(map, args->spawn[0], args->spawn[1], args));
}

int	no_empty_line(char **file, int l)
{
	while (file[l] && *(file[l]))
		l++;
	if (!file[l])
		return (1);
	while (file[l])
	{
		if (*(file[l]))
			return (error("Empty line(s) in map description", l, file));
		l++;
	}
	return (error("Map description followed by empty line(s)", -1, 0));
}
