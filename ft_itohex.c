/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:56:45 by tkleynts          #+#    #+#             */
/*   Updated: 2019/12/06 16:38:44 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			get_size(unsigned int num)
{
	size_t	size;

	size = 0;
	while(num > 0 || size == 0)
	{
		num = num / 16;
		size++;
	}
	return (size);
}

char			*ft_itohex(int num, char *base)
{
	char	*string;
	size_t	size;

	size = get_size((unsigned int)num);
	string = (char *)malloc(size + 1);
	string[size] = '\0';
	while (size)
	{
		string[size - 1] = base[num % 16];
		num = num / 16;
		size--;
	}
	return string;
	
}
