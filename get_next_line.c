/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/12 19:32:20 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest;
	int				read_size;
	char			*endl_found;


	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (rest && (endl_found = endl_check(rest)))
	{
		*line = ft_strmdup(rest, endl_found - rest);
		endl_found = ft_strmdup(endl_found + 1, 0);
		free(rest);
		rest = endl_found;
		return (1);
	}
	while ((read_size = read(fd, read_buff, BUFFER_SIZE)) > 0)
	{
		rest = ft_strjoin(rest, read_buff);
		if ((endl_found = endl_check(rest)))
		{
			*line = ft_strmdup(rest, endl_found - rest);
			endl_found = ft_strmdup(endl_found + 1, 0);
			free(rest);
			rest = endl_found;
			return (1);
		}
  	}
	if (read_size < 0)
	//free
		return (-1);
	*line = ft_strmdup(rest, 0);
	rest = NULL;
	return (0);
}
