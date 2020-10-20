/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:40:48 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/20 15:26:15 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_tex_data	*choose_tex(t_cub *data, t_dda *dda)
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

static void			draw_tx_calc(t_cub *data, t_dda *dda, t_draw *draw)
{
	double		w_hit;

	if (dda->side == 0)
		w_hit = data->pos.y + dda->perpwalldist * dda->ray_dir.y;
	else
		w_hit = data->pos.x + dda->perpwalldist * dda->ray_dir.x;
	w_hit -= floor((w_hit));
	draw->tex.x = (int)(w_hit * (double)dda->tex_draw->size.x);
	if (dda->side == 0 && dda->ray_dir.x > 0)
		draw->tex.x = dda->tex_draw->size.x - draw->tex.x - 1;
	if (dda->side == 1 && dda->ray_dir.y < 0)
		draw->tex.x = dda->tex_draw->size.x - draw->tex.x - 1;
	draw->step = 1.0 * dda->tex_draw->size.y / dda->lineheight;
	draw->tex_pos =
	(dda->drawstart - data->r_y / 2 + dda->lineheight / 2) * draw->step;
}

int					draw_tex(t_cub *data, t_dda *dda)
{
	int			i;
	t_draw		draw;

	dda->tex_draw = choose_tex(data, dda);
	draw_tx_calc(data, dda, &draw);
	i = 0;
	while (i < dda->drawstart)
		data->img_i[i++ * data->r_x + dda->x] = data->ceiling;
	while (i < dda->drawend)
	{
		draw.tex.y = (int)draw.tex_pos & (dda->tex_draw->size.y - 1);
		draw.tex_pos += draw.step;
		data->img_i[i++ * data->r_x + dda->x] =
			dda->tex_draw->tex_i
			[dda->tex_draw->size.y * draw.tex.y + draw.tex.x];
	}
	while (i < data->r_y)
		data->img_i[i++ * data->r_x + dda->x] = data->floor;
	return (0);
}
