/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/04 18:28:50 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
    static char read_buff[BUFFER_SIZE];
    int read_size;

    *line = NULL;
	//copy read_buff -> line
    while (/* condition */)
    {
        if ((read_size = read(fd, read_buff, BUFFER_SIZE)) < 0)
			return (NULL);

        

    }
    


}

char	*ft_catalloc(char **line, char *read_buff, int read_size)
{
    char *ptr;
    char *ptr_cpy;
	char *line_cpy;

    line_cpy = *line;
   	if (!(ptr = malloc(ft_strlen(*line) + read_size + 1)))
    	return ;
    ptr_cpy = ptr;
	if (*line)
	{
		while (*line_cpy)
      	  *ptr_cpy++ = *line_cpy++;
		free(*line);
	}
    while (read_size--)
    {
        *ptr_cpy++ = *read_buff++;
    }
	return (ptr);
    
}


while (i < BUFFER_SIZE && read_buff[i] != '\n')
            i++;
        
        //if \n
            //*line = ....
            //remove line from read_buff and malloc it in read_buff
            //return (1);





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
	



char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new_str;
	char *new_str_cpy;


	if (!s1 && !s2)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
											+ ft_strlen((char *)s2) + 1))))
		return (NULL);
	new_str_cpy = new_str;
	while (*s1)
		*new_str_cpy++ = *s1++;
		
	free(s1);
	
	return (new_str);
}

int endl_check(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}


if (endl_check(read_buff))
{

}