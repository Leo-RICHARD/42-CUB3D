/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:47:39 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/05 18:38:28 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned long int	error(char *str, int line, char **file)
{
	int	i;
	int	offset;

	printf("Error\n%s", str);
	if (line > 0)
	{
		printf(" : config file, l-%d\n\n", line);
		i = 4;
		offset = 0;
		while (!offset && --i)
			offset = i * (line > i);
		i = line - 1 - offset;
		if (i > 4)
			write(1, "...\n", 4);
		while (file[i] && i < line + 3)
		{
			if (i++ + 1 != line)
				printf("%*d |    %s\n", intlen(line + 3), i, file[i - 1]);
			else
				printf("%*d | -> %s\n", intlen(line + 3), i, file[i - 1]);
		}
		if (i < tablen(file))
			write(1, "...\n", 4);
	}
	return (0);
}

int	init_args_struct(t_args *args)
{
	int	i;

	args->file = 0;
	if (!nmallloc((void ***)&args->tx, 7))
		return (error("Memory allocation failed", -1, 0));
	i = -1;
	while (++i < 7)
		args->tx[i] = 0;
	args->spawn[0] = -1;
	args->xres = -1;
	args->yres = -1;
	args->file = 0;
	return (1);
}

t_player	*init_player(t_args *args, t_player *player)
{
	player->pos[0] = args->spawn[0];
	player->pos[1] = args->spawn[1];
	player->dir = args->spawndir;
	player->horizon = (int)((args->yres - 1) * 0.5);
	player->fova = PI / 3;
	return (player);
}

int	free_args_struct(t_args *args)
{
	int	n;

	n = 0;
	while (n < 7)
		free(args->tx[n++]);
	free(args->tx);
	n = 0;
	if (args->file)
		while (args->file[n])
			free(args->file[n++]);
	free(args->file);
	return (0);
}

int	main(int ac, char **av)
{
	t_args		args;
	t_player	player;

	if (ac > 3)
		return (error("Too many arguments", -1, 0));
	if (ac == 3 && ft_strcmp(av[2], "--save"))
		return (error("Second argument supplied was not --save", -1, 0));
	if (ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), ".cub"))
		return (error("Configuration file must be of extension .cub", -1, 0));
	if (!init_args_struct(&args))
		return (0);
	if (!get_file(&args, av[1]) || !parse_file(args.file, &args))
		return (free_args_struct(&args));
	mlx_dostuff(&args, init_player(&args, &player));
	return (0);
}
