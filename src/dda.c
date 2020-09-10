/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:40:29 by tkleynts          #+#    #+#             */
/*   Updated: 2020/09/10 14:45:16 by tkleynts         ###   ########.fr       */
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
/*
int draw_tex(t_cub *data, t_dda *dda)
{	
	double w_hit; //where exactly the wall was hit
	tex_data	*tex_draw;

	if(dda->side && dda->ray_dir.y < 0)
		tex_draw = &data->t[0];
	else if(dda->side && dda->ray_dir.y >= 0)
		tex_draw = &data->t[1];
	else if(dda->ray_dir.x < 0)
		tex_draw = &data->t[2];
	else if(dda->ray_dir.x >= 0)
		tex_draw = &data->t[3];

      //calculate value of w_hit
	if (dda->side == 0)
		w_hit = data->pos.y + dda->perpwalldist * dda->ray_dir.y;
    else
		w_hit = data->pos.x + dda->perpwalldist * dda->ray_dir.x;
	w_hit -= floor((w_hit));

	//x coordinate on the texture
	int texX = (int)(w_hit * (double)tex_draw->size.x);
	if(dda->side == 0 && dda->ray_dir.x > 0) texX = tex_draw->size.x - texX - 1;
	if(dda->side == 1 && dda->ray_dir.y < 0) texX = tex_draw->size.x - texX - 1;
		

	// How much to increase the texture coordinate per screen pixel
	double step = 1.0 * tex_draw->size.y / dda->lineheight;
	// Starting texture coordinate
	double texPos = (dda->drawstart - data->r_y / 2 + dda->lineheight / 2) * step;
	for(int y = dda->drawstart; y < dda->drawend; y++)
	{
		// Cast the texture coordinate to integer, and mask with (tex.height - 1) in case of overflow
		int texY = (int)texPos & (tex_draw->size.y - 1);
		texPos += step;
		data->img_i = texture[tex][tex.height * texY + texX];
	}
}
*/

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

		dda.lineheight = (int)(data->r_y / dda.perpwalldist);
		dda.drawstart = -dda.lineheight / 2 + data->r_y / 2;
		if (dda.drawstart < 0)
			dda.drawstart = 0;
		dda.drawend = dda.lineheight / 2 + data->r_y / 2;
		if (dda.drawend > data->r_y)
			dda.drawend = data->r_y;
			
		draw_image(data, &dda);
		dda.x++;
	}
	return 0;
}