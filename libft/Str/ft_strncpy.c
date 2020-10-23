/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:30:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:06:01 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *dst;

	if (!dest || !src)
		return (NULL);
	dst = dest;
	while (*src && len)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	*dst = '\0';
	return (dest);
}
