/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:51:46 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/21 17:39:09 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*endl_check(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

size_t			ft_strlen(const char *str)
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

char			*ft_strmdup(char *s1, int size)
{
	char	*new_str;
	char	*new_cpy;
	char	*s1_cpy;

	if (size < 0)
		size = ft_strlen(s1);
	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new_cpy = new_str;
	s1_cpy = s1;
	while (s1 && *s1_cpy && size)
	{
		*new_cpy++ = *s1_cpy++;
		size--;
	}
	*new_cpy = '\0';
	return (new_str);
}

char			*ft_strjoin(char *line, char *buff)
{
	char	*new_str;
	char	*new_str_cpy;
	char	*line_cpy;

	if (!line && !buff)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)line)
										+ ft_strlen((char *)buff) + 1))))
		return (NULL);
	new_str_cpy = new_str;
	line_cpy = line;
	while (line && *line)
		*new_str_cpy++ = *line++;
	while (buff && *buff)
		*new_str_cpy++ = *buff++;
	if (line)
		free(line_cpy);
	*new_str_cpy++ = '\0';
	return (new_str);
}

int				ft_desaloc(char **rest)
{
	if (rest && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (-1);
}
