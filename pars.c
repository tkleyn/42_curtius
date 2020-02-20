/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:05:43 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/19 16:42:51 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void		tab_free(char **tab)
{
	char **tb_cpy;

	tb_cpy = tab;
	while (*tb_cpy)
		free(*tb_cpy++);
	free(tab);
	tab = NULL;
}

int			f_err(char *msg, int ret, char **tab)
{
	ffrintf(2, "Error\n%s\n", msg);
	if (tab)
		tab_free(tab);
	return(ret);
}


place_holder(char *str, char **tab, t_cub *data, char *msg)
{
	if (!(tab = split_space(&str[1])) || tab[1] != 0)
		return(f_err(msg, -1, tab));
	if(!(data->tp_s = ft_strdup(*tab)))
		return(f_err(msg, -1, tab));
}

int			load_cub(char *file, t_cub *data)
{
	int				fd;
	char			*str;
	unsigned char	check;
	char			**tab;

	check = 0;
	str = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		return(f_err("Map file not found", -1, NULL));
	while (ft_gnl(fd, &str) > 0 && check != 255) //protect gnl call
	{
		if (*str == '\0')
			continue;
		else if (*str == 'R' && !(check & R) && (check += R))
		{
			if (!(tab = split_space(&str[1])) || tab[1] == 0 || tab[2] != 0)
				return(f_err("Invalid resolution", -1, tab));
			if ((data->r_x = ft_atoi(tab[0])) < 1 || (data->r_y = ft_atoi(tab[1])) < 1)
				return(f_err("Invalid resolution", -1, tab));
		}
		else if (*str == 'F' && !(check & F) && (check += F))
		{
			if (!(tab = ft_split(&str[1], ',')) || tab[1] == 0 || tab[2] == 0 || tab[3] != 0)
				return(f_err("Invalid floor color", -1, tab));
			if ((data->f_red = ft_atoi(tab[0])) < 0 || (data->f_grn = ft_atoi(tab[1])) < 0 || (data->f_blu = ft_atoi(tab[2])) < 0)
				return(f_err("Invalid floor color", -1, tab));
		}
		else if (*str == 'C' && !(check & C) && (check += C))
		{
			if (!(tab = ft_split(&str[1], ',')) || tab[1] == 0 || tab[2] == 0 || tab[3] != 0)
				return(f_err("Invalid ceilling color", -1, tab));
			if ((data->f_red = ft_atoi(tab[0])) < 0 || (data->f_grn = ft_atoi(tab[1])) < 0 || (data->f_blu = ft_atoi(tab[2])) < 0)
				return(f_err("Invalid ceilling color", -1, tab));
		}
		else if ((!ft_strncmp(str, "NO", 2)) && !(check & NO) && (check += NO))
		{
			if (!(tab = split_space(&str[2])) || tab[1] != 0)
				return(f_err("Invalid NO path", -1, tab));
			if(!(data->tp_no = ft_strdup(*tab)))
				return(f_err("Invalid NO path", -1, tab));
		}
		else if ((!ft_strncmp(str, "SO", 2)) && !(check & SO) && (check += SO))
		{
			if (!(tab = split_space(&str[2])) || tab[1] != 0)
				return(f_err("Invalid SO path", -1, tab));
			if(!(data->tp_so = ft_strdup(*tab)))
				return(f_err("Invalid SO path", -1, tab));
		}
		else if ((!ft_strncmp(str, "EA", 2)) && (check & EA) != EA && (check += EA))
		{
			if (!(tab = split_space(&str[2])) || tab[1] != 0)
				return(f_err("Invalid EA path", -1, tab));

			if(!(data->tp_ea = ft_strdup(*tab)))
				return(f_err("Invalid EA path", -1, tab));
		}
		else if ((!ft_strncmp(str, "WE", 2)) && !(check & WE) && (check += WE))
		{
			if (!(tab = split_space(&str[2])) || tab[1] != 0)
				return(f_err("Invalid WE path", -1, tab));

			if(!(data->tp_we = ft_strdup(*tab)))
				return(f_err("Invalid WE path", -1, tab));
		}
		else if (*str == 'S' && !(check & S) && (check += S))
		{
			if (!(tab = split_space(&str[1])) || tab[1] != 0)
				return(f_err("Invalid S path", -1, tab));

			if(!(data->tp_s = ft_strdup(*tab)))
				return(f_err("Invalid S path", -1, tab));
		}
		else
		{
			perror("Error\nInvalid .cub file");
			return (0);
		}
		free(str);
		tab_free(tab);

	}
	close(fd);
	if (check != 255)
	{
		perror("Error\nInvalid .cub file18");
		return (0);
	}
	return 1;
}

int main()
{
	t_cub loaded_file;
	if(load_cub("jean.cub", &loaded_file))
	{
		frintf("resolution : %d:%d\n", loaded_file.r_x, loaded_file.r_y);
		frintf("path NO : %s\n", loaded_file.tp_no);
		frintf("C col : %d:%d:%d\n", loaded_file.c_red, loaded_file.c_grn, loaded_file.c_blu);
	}
}
