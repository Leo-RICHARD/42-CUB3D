/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstuff_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:50 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/05 18:26:53 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	leave(t_hooker *h)
{
	int	i;

	i = -1;
	while (++i < 4 && h->args->txs[0].img)
		mlx_destroy_image(h->mlx->mlx, h->args->txs[i].img);
	mlx_destroy_image(h->mlx->mlx, h->mlx->frame->img);
	mlx_destroy_window(h->mlx->mlx, h->mlx->window);
	free_args_struct(h->args);
	exit(1);
	return (0);
}

int	mlx_get_textures(t_args *args, void *mlx)
{
	int	i;

	args->txs[0].img = mlx_xpm_file_to_image(mlx, args->tx[0], \
			&args->txs[0].w, &args->txs[0].h);
	if (!args->txs[0].img)
		return (error("Failed to load norh texture", -1, 0));
	args->txs[1].img = mlx_xpm_file_to_image(mlx, args->tx[1], \
			&args->txs[1].w, &args->txs[1].h);
	if (!args->txs[1].img)
		return (error("Failed to load souh texture", -1, 0));
	args->txs[2].img = mlx_xpm_file_to_image(mlx, args->tx[2], \
			&args->txs[2].w, &args->txs[2].h);
	if (!args->txs[2].img)
		return (error("Failed to load east texture", -1, 0));
	args->txs[3].img = mlx_xpm_file_to_image(mlx, args->tx[3], \
			&args->txs[3].w, &args->txs[3].h);
	if (!args->txs[3].img)
		return (error("Failed to load west texture", -1, 0));
	i = -1;
	while (i++ < 3)
		args->txs[i].addr = (int *)mlx_get_data_addr(args->txs[i].img, \
			&args->txs[i].bppx, &args->txs[i].linelen, &args->txs[i].endian);
	return (1);
}

int	refresh(t_hooker *h)
{
	if (h->inputs->terminate)
		leave(h);
	move_player(h->player, h->inputs, h->args);
	renderfram(h->mlx->frame, h->ray, h->player, h->args);
	addcrosshair(h->mlx->frame, h->args->xres, h->args->yres);
	mlx_put_image_to_window(h->mlx->mlx, h->mlx->window, \
			h->mlx->frame->img, 0, 0);
	return (1);
}

void	init_things(t_args *args, t_player *player, t_raydata *ray, t_hooker *h)
{
	player->pos[0] += 0.5;
	player->pos[1] += 0.5;
	ray->xmax = args->mapw;
	ray->ymax = args->maph;
	ray->step = player->fova / args->xres;
	args->wallhdef = args->yres / (2 * tan(player->fova * 0.5));
	h->args = args;
	h->player = player;
	h->ray = ray;
	h->inputs->mvforward = 0;
	h->inputs->mvbackward = 0;
	h->inputs->mvleft = 0;
	h->inputs->mvright = 0;
	h->inputs->lkup = 0;
	h->inputs->lkdown = 0;
	h->inputs->lkleft = 0;
	h->inputs->lkright = 0;
	h->inputs->terminate = 0;
}

int	mlx_dostuff(t_args *args, t_player *player)
{
	t_mlx		mlx;
	t_img		frame;
	t_raydata	ray;
	t_controls	inputs;
	t_hooker	h;

	mlx.mlx = mlx_init();
	frame.img = mlx_new_image(mlx.mlx, args->xres, args->yres);
	frame.addr = (int *)mlx_get_data_addr(frame.img, &frame.bppx, \
			&frame.linelen, &frame.endian);
	mlx.window = mlx_new_window(mlx.mlx, args->xres, args->yres, "cub3d");
	mlx.frame = &frame;
	h.mlx = &mlx;
	h.inputs = &inputs;
	init_things(args, player, &ray, &h);
	if (!mlx_get_textures(args, mlx.mlx))
		leave(&h);
	mlx_hook(mlx.window, 2, 1L << 0, controls_press, &inputs);
	mlx_hook(mlx.window, 3, 1L << 1, controls_release, &inputs);
	mlx_hook(mlx.window, 17, 1L << 17, leave, &h);
	mlx_loop_hook(mlx.mlx, refresh, &h);
	renderfram(&frame, &ray, player, args);
	mlx_put_image_to_window(mlx.mlx, mlx.window, frame.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (1);
}
