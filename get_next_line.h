/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:48:32 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/30 11:50:29 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>

int get_next_line(int fd, char **line);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif 
