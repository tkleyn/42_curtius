/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:15:15 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/29 18:23:10 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	char	*new_str_cpy;
	char	*s1_cpy;
	char	*s2_cpy;

	if (!s2)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
						+ ft_strlen((char *)s2) + 1))))
		return (NULL);
	new_str_cpy = new_str;
	s1_cpy = s1;
	s2_cpy = s2;
	while (s1 && *s1)
		*new_str_cpy++ = *s1++;
	while (s2 && *s2)
		*new_str_cpy++ = *s2++;
	*new_str_cpy++ = '\0';
	if (s1)
		free(s1_cpy);
	return (new_str);
}
