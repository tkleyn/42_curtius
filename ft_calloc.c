/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:55:52 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/24 10:18:33 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (count < 1 || size < 1)
		return (NULL);
	if (!(ptr = (void *)malloc(count * size)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
