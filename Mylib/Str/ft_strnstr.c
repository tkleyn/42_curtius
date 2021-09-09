/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:13:21 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:06:13 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay_cpy;
	char	*n_cpy;
	size_t	len_cpy;

	if (!needle || !*needle)
		return ((char *)haystack);
	while (len && *haystack)
	{
		hay_cpy = (char *)haystack;
		n_cpy = (char *)needle;
		len_cpy = len;
		while (*hay_cpy == *n_cpy && len_cpy)
		{
			n_cpy++;
			if (!*n_cpy)
				return ((char *)haystack);
			hay_cpy++;
			len_cpy--;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
