/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:10:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/29 14:55:34 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				clean_exit(t_cub *data)
{
	if (data->map)
		tab_free(data->map);
	if (data->tp_no)
		free(data->tp_no);
	if (data->tp_so)
		free(data->tp_so);
	if (data->tp_ea)
		free(data->tp_ea);
	if (data->tp_ea)
		free(data->tp_we);
	if (data->tp_ea)
		free(data->tp_s);
	if(data->img)
		mlx_destroy_image(data->mlx, data->img);
	if(data->window)
		mlx_destroy_image(data->mlx, data->window);
	if(data->mlx)
		free(data->mlx);
	exit (0);
}

int				cub_init(t_cub *data)
{
	int	a;

	if (!(data->mlx = mlx_init()))
		clean_exit(data);
	if (!(data->window = mlx_new_window(data->mlx, data->r_x, data->r_y, "Cub3d")))
		clean_exit(data);
	if (!(data->img = mlx_new_image(data->mlx, data->r_x, data->r_y)))
		clean_exit(data);
	if(!(data->img_c = mlx_get_data_addr(data->img, &a, &a, &a)))
		clean_exit(data);
	data->img_i = (int*)data->img_c;
	return (0);
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
	data->tp_no 	= 0;
	data->tp_so 	= 0;
	data->tp_ea 	= 0;
	data->tp_we 	= 0;
	data->tp_s 		= 0;
	data->map		= 0;
}

int				main(int argc, char **argv)
{
	t_cub data;

	if (argc == 3)
	{
		//screenshot
		exit(0);
	}	
	else if (argc != 2)
		return (f_err("No specified map", -1, NULL));
	struct_init(&data);
	if (load_cub(argv[1], &data) < 0)
		exit (-1);
	cub_init(&data);
	cub_loop(&data);
	return (0);
}
