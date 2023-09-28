/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:47:18 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/27 19:21:04 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	collides_forward(t_args *args, t_controls *inputs, float *pos)
{
	float	inc;

	inc = 0.0001;
	while (inc < 0.0701)
	{
		pos[2] = pos[0] + inputs->cosa * inc;
		pos[3] = pos[1] - inputs->sina * inc;
		if ((int)pos[2] < 0 || (int)pos[2] >= args->mapw || \
			(int)pos[3] < 0 || (int)pos[3] >= args->maph || \
				args->map[(int)pos[3]][(int)pos[2]] == '1')
			return (1);
		inc += 0.0001;
	}
	return (0);
}

int	collides_backward(t_args *args, t_controls *inputs, float *pos)
{
	float	inc;

	inc = 0.0001;
	while (inc < 0.0701)
	{
		pos[2] = pos[0] - inputs->cosa * inc;
		pos[3] = pos[1] + inputs->sina * inc;
		if ((int)pos[2] < 0 || (int)pos[2] >= args->mapw || \
			(int)pos[3] < 0 || (int)pos[3] >= args->maph || \
				args->map[(int)pos[3]][(int)pos[2]] == '1')
			return (1);
		inc += 0.0001;
	}
	return (0);
}

int	collides_left(t_args *args, t_controls *inputs, float *pos)
{
	float	inc;

	inc = 0.0001;
	while (inc < 0.0401)
	{
		pos[2] = pos[0] - inputs->sina * inc;
		pos[3] = pos[1] - inputs->cosa * inc;
		if ((int)pos[2] < 0 || (int)pos[2] >= args->mapw || \
			(int)pos[3] < 0 || (int)pos[3] >= args->maph || \
				args->map[(int)pos[3]][(int)pos[2]] == '1')
			return (1);
		inc += 0.0001;
	}
	return (0);
}

int	collides_right(t_args *args, t_controls *inputs, float *pos)
{
	float	inc;

	inc = 0.0001;
	while (inc < 0.0401)
	{
		pos[2] = pos[0] + inputs->sina * inc;
		pos[3] = pos[1] + inputs->cosa * inc;
		if ((int)pos[2] < 0 || (int)pos[2] >= args->mapw || \
			(int)pos[3] < 0 || (int)pos[3] >= args->maph || \
				args->map[(int)pos[3]][(int)pos[2]] == '1')
			return (1);
		inc += 0.0001;
	}
	return (0);
}
