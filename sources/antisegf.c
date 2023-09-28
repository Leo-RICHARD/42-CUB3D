/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antisegf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:39:10 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/29 21:42:08 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	segfaults_forward(t_args *args, t_controls *inputs, float *pos)
{
	pos[2] = pos[0] + inputs->cosa * 0.07;
	pos[3] = pos[1] - inputs->sina * 0.07;
	if (pos[2] < 0 || (int)pos[2] >= args->mapw || \
			pos[3] < 0 || (int)pos[3] >= args->maph || \
				!args->map[(int)pos[3]][(int)pos[2]])
		return (1);
	return (0);
}

int	segfaults_backward(t_args *args, t_controls *inputs, float *pos)
{
	pos[2] = pos[0] - inputs->cosa * 0.07;
	pos[3] = pos[1] + inputs->sina * 0.07;
	if (pos[2] < 0 || (int)pos[2] >= args->mapw || \
			pos[3] < 0 || (int)pos[3] >= args->maph || \
				!args->map[(int)pos[3]][(int)pos[2]])
		return (1);
	return (0);
}

int	segfaults_left(t_args *args, t_controls *inputs, float *pos)
{
	pos[2] = pos[0] - inputs->sina * 0.04;
	pos[3] = pos[1] - inputs->cosa * 0.04;
	if (pos[2] < 0 || (int)pos[2] >= args->mapw || \
			pos[3] < 0 || (int)pos[3] >= args->maph || \
				!args->map[(int)pos[3]][(int)pos[2]])
		return (1);
	return (0);
}

int	segfaults_right(t_args *args, t_controls *inputs, float *pos)
{
	pos[2] = pos[0] + inputs->sina * 0.04;
	pos[3] = pos[1] + inputs->cosa * 0.04;
	if (pos[2] < 0 || (int)pos[2] >= args->mapw || \
			pos[3] < 0 || (int)pos[3] >= args->maph || \
				!args->map[(int)pos[3]][(int)pos[2]])
		return (1);
	return (0);
}
