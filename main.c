/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:10:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/03/10 14:21:28 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				cub(t_cub *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->r_x, data->r_y, "Cub3d");

	mlx_loop(data->mlx);

	mlx_destroy_window (data->mlx, data->window);
	exit (0);
}

int				main(int argc, char **argv)
{
	t_cub cub_conf;

	if (argc != 2)
		return (f_err("Wrong number of args", -1, NULL));
	cub_conf.spawn_x = -1;
	if (load_cub(argv[1], &cub_conf) < 0)
		return (-1);
	cub(&cub_conf);
	return (0);
}
