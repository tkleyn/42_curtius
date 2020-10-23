/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:55:52 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:03:49 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (!(ptr = (void *)malloc(count * size)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
