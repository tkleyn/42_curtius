/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:10:13 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/22 18:10:15 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnjoin3(char *s1, char *s2, size_t size1, size_t size2)
{
	char	*new_str;
	char	*new_str_cpy;
	char	*s1_cpy;

	if (!s2)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	new_str_cpy = new_str;
	s1_cpy = s1;
	while (size1--)
		*new_str_cpy++ = *s1++;
	while (size2--)
		*new_str_cpy++ = *s2++;
	if (s1_cpy)
		free(s1_cpy);
	*new_str_cpy++ = '\0';
	return (new_str);
}
