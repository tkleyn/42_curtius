/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:07:10 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/21 11:22:04 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define R 1
# define NO 2
# define SO 4
# define WE 8
# define EA 16
# define F 32
# define C 64
# define S 128

# define SPEED 0.05

# include "../libft/libft.h"
# include "keycode.h"
# include "x_events.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct
{
	double	x;
	double	y;
}			t_vector;

typedef struct
{
	int	x;
	int	y;
}		t_ivector;

typedef struct
{
	t_ivector	tex;
	double		step;
	double		tex_pos;
}	t_draw;

typedef struct
{
	t_ivector	size;
	void		*tex;
	char		*tex_c;
	int			*tex_i;
}	t_tex_data;

typedef struct
{
	t_vector	sde_dst;
	t_vector	ray_dir;
	t_vector	delta_dist;
	t_ivector	m_pos;
	t_ivector	step;
	double		perpwalldist;
	int			side;
	int			drawstart;
	int			drawend;
	int			x;
	int			lineheight;
	t_tex_data	*tex_draw;

}	t_dda;

typedef struct
{
	t_vector	sprite;
	t_vector	transform;
	t_ivector	drawstart;
	t_ivector	drawend;
	t_ivector	spritedata;
	int			spritescreenx;
	t_ivector	tex;
	uint32_t	color;
	int			stripe;
}	t_sp_data;

typedef struct
{
	t_vector	pos;
	double		dist;
}	t_sp_pos;

typedef struct
{
	t_tex_data	t[5];
	int			r_x;
	int			r_y;
	int			floor;
	int			ceiling;
	char		**map;
	int			n_row;

	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	int			move_ud;
	int			move_lr;
	int			rotate;

	void		*mlx;
	void		*window;
	void		*img;
	char		*img_c;
	int			*img_i;

	int			n_srites;
	t_sp_pos	*s_pos;

	uint8_t		apply_tex;
	uint8_t		refresh;
}	t_cub;

int				load_cub(char *file, t_cub *data);

int				ck_arg(char *str, t_cub *data, unsigned char *ck);

int				f_err(char *msg, int ret, char **tab);
void			tab_free(char **tab);
int				clean_exit(t_cub *data);
void			error_exit(t_cub *data, char *msg);

int				get_map(int fd, t_cub *data);

int				dda(t_cub *data);
void			setpos(t_cub *data, double x, double y);
void			setdir(t_cub *data, double x, double y);
void			setplane(t_cub *data, double x, double y);

int				move_fw(t_cub *data);
int				move_lr(t_cub *data);
int				move_rot(t_cub *data);
int				cub_loop(t_cub *data);

void			bmp2img(t_cub *data);

int				cub_init(t_cub *data);
int				tex_load(t_cub *data);

int				draw_image(t_cub *data, t_dda *dda);
int				draw_tex(t_cub *data, t_dda *dda);

void			sprite_cast(t_cub *data, double *zbuf);

#endif
