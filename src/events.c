/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:54:03 by tkleynts          #+#    #+#             */
/*   Updated: 2020/09/30 11:13:27 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int				key_pressed(int key, t_cub *data)
{
	if (key == k_UpArrow || key == k_ANSI_W)
		data->move_ud = 1;
	else if (key == k_DownArrow || key == k_ANSI_S)
		data->move_ud = -1;
	else if (key == k_ANSI_A)
		data->move_lr = -1;
	else if (key == k_ANSI_D)
		data->move_lr = 1;
	else if (key == k_LeftArrow)
		data->rotate = -1;
	else if (key == k_RightArrow)
		data->rotate = 1;
	else if (key == k_Escape)
		clean_exit(data);
	else if (key == k_ANSI_T)
	{
		data->apply_tex = ~data->apply_tex;
		data->refresh = 1;
	}
	return (0);
}

static int				key_released(int key, t_cub *data)
{
	if (key == k_UpArrow || key == k_ANSI_W)
		data->move_ud = 0;
	else if (key == k_DownArrow || key == k_ANSI_S)
		data->move_ud = 0;
	else if (key == k_ANSI_A)
		data->move_lr = 0;
	else if (key == k_ANSI_D)
		data->move_lr = 0;
	else if (key == k_RightArrow || key == k_LeftArrow)
		data->rotate = 0;
	return (0);
}

static int				cub_playzone(t_cub *data)
{
	if (data->refresh)
	{
		dda(data);
		mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
		data->refresh = 0;
	}
	if (data->move_ud)
		data->refresh = move_fw(data);
	if (data->move_lr)
		data->refresh = move_lr(data);
	if (data->rotate)
		data->refresh = move_rot(data);
	return (0);
}

int						cub_loop(t_cub *data)
{
	mlx_hook(data->window, KeyPress, 0, key_pressed, data);
	mlx_hook(data->window, KeyRelease, 0, key_released, data);
	mlx_hook(data->window, DestroyNotify, 0, clean_exit, data);
	mlx_loop_hook(data->mlx, cub_playzone, data);
	mlx_loop(data->mlx);
	return (0);
}
