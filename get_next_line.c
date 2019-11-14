/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/14 11:21:40 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest;
	int				read_size;
	int				package_return;

	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (rest)
	{
		package_return = line_packager(line, &rest);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (-1);
	}
	while ((read_size = read(fd, read_buff, BUFFER_SIZE)) > 0)
	{
		rest = ft_strjoin(rest, read_buff);
		package_return = line_packager(line, &rest);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (-1);
	}
	if (read_size < 0)
		return (-1);
	*line = ft_strmdup(rest, -1);
	rest = NULL;
	return (0);
}
