/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:03:50 by tkleynts          #+#    #+#             */
/*   Updated: 2020/11/11 12:22:17 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const char *str, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *str);
ssize_t	ft_read(int fd, const char *str, size_t len);

#endif