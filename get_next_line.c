/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/15 14:02:22 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_packager(char **line, char **rest)
{
	char *endl_found;

	if ((endl_found = endl_check(*rest)))
	{
		if ((*line = ft_strmdup(*rest, endl_found - *rest)) < 0)
			return (-1);
		if ((endl_found = ft_strmdup(endl_found + 1, -1)) < 0)
			return (-1);
		free(*rest);
		*rest = endl_found;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest;
	int				read_size;
	int				package_return;

	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (ft_desaloc(line, &rest));
	*line = NULL;
	if (rest)
	{
		package_return = line_packager(line, &rest);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (ft_desaloc(line, &rest));
	}
	while ((read_size = read(fd, read_buff, BUFFER_SIZE)) > 0)
	{
		rest = ft_strjoin(rest, read_buff);
		package_return = line_packager(line, &rest);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (ft_desaloc(line, &rest));
	}
	if (read_size < 0)
		return (ft_desaloc(line, &rest));
	*line = ft_strmdup(rest, -1);
	rest = NULL;
	return (0);
}
