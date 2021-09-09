/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/27 15:39:22 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char				*endl_check(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

static int				ft_desaloc(char **rest)
{
	if (rest && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (-1);
}

static int				line_packager(char **line, char **rest)
{
	char *endl_found;

	if ((endl_found = endl_check(*rest)))
	{
		if (!(*line = ft_strndup(*rest, endl_found - *rest)))
			return (-1);
		if (!(endl_found = ft_strdup(endl_found + 1)))
			return (-1);
		free(*rest);
		*rest = endl_found;
		return (1);
	}
	return (0);
}

static int				body(char **line, char *read_buff, char **rest, int fd)
{
	int		read_size;
	int		package_return;

	while ((read_size = read(fd, read_buff, BUFFER_SIZE)) > 0)
	{
		read_buff[read_size] = '\0';
		if ((*rest = ft_strjoin(*rest, read_buff)) == NULL)
			return (ft_desaloc(rest));
		package_return = line_packager(line, rest);
		if (package_return == 1)
			return (1);
		else if (package_return == -1)
			return (ft_desaloc(rest));
	}
	if (read_size <= 0)
		return (ft_desaloc(rest));
	*line = ft_strdup(*rest);
	ft_desaloc(rest);
	return (0);
}

int						ft_gnl(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest[OPEN_MAX];
	int				package_return;

	if (fd < 0)
	{
		*line = rest[-fd];
		if (rest[-fd] && *rest[-fd])
			return (0);
		return (-1);
	}
	if (!line || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (rest[fd])
	{
		package_return = line_packager(line, &rest[fd]);
		if (package_return == 1)
			return (1);
		else if (package_return == -1)
			return (ft_desaloc(&rest[fd]));
	}
	return (body(line, read_buff, &rest[fd], fd));
}
