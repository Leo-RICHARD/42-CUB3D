/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:48:23 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/05 18:26:49 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_file_len(char *path)
{
	int		nl;
	int		fd;
	int		ret;
	char	*line;

	nl = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		error("Failed to open configuration file", -1, 0);
		exit(0);
	}
	while (gnl(fd, &line, &ret) == 1 && ++nl)
		free(line);
	free(line);
	if (ret == -1)
	{
		error("Failed to read configuration file", -1, 0);
		exit(0);
	}
	close(fd);
	return (nl);
}

char	**get_file(t_args *args, char *path)
{
	int		fd;
	int		len;
	int		ret;
	char	**file;

	len = get_file_len(path);
	if (!len)
	{
		error("Configuration file empty", -1, 0);
		exit(0);
	}
	if (!nmallloc((void ***)&file, len + 1))
		return ((char **)error("Memory allocation failed", -1, 0));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ((char **)error("Failed to open configuration file", -1, 0));
	len = -1;
	while (gnl(fd, file + ++len, &ret) == 1)
		;
	if (ret == -1)
		return ((char **)error("Failed to read configuration file", -1, 0));
	close(fd);
	args->file = file;
	args->maph = len;
	return (file);
}
