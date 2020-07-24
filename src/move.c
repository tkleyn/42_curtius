/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:46:24 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/24 11:25:12 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		move_fw(t_cub *data)
{
	t_vector new_pos;

	new_pos.x =  data->pos.x + data->dir.x * SPEED * data->move_ud;
	new_pos.y =  data->pos.y + data->dir.y * SPEED * data->move_ud;
	if (data->map[(int)new_pos.y][(int)new_pos.x] == '0')
	{
		setpos(data, new_pos.x, new_pos.y);
		return (1);
	}
	return (0);
}

int			move_lr(t_cub *data)
{	
	t_vector new_pos;

	new_pos.x =  data->pos.x - data->move_lr * data->dir.y * (SPEED/2);
	new_pos.y =  data->pos.y - ~data->move_lr * data->dir.x * (SPEED/2);
	if (data->map[(int)new_pos.y][(int)new_pos.x] == '0')
	{
		setpos(data, new_pos.x, new_pos.y);
		return (1);
	}
	return (0);
}

int			move_rot(t_cub *data)
{
	t_vector	new_dir;
	t_vector	new_plane;
	double		r_speed;

	r_speed = data->rotate * SPEED / 2;
	new_dir.x = data->dir.x * cos(r_speed) - data->dir.y * sin(r_speed);
	new_dir.y = data->dir.x * sin(r_speed) + data->dir.y * cos(r_speed);
	new_plane.x = data->plane.x * cos(r_speed) - data->plane.y * sin(r_speed);
	new_plane.y = data->plane.x * sin(r_speed) + data->plane.y * cos(r_speed);
	setdir(data, new_dir.x, new_dir.y);
	setplane(data, new_plane.x, new_plane.y);
	return (1);
}