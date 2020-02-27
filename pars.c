/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:05:43 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/27 15:51:32 by tkleynts         ###   ########.fr       */
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
	ffrintf(2, "Error\n%s\n", msg);
	if (tab)
		tab_free(tab);
	return (ret);
}

char			*rm_spaces(char *str)
{
	char	*str_cpy;
	char	*new_str;
	char	*new_str_cpy;
	int		cnt;

	if (!str)
		return (NULL);
	cnt = 0;
	str_cpy = str;
	while (*str_cpy)
		if (!ft_isspace(*str_cpy++))
			cnt++;
	if (!(new_str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	str_cpy = str;
	new_str_cpy = new_str;
	while (*str_cpy)
	{
		if (!ft_isspace(*str_cpy))
			*new_str_cpy++ = *str_cpy;
		str_cpy++;
	}
	*new_str_cpy = '\0';
	return (new_str);
}

int fct(int fd, t_cub *data)
{
	char		buff[59];
	int			by_read;
	char		*tmp;
	int			i;
	int			len;

	i = 0;
	(ft_gnl(-fd, &tmp) != 0) ? (tmp = NULL) : (tmp = tmp);
	len = ft_strlen(tmp);
	while ((by_read = read(fd, buff, sizeof(buff))) >= 1)
	{
		if (!(tmp = ft_strnjoin(tmp, buff, len, by_read)))
			return (f_err("map", -1, NULL));
		len +=by_read;
	}
	if (!(data->map = ft_split(tmp, '\n')))
			return (f_err("map", -1, NULL));
	while(data->map[i] != 0)
	{
		tmp = rm_spaces(data->map[i]);
		free(data->map[i]);
		data->map[i] = tmp;
		//
		i++;
	}
	return 0;
}

int				is_str_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

int				ck_path(char *str, t_cub *data, char *msg, char **path)
{
	char			**tab;

	if (!(tab = split_space(&str[1])) || tab[1] != 0)
		return (f_err(msg, -1, tab));
	if (!(*path = ft_strdup(*tab)))
		return (f_err(msg, -1, tab));
	tab_free(tab);
	return (0);
}

int				ck_colors(char *str, t_cub *data, char *msg, unsigned char *col)
{
	char		**tab;
	int			i;
	int			tmp;

	i = 0;
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
		*col++ = tmp;
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
		ret = ck_colors(str, data, "Invalid floor color", &data->f_red);
	else if (*str == 'C' && !(*ck & C) && (*ck += C))
		ret = ck_colors(str, data, "Invalid ceilling color", &data->c_red);
	else if ((!ft_strncmp(str, "NO", 2)) && !(*ck & NO) && (*ck += NO))
		ret = ck_path(&str[1], data, "Invalid NO path", &data->tp_no);
	else if ((!ft_strncmp(str, "SO", 2)) && !(*ck & SO) && (*ck += SO))
		ret = ck_path(&str[1], data, "Invalid SO path", &data->tp_so);
	else if ((!ft_strncmp(str, "EA", 2)) && (*ck & EA) != EA && (*ck += EA))
		ret = ck_path(&str[1], data, "Invalid EA path", &data->tp_ea);
	else if ((!ft_strncmp(str, "WE", 2)) && !(*ck & WE) && (*ck += WE))
		ret = ck_path(&str[1], data, "Invalid WE path", &data->tp_we);
	else if (*str == 'S' && !(*ck & S) && (*ck += S))
		ret = ck_path(str, data, "Invalid S path", &data->tp_s);
	else
		ret = f_err("Invalid .cub file", -1, NULL);
	return (ret);
}

int				load_cub(char *file, t_cub *data)
{
	int				fd;
	char			*str;
	unsigned char	ck;
	int				ret;
	int				i;

	if (!(str = ft_strrchr(file, '.')))
		return (f_err("file has no extention", -1, NULL));
	if (str == file)
		return (f_err(".cub file has no name", -1, NULL));
	if (!(*++str == 'c' && *++str == 'u' && *++str == 'b' && *++str == '\0'))
		return (f_err("Invalid extention", -1, NULL));
	ck = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (f_err("Map file not found", -1, NULL));
	while (ck != 255 && ft_gnl(fd, &str) > 0)
	{
		if (*str == '\0')
			continue;
		else
			ret = ck_arg(str, data, &ck);
		free(str);
		if (ret < 0)
			return (-1);
	}
	if (ck != 255)
		return (f_err("Invalid .cub file", -1, NULL));
	if(fct(fd, data) < 0)
		return (-1);
	close(fd);
	return (0);
}

int				main(int argc, char **argv)
{
	int i = 0;

	if (argc != 2)
		return (f_err("Wrong number of args", -1, NULL));
	t_cub loaded_file;
	if (!load_cub(argv[1], &loaded_file))
	{
		frintf("resolution : %d:%d\n", loaded_file.r_x, loaded_file.r_y);
		frintf("path NO : %s\n", loaded_file.tp_no);
		frintf("path SO : %s\n", loaded_file.tp_so);
		frintf("path WE : %s\n", loaded_file.tp_we);
		frintf("path EA : %s\n", loaded_file.tp_ea);
		frintf("path S : %s\n", loaded_file.tp_s);
		frintf("F col : %d:%d:%d\n", loaded_file.f_red, loaded_file.f_grn, loaded_file.f_blu);
		frintf("Ccol : %d:%d:%d\n", loaded_file.c_red, loaded_file.c_grn, loaded_file.c_blu);
		
		while (loaded_file.map[i] != 0)
			frintf("%s\n", loaded_file.map[i++]);
	}
}

