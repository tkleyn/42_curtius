/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:05:15 by tkleynts          #+#    #+#             */
/*   Updated: 2019/12/10 17:49:19 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnjoin2(char *s1, char *s2, size_t size)
{
	char	*new_str;
	char	*new_str_cpy;
	char	*s1_cpy;

	if (!s2)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
						+ size + 1))))
		return (NULL);
	new_str_cpy = new_str;
	s1_cpy = s1;
	while (s1 && *s1)
		*new_str_cpy++ = *s1++;
	while (*s2 && size--)
		*new_str_cpy++ = *s2++;
	if (s1_cpy)
		free(s1_cpy);
	*new_str_cpy++ = '\0';
	return (new_str);
}
