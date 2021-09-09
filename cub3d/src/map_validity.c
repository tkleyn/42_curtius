/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:21:33 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/23 16:12:05 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int				is_valid_pos(t_cub *data, int k, int l)
{
	int len;

	if (k >= 0 && k < data->map_height)
		len = ft_strlen(data->map[k]);
	else
		return (0);
	if (l >= len || l < 0)
		return (0);
	if (data->map[k][l] == ' ')
		return (0);
	return (1);
}

static void				ck_body(t_cub *data, int i, int j)
{
	if (!is_valid_pos(data, i - 1, j - 1))
		error_exit(data, "Invalid map");
	if (!is_valid_pos(data, i - 1, j))
		error_exit(data, "Invalid map");
	if (!is_valid_pos(data, i - 1, j + 1))
		error_exit(data, "Invalid map");
	if (!is_valid_pos(data, i, j - 1))
		error_exit(data, "Invalid map");
	if (!is_valid_pos(data, i, j + 1))
		error_exit(data, "Invalid map");
	if (!is_valid_pos(data, i + 1, j - 1))
		error_exit(data, "Invalid map");
	if (!is_valid_pos(data, i + 1, j))
		error_exit(data, "Invalid map");
	if (!is_valid_pos(data, i + 1, j + 1))
		error_exit(data, "Invalid map");
}

void					check_map_validity(t_cub *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != ' ')
			{
				ck_body(data, i, j);
			}
			j++;
		}
		i++;
	}
}
