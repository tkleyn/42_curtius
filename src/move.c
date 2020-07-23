/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:46:24 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/23 15:04:29 by tkleynts         ###   ########.fr       */
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