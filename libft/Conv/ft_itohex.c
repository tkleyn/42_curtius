/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:21:02 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/18 13:30:40 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	get_size(unsigned long long num)
{
	size_t	size;

	size = 0;
	while (num > 0 || size == 0)
	{
		num = num / 16;
		size++;
	}
	return (size);
}

char	*ft_itohex(unsigned long long num, char *base)
{
	char	*string;
	size_t	size;

	size = get_size((unsigned long long)num);
	string = (char *)malloc(size + 1);
	if (!string)
		return (NULL);
	string[size] = '\0';
	while (size)
	{
		string[size - 1] = base[num % 16];
		num = num / 16;
		size--;
	}
	return (string);
}
