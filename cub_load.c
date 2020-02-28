/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:05:43 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/28 10:15:49 by tkleynts         ###   ########.fr       */
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

int get_map(int fd, t_cub *data)
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
	if(get_map(fd, data) < 0)
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

