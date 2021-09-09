/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:20:00 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:05:41 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				src_len;
	size_t				dst_len;
	size_t				cpt;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	cpt = dst_len;
	if (!size)
		return (src_len);
	dst = &dst[dst_len];
	while (*src && cpt < size - 1)
	{
		*dst++ = *src++;
		cpt++;
	}
	*dst = '\0';
	if (size < dst_len)
		return (src_len + size);
	return (src_len + dst_len);
}
