/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:40:29 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/05 13:57:02 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dda_init2(t_cub *data, t_dda *dda)
{
	if (dda->ray_dir.x < 0)
	{
		dda->step.x = -1;
		dda->sde_dst.x = (data->pos.x - dda->m_pos.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->sde_dst.x = (dda->m_pos.x + 1.0 - data->pos.x) * dda->delta_dist.x;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->step.y = -1;
		dda->sde_dst.y = (data->pos.y - dda->m_pos.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->sde_dst.y = (dda->m_pos.y + 1.0 - data->pos.y) * dda->delta_dist.y;
	}
	return (1);
}

int	dda_init(t_cub *data, t_dda *dda)
{
	double camerax;

	camerax = 2 * dda->x / (double)data->r_x - 1;
	dda->ray_dir.x = data->dir.x + data->plane.x * camerax;
	dda->ray_dir.y = data->dir.y + data->plane.y * camerax;
	dda->m_pos.x = (int)data->pos.x;
	dda->m_pos.y = (int)data->pos.y;
	dda->delta_dist.x = fabs(1 / dda->ray_dir.x);
	dda->delta_dist.y = fabs(1 / dda->ray_dir.y);
	return (dda_init2(data, dda));
}

int	dda_algo(t_cub *data, t_dda *dda)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->sde_dst.x < dda->sde_dst.y)
		{
			dda->sde_dst.x += dda->delta_dist.x;
			dda->m_pos.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->sde_dst.y += dda->delta_dist.y;
			dda->m_pos.y += dda->step.y;
			dda->side = 1;
		}
		if (data->map[dda->m_pos.y][dda->m_pos.x] > '0')
			hit = 1;
	}
	return (1);
}

int	dda(t_cub *data)
{
	t_dda dda;

	dda.x = 0;
	while (dda.x < data->r_x)
	{
		dda_init(data, &dda);
		dda_algo(data, &dda);
		if (dda.side == 0)
			dda.perpwalldist = (dda.m_pos.x - data->pos.x + (1 - dda.step.x) / 2) / dda.ray_dir.x;
		else
			dda.perpwalldist = (dda.m_pos.y - data->pos.y + (1 - dda.step.y) / 2) / dda.ray_dir.y;
		dda.lineheight = (int)(data->r_y / dda.perpwalldist);
		dda.drawstart = -dda.lineheight / 2 + data->r_y / 2;
		if (dda.drawstart < 0)
			dda.drawstart = 0;
		dda.drawend = dda.lineheight / 2 + data->r_y / 2;
		if (dda.drawend > data->r_y)
			dda.drawend = data->r_y;
		if (data->apply_tex)
			draw_tex(data, &dda);
		else
			draw_image(data, &dda);
		dda.x++;
	}
	return (0);
}
