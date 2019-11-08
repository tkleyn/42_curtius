/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/08 15:44:02 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest;
	int				read_size;
	char			*endl_found;

	*line = NULL;
	if (rest && (endl_found = endl_check(rest)))
	{
		line = ft_strmdup(rest, endl_found - rest);
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
			/* code */
		}
		
		
  }
	if (read_size == 0)
		
	

}

	//check \n static read_buff
		//fct(line, readbuff, size) copie/malloc size elem of readbuff into *line
		//strcpy(readbuff, readbuff[size - 1])
		//return ()
	//malloc/cpy read_buff to line

	//while (read())
	//{
		//if \n 
			//malloc(size line + counter)
			//cpy line and counter elem of read_buff
			//free line 
			//line = ptr
			//srtrcpy(read_buff, readbuff[counter])
			//return ()
	//}
