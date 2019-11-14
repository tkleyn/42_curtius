/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:48:32 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/14 11:41:32 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t		ft_strlen(const char *str);
char		*endl_check(char *str);
char		*ft_strmdup(char *s1, int size);
char		*ft_strjoin(char *line, char *buff);
int			get_next_line(int fd, char **line);
int			line_packager(char **line, char **rest);
int			ft_desaloc(char **line, char **rest);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#endif
