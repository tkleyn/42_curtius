/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:07:06 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:04:02 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d_cpy;

	if (!dst && !src)
		return (NULL);
	d_cpy = (char *)dst;
	while (n--)
		*d_cpy++ = *(char *)src++;
	return (dst);
}
