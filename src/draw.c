/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:40:48 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/05 14:27:18 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_tex_data		*choose_tex(t_cub *data, t_dda *dda)
{
	t_tex_data	*tex_draw;

	if (dda->side && dda->ray_dir.y < 0)
		tex_draw = &data->t[0];
	else if (dda->side && dda->ray_dir.y >= 0)
		tex_draw = &data->t[1];
	else if (dda->ray_dir.x < 0)
		tex_draw = &data->t[2];
	else
		tex_draw = &data->t[3];
	return (tex_draw);
}

int					draw_image(t_cub *data, t_dda *dda)
{
	int i;
	int color;

	i = 0;
	while (i < dda->drawstart)
		data->img_i[i++ * data->r_x + dda->x] = data->ceiling;
	if (dda->side && dda->ray_dir.y < 0)
		color = 0x0000FF;
	else if (dda->side && dda->ray_dir.y >= 0)
		color = 0xFF0000;
	else if (dda->ray_dir.x >= 0)
		color = 0x00FF00;
	else if (dda->ray_dir.x < 0)
		color = 0xFF6600;
	while (i < dda->drawend)
		data->img_i[i++ * data->r_x + dda->x] = color;
	while (i < data->r_y)
		data->img_i[i++ * data->r_x + dda->x] = data->floor;
	return (0);
}

int					draw_tex(t_cub *data, t_dda *dda)
{
	double		w_hit;
	t_tex_data	*tex_draw;
	int			i;
	t_ivector	tex;
	double		step;
	double		tex_pos;

	tex_draw = choose_tex(data, dda);
	if (dda->side == 0)
		w_hit = data->pos.y + dda->perpwalldist * dda->ray_dir.y;
	else
		w_hit = data->pos.x + dda->perpwalldist * dda->ray_dir.x;
	w_hit -= floor((w_hit));
	tex.x = (int)(w_hit * (double)tex_draw->size.x);
	if (dda->side == 0 && dda->ray_dir.x > 0)
		tex.x = tex_draw->size.x - tex.x - 1;
	if (dda->side == 1 && dda->ray_dir.y < 0)
		tex.x = tex_draw->size.x - tex.x - 1;
	step = 1.0 * tex_draw->size.y / dda->lineheight;
	tex_pos = (dda->drawstart - data->r_y / 2 + dda->lineheight / 2) * step;
	i = 0;
	while (i < dda->drawstart)
		data->img_i[i++ * data->r_x + dda->x] = data->ceiling;
	while (i < dda->drawend)
	{
		tex.y = (int)tex_pos & (tex_draw->size.y - 1);
		tex_pos += step;
		data->img_i[i++ * data->r_x + dda->x] = tex_draw->tex_i[tex_draw->size.y * tex.y + tex.x];
	}
	while (i < data->r_y)
		data->img_i[i++ * data->r_x + dda->x] = data->floor;
	return (0);
}
