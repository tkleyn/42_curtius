/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:51:46 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/07 15:20:27 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strmdup(char *s1, size_t size)
{
	char *new_str;
	char *new_cpy;
	char *s1_cpy;
	int free_bool;

	free_bool = 0;
	if (size = 0)
	{
		size = ft_strlen(s1);
		free_bool = 1;
	}
	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new_cpy = new_str;
	s1_cpy = s1;
	while (*s1_cpy && size)
	{
		*new_cpy++ = *s1_cpy++;
		size--;
	}
	*new_cpy = '\0';
	if (free_bool)
		free(s1);
	return (new_str);
}