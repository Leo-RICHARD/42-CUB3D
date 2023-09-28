/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:25:17 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/30 16:55:44 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	controls_press(int keycode, t_controls *inputs)
{
	if (keycode == 13)
		inputs->mvforward = 1;
	else if (keycode == 0)
		inputs->mvleft = 1;
	else if (keycode == 1)
		inputs->mvbackward = 1;
	else if (keycode == 2)
		inputs->mvright = 1;
	else if (keycode == 124)
		inputs->lkleft = 1;
	else if (keycode == 123)
		inputs->lkright = 1;
	else if (keycode == 126)
		inputs->lkup = 1;
	else if (keycode == 125)
		inputs->lkdown = 1;
	else if (keycode == 53)
		inputs->terminate = 1;
	return (1);
}

int	controls_release(int keycode, t_controls *inputs)
{
	if (keycode == 13)
		inputs->mvforward = 0;
	else if (keycode == 0)
		inputs->mvleft = 0;
	else if (keycode == 1)
		inputs->mvbackward = 0;
	else if (keycode == 2)
		inputs->mvright = 0;
	else if (keycode == 124)
		inputs->lkleft = 0;
	else if (keycode == 123)
		inputs->lkright = 0;
	else if (keycode == 126)
		inputs->lkup = 0;
	else if (keycode == 125)
		inputs->lkdown = 0;
	return (1);
}

int	change_position(t_player *player, t_controls *inputs, t_args *args)
{
	if (inputs->mvforward && \
			!collides_forward(args, inputs, player->pos))
	{
		player->pos[0] = player->pos[2];
		player->pos[1] = player->pos[3];
	}
	if (inputs->mvleft && \
			!collides_left(args, inputs, player->pos))
	{
		player->pos[0] = player->pos[2];
		player->pos[1] = player->pos[3];
	}
	if (inputs->mvbackward && \
			!collides_backward(args, inputs, player->pos))
	{
		player->pos[0] = player->pos[2];
		player->pos[1] = player->pos[3];
	}
	if (inputs->mvright && \
			!collides_right(args, inputs, player->pos))
	{
		player->pos[0] = player->pos[2];
		player->pos[1] = player->pos[3];
	}
	return (1);
}

int	move_player(t_player *player, t_controls *inputs, t_args *args)
{
	inputs->cosa = cos(player->dir);
	inputs->sina = sin(player->dir);
	if (player->dir == 0.785398135 || player->dir == 2.356194 || \
		player->dir == 3.926991 || player->dir == 5.497787)
		player->dir += 0.1;
	change_position(player, inputs, args);
	if (player->pos[0] == (int)player->pos[0])
		player->pos[0] += 0.01;
	if (player->pos[1] == (int)player->pos[1])
		player->pos[1] += 0.01;
	if (inputs->lkleft)
		player->dir -= 0.04;
	if (inputs->lkright)
		player->dir += 0.04;
	if (inputs->lkdown && player->horizon > 0)
		player->horizon -= 16;
	if (inputs->lkup && player->horizon < args->yres)
		player->horizon += 16;
	if (player->dir < 0)
		player->dir += 2 * PI;
	else if (player->dir >= 2 * PI)
		player->dir -= 2 * PI;
	return (1);
}
