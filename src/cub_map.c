/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:31:06 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/15 14:02:35 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int					alloc_sprite(t_cub *data)
{
	int i;
	int j;
	int n;

	if (!(data->s_pos = (t_sp_pos *)malloc(sizeof(t_sp_pos) * data->n_srites)))
		return (-1);
	j = 0;
	n = 0;
	while (j < data->n_row)
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '2')
			{
				data->s_pos[n].pos.x = i;
				data->s_pos[n].pos.y = j;
				n++;
			}
			i++;
		}
		j++;
	}
	return (0);
}

static int					ck_val_map(char *str, t_cub *data, int i)
{
	while (*(str + 1))
	{
		if (*str == '0' || *str == '1' || (*str == '2' && data->n_srites++))
			str++;
		else if (data->pos.x < 0 && (*str == 'N' || *str == 'S'
									|| *str == 'W' || *str == 'E'))
		{
			data->pos.x = str - data->map[i] + 0.5;
			data->pos.y = i + 0.5;
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
		else
			return (-1);
	}
	return (0);
}

static int					ck_map(char *str, t_cub *data, int i)
{
	static int size;

	if (i == 0)
	{
		size = ft_strlen(str);
		while (*str)
			if (*str++ != '1')
				return (-1);
		return (0);
	}
	if ((*str != '1' || str[ft_strlen(str) - 1] != '1'
					|| size != (int)ft_strlen(str)) && str++)
		return (-1);
	return (ck_val_map(str, data, i));
}

static int					map_to_tab(int fd, t_cub *data)
{
	int			len;
	int			by_read;
	char		buff[60];
	char		*tmp;
	int i;

	i = 0;
	(ft_gnl(-fd, &tmp) != 0) ? (tmp = NULL) : (tmp);
	len = ft_strlen(tmp);
	while ((by_read = read(fd, buff, sizeof(buff))) >= 1)
	{
		if (!(tmp = ft_strnjoin(tmp, buff, len, by_read)))
			return (-1);
		len += by_read;
	}
	while(tmp[i])
		data->n_row++;
	if (!(data->map = ft_split(tmp, '\n')))
		return (-1);
	return (0);
}

int					get_map(int fd, t_cub *data)
{
	char		*tmp;
	int			i;

	if (map_to_tab(fd, data) < 0)
		return (f_err("Invalid map", -1, NULL));
	i = 0;
	while (data->map[i] != 0)
	{
		tmp = rm_spaces(data->map[i]);
		free(data->map[i]);
		data->map[i] = tmp;
		if (ck_map(tmp, data, i) < 0)
			return (f_err("Invalid map", -1, data->map));
		i++;
	}
	while (*tmp)
		if (*tmp++ != '1')
			return (f_err("Invalid map", -1, data->map));
	if (data->pos.x == -1)
		return (f_err("Invalid map", -1, data->map));
	if (alloc_sprite(data))
		return (f_err("Allocation Error", -1, data->map));
	return (0);
}
