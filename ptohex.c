/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:20:02 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/22 16:01:06 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			get_size(unsigned long long num)
{
	size_t	size;

	size = 0;
	while (num >= 1 || size == 0)
	{
		num = num / 16;
		size++;
	}
	return (size + 2);
}

char					*ptohex(unsigned long long num, char *base)
{
	char	*string;
	size_t	size;
	size = get_size(num);
	string = (char *)malloc(size + 1);
	string[0] = '0';
	string[1] = 'x';
	string[size] = '\0';
	while (size > 2)
	{
		string[size - 1] = base[num % 16];
		num = num / 16;
		size--;
	}
	return (string);
}
