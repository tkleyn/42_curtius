/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:05:43 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/20 14:31:50 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ck_open_file(int *fd, char *file)
{
	char *str;

	if (!(str = ft_strrchr(file, '.')))
		return (f_err("file has no extention", -1, NULL));
	if (str == file)
		return (f_err(".cub file has no name", -1, NULL));
	if (!(*++str == 'c' && *++str == 'u' && *++str == 'b' && *++str == '\0'))
		return (f_err("Invalid extention", -1, NULL));
	if ((*fd = open(file, O_RDONLY)) < 0)
		return (f_err("Map file not found", -1, NULL));
	return (1);
}

int				load_cub(char *file, t_cub *data)
{
	int				fd;
	char			*str;
	unsigned char	ck;
	int				ret;

	if (ck_open_file(&fd, file) < 0)
		return (-1);
	ck = 0;
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
	if (get_map(fd, data) < 0)
		return (-1);
	close(fd);
	return (0);
}
