/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:10:13 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/02 15:06:29 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;

	sign = 1;
	while (*str == '\r' || *str == '\f' || *str == '\n' || *str == '\v'
		|| *str == '\t' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str++ - '0');
		if (number > 9223372036854775807)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
	}
	return ((int)(number * sign));
}
