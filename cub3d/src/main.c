/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:10:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/23 14:24:01 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					cub_init(t_cub *data)
{
	int	a;

	if (!(data->mlx = mlx_init()))
		error_exit(data, "Impossible to create an instance of mlx");
	if (!data->apply_tex)
		if (!(data->window = mlx_new_window(data->mlx, data->r_x,
											data->r_y, "Cub3d")))
			error_exit(data, "Impossible to create an mlx window");
	if (!(data->img = mlx_new_image(data->mlx, data->r_x, data->r_y)))
		error_exit(data, "Impossible to create an mlx image");
	if (!(data->img_c = mlx_get_data_addr(data->img, &a, &a, &a)))
		error_exit(data, "Impossible to get image address");
	data->img_i = (int*)data->img_c;
	return (0);
}

static void			struct_init(t_cub *data)
{
	setpos(data, -1, 0);
	setdir(data, 0, 0);
	setplane(data, 0, 0);
	data->move_ud = 0;
	data->move_lr = 0;
	data->rotate = 0;
	data->floor = 0;
	data->ceiling = 0;
	data->t[0].size.x = 0;
	data->t[1].size.x = 0;
	data->t[2].size.x = 0;
	data->t[3].size.x = 0;
	data->t[4].size.x = 0;
	data->map = 0;
	data->apply_tex = 0;
	data->refresh = 1;
	data->n_srites = 0;
	data->n_row = 0;
	data->map_height = 0;
	data->map = NULL;
	data->img = NULL;
	data->window = NULL;
	data->mlx = NULL;
}

int					tex_load(t_cub *data)
{
	char	*file;
	int		i;
	int		a;

	i = 0;
	while (i <= 4)
	{
		file = data->t[i].tex;
		if (!(data->t[i].tex = mlx_xpm_file_to_image(data->mlx, file,
							&data->t[i].size.x, &data->t[i].size.y)))
			error_exit(data, "Wrong texture path");
		if (!(data->t[i].tex_c = mlx_get_data_addr(data->t[i].tex, &a, &a, &a)))
			error_exit(data, "Impossible to get image address of a texture");
		data->t[i].tex_i = (int*)data->t[i].tex_c;
		free(file);
		i++;
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_cub data;

	if (argc < 2)
		return (f_err("No specified map", -1, NULL));
	else if (argc > 3)
		return (f_err("Too many args", -1, NULL));
	struct_init(&data);
	if (load_cub(argv[1], &data) < 0)
		exit(-1);
	if (argc == 3 && !ft_strncmp("--save", argv[2], 7))
		bmp2img(&data);
	else if (argc == 3)
		return (f_err("Wrong Option", -1, NULL));
	cub_init(&data);
	tex_load(&data);
	cub_loop(&data);
	return (0);
}
