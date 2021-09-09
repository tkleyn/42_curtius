/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:31:06 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/23 15:25:49 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int				alloc_sprite(t_cub *data)
{
	int i;
	int j;
	int n;

	if (!(data->s_pos = (t_sp_pos *)malloc(sizeof(t_sp_pos) * data->n_srites)))
		return (-1);
	j = 0;
	n = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '2')
			{
				data->s_pos[n].pos.x = (double)(i + 0.5);
				data->s_pos[n].pos.y = (double)(j + 0.5);
				n++;
			}
			i++;
		}
		j++;
	}
	return (0);
}

void					set_spawn(t_cub *data, char *str)
{
	if (*str == 'N')
	{
		data->dir.y = -1;
		data->plane.x = 0.66;
	}
	else if (*str == 'S')
	{
		data->dir.y = 1;
		data->plane.x = -0.66;
	}
	else if (*str == 'W')
	{
		data->dir.x = -1;
		data->plane.y = -0.66;
	}
	else if (*str == 'E')
	{
		data->dir.x = 1;
		data->plane.y = 0.66;
	}
	*str++ = '0';
}

static int				ck_val_map(char *str, t_cub *data, int i)
{
	while (*str)
	{
		if (*str == '0' || *str == '1' || *str == ' '
				|| (*str == '2' && (data->n_srites++ || 1)))
			str++;
		else if (data->pos.x < 0 && (*str == 'N' || *str == 'S'
									|| *str == 'W' || *str == 'E'))
		{
			data->pos.x = str - data->map[i] + 0.5;
			data->pos.y = i + 0.5;
			set_spawn(data, str);
		}
		else
			return (-1);
	}
	return (0);
}

static int				map_to_tab(int fd, t_cub *data)
{
	int			len;
	int			by_read;
	char		buff[200];
	char		*tmp;

	(ft_gnl(-fd, &tmp) != 0) ? (tmp = NULL) : (tmp);
	len = ft_strlen(tmp);
	while ((by_read = read(fd, buff, sizeof(buff))) >= 1)
	{
		if (!(tmp = ft_strnjoin(tmp, buff, len, by_read)))
			return (-1);
		len += by_read;
	}
	if (!(data->map = cub_split(tmp, '\n')))
		return (-1);
	while (data->map[data->map_height])
		data->map_height++;
	return (0);
}

int						get_map(int fd, t_cub *data)
{
	int			i;

	if (map_to_tab(fd, data) < 0)
		error_exit(data, "Allocation Error");
	i = 0;
	while (data->map[i] != 0)
	{
		if (ck_val_map(data->map[i], data, i) < 0)
			error_exit(data, "Invalid map");
		i++;
	}
	if (data->pos.x == -1)
		error_exit(data, "Invalid map");
	check_map_validity(data);
	if (alloc_sprite(data))
		error_exit(data, "Allocation Error");
	i = 0;
	return (0);
}
