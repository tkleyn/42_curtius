/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:48:32 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/12 17:28:51 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


int			get_next_line(int fd, char **line);
char		*endl_check(char *str);
size_t		ft_strlen(const char *str);
char		*ft_strmdup(char *s1, size_t size);
char		*ft_strjoin(char *line, char *buff);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
