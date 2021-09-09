/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:39:13 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:04:09 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *b_cpy;

	b_cpy = b;
	while (len)
	{
		*b_cpy = (unsigned char)c;
		b_cpy++;
		len--;
	}
	return (b);
}
