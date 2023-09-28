/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:46:49 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/30 16:56:04 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	addcrosshair(t_img *frame, int xres, int yres)
{
	int	i;

	frame->cx = (xres - 1) * 0.5 - 8;
	frame->cy = (yres - 1) * 0.5;
	i = 0;
	while (i++ < 15 && frame->cx++ && frame->cy > -1 && frame->cy < yres && \
						frame->cx > -1 && frame->cx < xres)
		frame->addr[frame->cy * xres + frame->cx] = 0;
	frame->cy -= 8;
	frame->cx = (xres - 1) * 0.5;
	i = 0;
	while (i++ < 15 && frame->cy++ && frame->cy > -1 && frame->cy < yres && \
						frame->cx > -1 && frame->cx < xres)
		frame->addr[frame->cy * xres + frame->cx] = 0;
}
