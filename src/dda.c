/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:40:29 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/29 15:47:06 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	dda_init2(t_cub *data, t_dda *dda)
{	if (dda->ray_dir.x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = (data->pos.x - dda->m_pos.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->m_pos.x + 1.0 - data->pos.x) * dda->delta_dist.x;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->step.y = -1;
		dda->side_dist.y = (data->pos.y - dda->m_pos.y) * dda->delta_dist.y;
	} 
	else
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->m_pos.y + 1.0 - data->pos.y) * dda->delta_dist.y;
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
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			dda->m_pos.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			dda->m_pos.y += dda->step.y;
			dda->side = 1;
		}	
		if (data->map[dda->m_pos.y][dda->m_pos.x] > '0')
			hit = 1;
	}
	return (1);
}

int	draw_image(t_cub *data, t_dda *dda)
{
	int i;
	int color;
	i =  0;
	while (i < dda->drawstart)
		data->img_i[i++ * data->r_x + dda->x] = data->ceiling;
	if(dda->side && dda->ray_dir.y < 0)
		color = 0x0000FF;
	else if(dda->side && dda->ray_dir.y >= 0)
		color = 0xFF0000;
	else if(dda->ray_dir.x >= 0)
		color = 0x00FF00;
	else if(dda->ray_dir.x < 0)
		color = 0xFF6600;
	while (i < dda->drawend)			
		data->img_i[i++ * data->r_x + dda->x] = color;
	while (i < data->r_y)
		data->img_i[i++ * data->r_x + dda->x] = data->floor;
	return (1);
}

int dda(t_cub *data)
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

		int lineHeight;
		lineHeight = (int)(data->r_y / dda.perpwalldist);
		dda.drawstart = -lineHeight / 2 + data->r_y / 2;
		if (dda.drawstart < 0)
			dda.drawstart = 0;
		dda.drawend = lineHeight / 2 + data->r_y / 2;
		if (dda.drawend > data->r_y)
			dda.drawend = data->r_y;
			
		draw_image(data, &dda);
		dda.x++;
	}
	return 0;
}