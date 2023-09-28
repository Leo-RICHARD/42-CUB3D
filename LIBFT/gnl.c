/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:00:12 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:48:15 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	err(char **line, int *ret, int rv)
{
	free(*line);
	*line = 0;
	*ret = rv;
	return (rv);
}

int	gnl(int fd, char **line, int *ret)
{
	int	llen;

	*ret = 1;
	llen = -1;
	*line = 0;
	while (!(*line) || (*line)[llen])
	{
		llen += *ret;
		if (*ret == -1 || !nealloc((void **)line, 2))
			return (err(line, ret, -1));
		*ret = read(fd, *line + llen, 1);
		*(*line + llen + 1) = 0;
		if (!*ret || (*line)[llen] == '\n')
			(*line)[llen] = 0;
	}
	*ret = (llen || *ret);
	if (!*ret)
		return (err(line, ret, *ret));
	return (1);
}
