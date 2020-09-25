/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:10:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/09/25 13:59:57 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				clean_exit(t_cub *data)
{
	if (data->map)
		tab_free(data->map);
	if (data->t[0].tex && data->t[0].size.x == 0)
		free(data->t[0].tex);
	if (data->t[1].tex && data->t[1].size.x == 0)
		free(data->t[1].tex);
	if (data->t[2].tex  && data->t[2].size.x == 0)
		free(data->t[2].tex);
	if (data->t[3].tex && data->t[3].size.x == 0)
		free(data->t[3].tex);
	if (data->t[4].tex && data->t[4].size.x == 0)
		free(data->t[4].tex);
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
	if (!data->apply_tex)
		if (!(data->window = mlx_new_window(data->mlx, data->r_x, data->r_y, "Cub3d")))
			clean_exit(data);
	if (!(data->img = mlx_new_image(data->mlx, data->r_x, data->r_y)))
		clean_exit(data);
	if(!(data->img_c = mlx_get_data_addr(data->img, &a, &a, &a)))
		clean_exit(data);
	data->img_i = (int*)data->img_c;
	return (0);
}

static void			struct_init(t_cub *data)
{
	setpos(data, -1, 0);
	setdir(data, 0, 0);
	setplane(data, 0, 0);
	data->move_ud		= 0;
	data->move_lr		= 0;
	data->rotate		= 0;
	data->floor			= 0;
	data->ceiling		= 0;
	data->t[0].size.x 	= 0;
	data->t[1].size.x 	= 0;
	data->t[2].size.x 	= 0;
	data->t[3].size.x 	= 0;
	data->t[4].size.x 	= 0;
	data->map			= 0;
	data->apply_tex		= 0;
	data->refresh		= 1;
}

int				tex_load(t_cub *data)
{
	char *file;
	int i;
	int a;
	
	i = 0;
	while (i <= 4)
	{
		file = data->t[i].tex;
		if(!(data->t[i].tex = mlx_xpm_file_to_image(data->mlx, file, &data->t[i].size.x, &data->t[i].size.y)))
			clean_exit(data);
		if(!(data->t[i].tex_c = mlx_get_data_addr(data->t[i].tex, &a, &a, &a)))
			clean_exit(data);

		data->t[i].tex_i = (int*)data->t[i].tex_c;
		free (file);
		i++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_cub data;

	if (argc < 2)
		return (f_err("No specified map", -1, NULL));
	else if (argc > 3)
		return (f_err("Too many args", -1, NULL));
	struct_init(&data);
	if (load_cub(argv[1], &data) < 0)
		exit (-1);
	if (argc == 3 && !ft_strncmp("--save", argv[2], 7))
		bmp2img(&data);
	else if (argc == 3)
		return (f_err("Wrong Option", -1, NULL));
	cub_init(&data);
	tex_load(&data);
	cub_loop(&data);
	return (0);
}
