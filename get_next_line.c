/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/30 17:22:09 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char read_buff[BUFFER_SIZE];
    int i;

    *line = NULL;
    while (/* condition */)
    {
        i = 0;

        if (!read(fd, read_buff, BUFFER_SIZE))

        while (i < BUFFER_SIZE && read_buff[i] != '\n')
            i++;
        
        //if \n
            //*line = strndup(read_buff, i);
            //remove line from read_buff and malloc it in read_buff
            return (1);

    }
    


}

ft_catalloc(char **line, char *read_buff, int i)
{
    char *ptr;
    char *ptr_cpy;

    
   if (!(ptr = malloc(ft_strlen(**line) + i + 1)))
    return ;
    ptr_cpy = ptr;
    while (line_cpy && *line_cpy)
    {
        *ptr_cpy++ = *line_cpy++;
    }
    while (i--)
    {
        *ptr_cpy++ = *read_buff_cpy++;
    }
    
}


