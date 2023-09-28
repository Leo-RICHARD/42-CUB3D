/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:53:00 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/30 16:53:36 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	raycaster(char **map, t_raydata *ray, float *origin)
{
	float	dist2;

	while (ray->hx > 0 && ray->hx < ray->xmax && \
			(int)ray->hy >= 0 && (int)ray->hy < ray->ymax && \
			map[(int)ray->hy][(int)(ray->hx - ray->hcorr)] != '1')
	{
		ray->hx += ray->offhx;
		ray->hy -= ray->offhy;
	}
	ray->dist = sqrt(sq(ray->hx - origin[0]) + sq(ray->hy - origin[1]));
	while ((int)ray->vx >= 0 && (int)ray->vx < ray->xmax && \
			ray->vy > 0 && ray->vy < ray->ymax && \
			map[(int)(ray->vy - ray->vcorr)][(int)ray->vx] != '1')
	{
		ray->vx += ray->offvx;
		ray->vy -= ray->offvy;
	}
	dist2 = sqrt(sq(ray->vx - origin[0]) + sq(ray->vy - origin[1]));
	ray->obstacle = 'h' * (ray->dist <= dist2) + 'v' * (dist2 < ray->dist);
	return (ray->dist * (ray->dist <= dist2) + dist2 * (dist2 < ray->dist));
}

void	init_raydata(t_raydata *ray, float *origin)
{
	float	xinc;
	float	yinc;
	float	tangle;

	tangle = absf(tan(ray->angle));
	xinc = -(origin[0] - (int)origin[0]);
	if (ray->angle < PI_2 || ray->angle > 3 * PI_2)
		xinc = 1 + xinc;
	yinc = absf(xinc) * tangle * (1 - 2 * (ray->angle > PI));
	ray->hx = origin[0] + xinc;
	ray->hy = origin[1] - yinc;
	yinc = origin[1] - (int)origin[1];
	if (ray->angle > PI)
		yinc = -(1 - yinc);
	xinc = absf(yinc) / tangle;
	xinc *= 1 - 2 * (ray->angle > PI_2 && ray->angle < 3 * PI_2);
	ray->vx = origin[0] + xinc;
	ray->vy = origin[1] - yinc;
	ray->offhx = 1 - 2 * (ray->angle > PI_2 && ray->angle < 3 * PI_2);
	ray->offhy = tangle * (1 - 2 * (ray->angle > PI));
	ray->offvx = 1 / tangle \
				   * (1 - 2 * (ray->angle > PI_2 && ray->angle < 3 * PI_2));
	ray->offvy = 1 - 2 * (ray->angle > PI);
	ray->hcorr = (ray->angle > PI_2 && ray->angle < 3 * PI_2) * 0.0001;
	ray->vcorr = (ray->angle < PI) * 0.0001;
}
