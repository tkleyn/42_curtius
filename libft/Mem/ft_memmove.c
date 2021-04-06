/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:07:10 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:04:05 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_c;
	unsigned char	*dst_c;
	int				i;

	if (!dst || !src || !len)
		return (dst);
	src_c = (unsigned char *)src;
	dst_c = dst;
	i = 1;
	if (src < dst)
	{
		src_c = (unsigned char *)&src[len - 1];
		dst_c = (unsigned char *)&dst[len - 1];
		i = -1;
	}
	while (len)
	{
		*dst_c = *src_c;
		len--;
		dst_c = dst_c + i;
		src_c = src_c + i;
	}
	return (dst);
}
