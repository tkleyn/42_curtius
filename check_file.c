/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:01:45 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/14 15:43:08 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ck_path(char *str, char *msg, char **path)
{
	char			**tab;

	if (!(tab = split_space(&str[1])) || tab[1] != 0)
		return (f_err(msg, -1, tab));
	if (!(*path = ft_strdup(*tab)))
		return (f_err(msg, -1, tab));
	tab_free(tab);
	return (0);
}

int				ck_colors(char *str, char *msg, int *col)
{
	char		**tab;
	int			i;
	int			tmp;
	int			shft;

	i = 0;
	shft = 16;
	if (!(str = rm_spaces(str)))
		return (f_err(msg, -1, NULL));
	if (!(tab = ft_split(&str[1], ',')) || tab[1] == 0 || tab[2] == 0 || tab[3])
		return (f_err(msg, -1, tab));
	while (i <= 2)
	{
		if (!is_str_digit(tab[i]))
			return (f_err(msg, -1, tab));
		tmp = ft_atoi(tab[i++]);
		if (tmp < 0 || tmp > 255)
			return (f_err(msg, -1, tab));
		*col = *col + (tmp << shft);
		shft = shft - 8;
	}
	tab_free(tab);
	free(str);
	return (0);
}

int				ck_res(char *str, t_cub *data, char *msg)
{
	char **tab;

	if (!(tab = split_space(&str[1])) || tab[1] == 0 || tab[2] != 0)
		return (f_err(msg, -1, tab));
	if ((data->r_x = ft_atoi(tab[0])) < 1)
		return (f_err(msg, -1, tab));
	if ((data->r_y = ft_atoi(tab[1])) < 1)
		return (f_err(msg, -1, tab));
	(data->r_x > 5120) ? (data->r_x = 5120) : (1);
	(data->r_y > 2880) ? (data->r_y = 2880) : (1);
	tab_free(tab);
	return (0);
}

int				ck_arg(char *str, t_cub *data, unsigned char *ck)
{
	int ret;

	if (*str == 'R' && !(*ck & R) && (*ck += R))
		ret = ck_res(str, data, "Invalid resolution");
	else if (*str == 'F' && !(*ck & F) && (*ck += F))
		ret = ck_colors(str, "Invalid floor color", &data->floor);
	else if (*str == 'C' && !(*ck & C) && (*ck += C))
		ret = ck_colors(str, "Invalid ceilling color", &data->ceiling);
	else if ((!ft_strncmp(str, "NO", 2)) && !(*ck & NO) && (*ck += NO))
		ret = ck_path(&str[1], "Invalid NO path", &data->tp_no);
	else if ((!ft_strncmp(str, "SO", 2)) && !(*ck & SO) && (*ck += SO))
		ret = ck_path(&str[1], "Invalid SO path", &data->tp_so);
	else if ((!ft_strncmp(str, "EA", 2)) && (*ck & EA) != EA && (*ck += EA))
		ret = ck_path(&str[1], "Invalid EA path", &data->tp_ea);
	else if ((!ft_strncmp(str, "WE", 2)) && !(*ck & WE) && (*ck += WE))
		ret = ck_path(&str[1], "Invalid WE path", &data->tp_we);
	else if (*str == 'S' && !(*ck & S) && (*ck += S))
		ret = ck_path(str, "Invalid S path", &data->tp_s);
	else
		ret = f_err("Invalid .cub file", -1, NULL);
	return (ret);
}
