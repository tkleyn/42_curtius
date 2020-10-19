/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:46:24 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/19 14:24:33 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_fw(t_cub *data)
{
	t_vector new_pos;
	int ret;
	t_vector space;

	space.x = (data->dir.x >= 0)? -0.2 : 0.2;
	space.y = (data->dir.y >= 0)? 0.2 : -0.2;
	ret = 0;
	new_pos.x = data->pos.x + data->dir.x * SPEED * data->move_ud;
	new_pos.y = data->pos.y + data->dir.y * SPEED * data->move_ud;
	if (data->map[(int)data->pos.y][(int)(new_pos.x - data->move_ud * space.x)] == '0')
	{
		setpos(data, new_pos.x, data->pos.y);
		ret = 1;
	}
	if (data->map[(int)(new_pos.y + data->move_ud * space.y)][(int)data->pos.x] == '0')
	{
		setpos(data, data->pos.x, new_pos.y);
		ret = 1;
	}
	return (ret);
}

int         move_lr(t_cub *data)
{
	t_vector new_pos;
	int ret;

	ret = 0;
	new_pos.x = data->pos.x - data->move_lr * data->dir.y * (SPEED / 2);
	new_pos.y = data->pos.y + data->move_lr * data->dir.x * (SPEED / 2);
	if (data->map[(int)data->pos.y][(int)new_pos.x] == '0')
	{
		setpos(data, new_pos.x, data->pos.y);
		ret = 1;
	}
	if (data->map[(int)new_pos.y][(int)data->pos.x] == '0')
	{
		setpos(data, data->pos.x, new_pos.y);
		ret = 1;

	}
		return (ret);
}

int         move_rot(t_cub *data)
{
	t_vector    new_dir;
	t_vector    new_plane;
	double      r_speed;

	r_speed = data->rotate * SPEED / 2;
	new_dir.x = data->dir.x * cos(r_speed) - data->dir.y * sin(r_speed);
	new_dir.y = data->dir.x * sin(r_speed) + data->dir.y * cos(r_speed);
	new_plane.x = data->plane.x * cos(r_speed) - data->plane.y * sin(r_speed);
	new_plane.y = data->plane.x * sin(r_speed) + data->plane.y * cos(r_speed);
	setdir(data, new_dir.x, new_dir.y);
	setplane(data, new_plane.x, new_plane.y);
	return (1);
}
