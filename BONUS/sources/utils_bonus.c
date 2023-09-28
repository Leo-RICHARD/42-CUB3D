/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:51:05 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/27 20:44:13 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	skip_spaces_nl(char **line, int *i, char skipnl)
{
	if (skipnl)
		while (line[*i] && !*(line[*i]))
			(*i)++;
	else
		while ((*line)[*i] == 32)
			(*i)++;
	return (*i);
}

int	atoi_push(char **line)
{
	int	n;
	int	worked;

	n = 0;
	worked = -1;
	while (**line > 47 && **line < 58)
	{
		n = n * 10 + **line - 48;
		(*line)++;
		++worked;
	}
	if (worked == -1)
		return (-2);
	return (n);
}

int	atoi_count(char *line, int *i)
{
	int	n;
	int	worked;

	n = 0;
	worked = -1;
	while (line[*i] > 47 && line[*i] < 58)
	{
		n = n * 10 + line[(*i)++] - 48;
		if ((n == 214748364 && (line[*i] == '8' || line[*i] == '9')) || \
			((n > 214748364 || n >= 1000000000) && ft_isdigit(line[*i])))
			return (-1);
		++worked;
	}
	if (worked == -1)
		return (-1);
	return (n);
}

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char	**clearmap(char **file)
{
	int	i;
	int	ii;

	i = -1;
	while (file[++i])
	{
		ii = -1;
		while (file[i][++ii])
			if (file[i][ii] == '*')
				file[i][ii] = '0';
	}
	return (file);
}
