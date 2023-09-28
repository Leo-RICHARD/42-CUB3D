/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:51:24 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/04 20:01:53 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <time.h>

# define PI 3.14159265358979323846
# define PI_2 1.57079632679489661923

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bppx;
	int			linelen;
	int			endian;
	int			cx;
	int			cy;
	int			w;
	int			h;
}				t_img;

typedef struct s_args
{
	int			xres;
	int			yres;
	int			colors[2];
	char		**map;
	int			mapw;
	int			maph;
	int			wallhdef;
	float		spawndir;
	int			spawn[2];
	char		**tx;
	t_img		txs[4];
	char		**file;
	int			l;
	char		c;
}				t_args;

typedef struct s_player
{
	float		pos[4];
	float		dir;
	float		angle;
	float		fova;
	int			horizon;
}				t_player;

typedef struct s_controls
{
	int		mvforward;
	int		mvleft;
	int		mvright;
	int		mvbackward;
	int		lkup;
	int		lkdown;
	int		lkleft;
	int		lkright;
	int		terminate;
	float	cosa;
	float	sina;
}				t_controls;

typedef struct s_raydata
{
	float		hx;
	float		hy;
	float		vx;
	float		vy;
	float		tangle;
	float		offhx;
	float		offhy;
	float		offvx;
	float		offvy;
	float		fovh;
	float		angle;
	char		obstacle;
	float		dist;
	float		step;
	float		hcorr;
	float		vcorr;
	int			xmax;
	int			ymax;
}				t_raydata;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_img		*frame;
}				t_mlx;

typedef struct s_hooker
{
	t_mlx		*mlx;
	t_args		*args;
	t_player	*player;
	t_raydata	*ray;
	t_controls	*inputs;
	int			xlook;
	int			ylook;
}				t_hooker;

int					get_file_len(char *path);
char				**get_file(t_args *args, char *path);
int					parse_file(char **file, t_args *args);
int					get_trgb(int t, int r, int g, int b);
char				**get_map(t_args *args, int l);
int					parse_map(char **map, t_args *args, int l);
char				**clearmap(char **file);
int					no_empty_line(char **file, int l);
int					skip_spaces_nl(char **line, int *i, char skipnl);
int					atoi_push(char **line);
int					atoi_count(char *line, int *i);
unsigned long int	error(char *str, int line, char **file);
int					mlx_dostuff(t_args *args, t_player *player);
int					mlx_get_textures(t_args *args, void *mlx);
void				renderfram(t_img *frame, t_raydata *ray, \
											t_player *player, t_args *args);
void				init_raydata(t_raydata *ray, float *origin);
float				raycaster(char **map, t_raydata *ray, float *origin);
int					controls_press(int keycode, t_controls *inputs);
int					controls_release(int keycode, t_controls *inputs);
int					move_player(t_player *player, \
											t_controls *inputs, t_args *args);
int					collides_right(t_args *args, t_controls *inputs, \
																float *pos);
int					collides_left(t_args *args, t_controls *inputs, \
																float *pos);
int					collides_backward(t_args *args, t_controls *inputs, \
																float *pos);
int					collides_forward(t_args *args, t_controls *inputs, \
																float *pos);
void				addcrosshair(t_img *frame, int xres, int yres);
int					free_args_struct(t_args *args);

#endif
