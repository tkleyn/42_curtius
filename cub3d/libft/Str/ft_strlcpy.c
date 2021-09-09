/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:32:15 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:05:45 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char *src_cpy;

	src_cpy = (char *)src;
	while (size && size - 1 && *src)
	{
		*dst++ = *src++;
		size--;
	}
	if (size)
		*dst = '\0';
	return (ft_strlen(src_cpy));
}
