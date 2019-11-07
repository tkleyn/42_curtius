/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/07 15:33:45 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE];
	static char		*rest;
	int				read_size;
	char			*endl_found;

	*line = NULL;
	if (rest && (endl_found = endl_check(rest)))
	{
		line = ft_strmdup(endl_found, endl_found - rest);
		endl_found = ft_strmdup(endl_found + 1, 0);
		free(rest);
		rest = endl_found;
		return (1);
	}
	while ((read_size = read(fd, read_buff, BUFFER_SIZE)) < 0)
	{
		
    }

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
	


/*
char	*ft_strjoin(char const *line, char const *buff)
{
	char *new_str;
	char *new_str_cpy;


	if (!line && !buff)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)line)
											+ ft_strlen((char *)buff) + 1))))
		return (NULL);
	new_str_cpy = new_str;
	while (line && *line)
		*new_str_cpy++ = *line++;
	while (buff && *buff)
		*new_str_cpy++ = *buff++;
	if (line)
		free(line);
	*new_str_cpy++ = '\0';
	return (new_str);
}

*/





// char *ft_catalloc(char **line, char *read_buff, int read_size)
// {
// 	char *ptr;
// 	char *ptr_cpy;
// 	char *line_cpy;

// 	line_cpy = *line;
// 	if (!(ptr = malloc(ft_strlen(*line) + read_size + 1)))
// 		return;
// 	ptr_cpy = ptr;
// 	if (*line)
// 	{
// 		while (*line_cpy)
// 			*ptr_cpy++ = *line_cpy++;
// 		free(*line);
// 	}
// 	while (read_size--)
// 	{
// 		*ptr_cpy++ = *read_buff++;
// 	}
// 	return (ptr);
// }