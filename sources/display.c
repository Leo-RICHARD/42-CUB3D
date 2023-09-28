/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:42:40 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/17 22:44:09 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	aff_sky(t_img *frame, t_args *args, int walltop)
{
	frame->cy = -1;
	while (++frame->cy < walltop)
	{
		if (frame->cy < args->yres && frame->cx < args->xres)
			frame->addr[frame->cy * args->xres + \
				frame->cx] = args->colors[1];
	}
}

int	get_side(t_args *args, t_raydata *ray, int side)
{
	if (ray->obstacle == 'h' && (ray->angle > PI_2 && ray->angle < 3 * PI_2))
	{
		side = 2;
		args->txs[2].cx = (1 - \
				(float)(ray->hy - (int)(ray->hy))) * (args->txs[2].w - 1);
	}
	else if (ray->obstacle == 'h' && \
			!(ray->angle > PI_2 && ray->angle < 3 * PI_2))
	{
		side = 3;
		args->txs[3].cx = (float)(ray->hy - \
										(int)(ray->hy)) *(args->txs[3].w - 1);
	}
	else if (ray->obstacle == 'v' && (ray->angle > PI))
	{
		side = 1;
		args->txs[1].cx = (1 - \
				(float)(ray->vx - (int)(ray->vx))) * (args->txs[1].w - 1);
	}
	else
		args->txs[0].cx = (float)(ray->vx - \
										(int)(ray->vx)) *(args->txs[0].w - 1);
	return (side);
}

void	aff_wall(t_img *frame, t_args *args, t_raydata *ray, int wallheight)
{
	int		color;
	float	step;
	float	txy;
	t_img	*tx;

	tx = &(args->txs[get_side(args, ray, 0)]);
	txy = 0;
	step = (float)tx->h / wallheight;
	frame->cy = (ray->tangle - wallheight * 0.5) - 1;
	if (frame->cy < 0)
		frame->cy = 0 + 0 * (txy = txy + -frame->cy * step) \
						+ 0 * (wallheight += frame->cy) - 1;
	while (wallheight-- && ++frame->cy < args->yres)
	{
		if ((int)txy < tx->h - 1 && (int)tx->cx < tx->w)
			color = *(int *)(tx->addr + (int)txy * tx->w + (int)tx->cx);
		if (frame->cx < args->xres)
			*(frame->addr + frame->cy * args->xres + frame->cx) = color;
		txy += step;
	}
}

void	aff_floor(t_img *frame, int color, int xres, int yres)
{
	while (frame->cy < yres && frame->cx < xres)
	{
		frame->addr[frame->cy * xres + \
			frame->cx] = color;
		frame->cy++;
	}
}

void	renderfram(t_img *frame, t_raydata *ray, t_player *player, t_args *args)
{
	int		walltop;
	float	walldist;
	int		wallheight;

	ray->angle = player->dir - (player->fova * 0.5);
	frame->cx = args->xres;
	while (frame->cx--)
	{
		ray->angle += 2 * PI * (ray->angle < 0);
		ray->angle -= 2 * PI * (ray->angle >= 2 * PI);
		if (ray->angle && ray->angle != PI && \
			ray->angle != PI_2 && ray->angle != 3 * PI_2)
		{
			init_raydata(ray, player->pos);
			walldist = raycaster(args->map, ray, player->pos) \
					  * cos(absf(ray->angle - player->dir));
			wallheight = args->wallhdef / (walldist + (0.5 * (!walldist)));
			walltop = player->horizon - wallheight * 0.5;
		}
		aff_sky(frame, args, walltop);
		ray->tangle = player->horizon;
		aff_wall(frame, args, ray, wallheight);
		aff_floor(frame, args->colors[0], args->xres, args->yres);
		ray->angle += ray->step;
	}
}
