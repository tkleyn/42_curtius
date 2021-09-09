/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:07:30 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:06:04 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char *new_str;
	char *new_cpy;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new_cpy = new_str;
	while (*s1 && size)
	{
		*new_cpy++ = *s1++;
		size--;
	}
	*new_cpy = '\0';
	return (new_str);
}
