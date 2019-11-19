/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/19 16:41:37 by tkleynts         ###   ########.fr       */
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

int		body(char **line, char *read_buff, char **rest, int fd)
{
	int		read_size;
	int		package_return;

	while ((read_size = read(fd, read_buff, BUFFER_SIZE)) > 0)
	{
		read_buff[read_size] = '\0';
		if (*rest = ft_strjoin(*rest, read_buff) == NULL)
			return (ft_desaloc(rest));
		package_return = line_packager(line, rest);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (ft_desaloc(rest));
	}
	if (read_size < 0)
		return (ft_desaloc(rest));
	*line = ft_strmdup(*rest, -1);
	*rest = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest[OPEN_MAX];
	int				package_return;

	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (rest[fd])
	{
		package_return = line_packager(line, &rest[fd]);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (ft_desaloc(&rest[fd]));
	}
	return (body(line, read_buff, &rest[fd], fd));
}
