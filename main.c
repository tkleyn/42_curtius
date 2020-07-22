/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:10:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/22 17:09:38 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				key_pressed(int key, t_cub *data)
{
	if (key == k_UpArrow || key == k_ANSI_W)
		data->pos_y -= 0.1; //data->move = -1;
	else if (key == k_DownArrow || key == k_ANSI_S)
			data->pos_y += 0.1;//data->move = 1;
	else if (key == k_LeftArrow || key == k_ANSI_A)
				data->pos_x -= 0.1;//->rotate = -1;
	else if (key == k_RightArrow || key == k_ANSI_D)
				data->pos_x += 0.1;//data->rotate = 1;
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
		data->move = 0;
	else if (key == k_DownArrow || key == k_ANSI_S)
			data->move = 0;
	else if (key == k_LeftArrow || key == k_ANSI_A)
				data->rotate = 0;
	else if (key == k_RightArrow || key == k_ANSI_D)
				data->rotate = 0;
	return (0);
}

int				playzone(t_cub *data)
{
	dda(data);
	mlx_put_image_to_window (data->mlx, data->window, data->img, 0, 0);
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

	data->pos_x		= -1;
	data->dir_x		= 0;
	data->dir_y		= 0;
	data->plane_y	= 0;
	data->plane_y	= 0;
	data->move		= 0;
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
