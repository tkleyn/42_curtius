/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:05:15 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:06:10 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*ft_strnjoin2(char *s1, char *s2, size_t size1, size_t size2)
{
	char	*new_str;
	char	*new_str_cpy;
	char	*s1_cpy;
	char	*s2_cpy;

	if (!s2)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	new_str_cpy = new_str;
	s1_cpy = s1;
	s2_cpy = s2;
	while (size1--)
		*new_str_cpy++ = *s1++;
	while (size2--)
		*new_str_cpy++ = *s2++;
	if (s1_cpy)
		free(s1_cpy);
	if (s2_cpy)
		free(s2_cpy);
	*new_str_cpy++ = '\0';
	return (new_str);
}
