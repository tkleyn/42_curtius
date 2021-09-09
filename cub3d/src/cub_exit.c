/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:56:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/23 15:11:16 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			tab_free(char **tab)
{
	char **tb_cpy;

	tb_cpy = tab;
	while (*tb_cpy)
		free(*tb_cpy++);
	free(tab);
	tab = NULL;
}

int				f_err(char *msg, int ret, char **tab)
{
	ffrintf(2, "\nError\n%s\n", msg);
	if (tab)
		tab_free(tab);
	return (ret);
}

int				clean_exit(t_cub *data)
{
	int i;

	if (data->map)
		tab_free(data->map);
	i = -1;
	while (++i <= 4)
		if (data->t[i].tex && data->t[i].size.x == 0)
			free(data->t[i].tex);
		else if (data->t[i].tex)
			mlx_destroy_image(data->mlx, data->t[i].tex);
	if (data->n_srites != 0)
		free(data->s_pos);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		free(data->mlx);
	exit(0);
}

void			error_exit(t_cub *data, char *msg)
{
	ffrintf(2, "\nError\n%s\n", msg);
	clean_exit(data);
}
