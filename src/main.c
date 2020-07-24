/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:10:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/24 11:04:04 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				key_pressed(int key, t_cub *data)
{
	if (key == k_UpArrow || key == k_ANSI_W)
		data->move_ud = 1;
	else if (key == k_DownArrow || key == k_ANSI_S)
		data->move_ud = -1;
	else if (key == k_ANSI_A)
		data->move_lr = -1;
	else if (key == k_ANSI_D)
		data->move_lr = 1;
	else if(key == k_LeftArrow)
		data->rotate = -1;
	else if(key == k_RightArrow)
		data->rotate = 1;
	else if (key == k_Escape)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}

int				key_released(int key, t_cub *data)
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

int				playzone(t_cub *data)
{
	static int		refresh = 1;

	if(refresh)
	{
		dda(data);
		mlx_put_image_to_window (data->mlx, data->window, data->img, 0, 0);
		refresh = 0;
	}
	if (data->move_ud)
		refresh = move_fw(data);
	if (data->move_lr)
		refresh = move_lr(data);
	if (data->rotate)
		refresh = move_rot(data);
	return (0);
}

int				cub(t_cub *data)
{
	int	a;

	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->r_x, data->r_y, "Cub3d");
	data->img = mlx_new_image(data->mlx, data->r_x, data->r_y);
	data->img_c = mlx_get_data_addr(data->img, &a, &a, &a);
	data->img_i = (int*)data->img_c;
	mlx_hook(data->window, KeyPress, 0, key_pressed, data);
	mlx_hook(data->window, KeyRelease, 0, key_released, data);
	mlx_loop_hook(data->mlx, playzone, data);
	mlx_loop(data->mlx);
	mlx_destroy_window (data->mlx, data->window);
	exit (0);
}

void			struct_init(t_cub *data)
{
	setpos(data, -1, 0);
	setdir(data, 0, 0);
	setplane(data, 0, 0);
	data->move_ud	= 0;
	data->move_lr	= 0;
	data->rotate	= 0;
	data->floor		= 0;
	data->ceiling	= 0;
}

int				main(int argc, char **argv)
{
	t_cub data;

	if (argc != 2)
		return (f_err("No specified map", -1, NULL));

	struct_init(&data);

	if (load_cub(argv[1], &data) < 0)
		return (-1);
	cub(&data);
	return (0);
}
