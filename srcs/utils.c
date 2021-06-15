/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:03:53 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/14 13:04:57 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	ft_fatoi(const char	*str, uint8_t	*flag)
{
	uint64_t	number;
	int			sign;

	*flag = 0;
	sign = 1;
	number = 0;
	while (*str == '\r' || *str == '\f' || *str == '\n' || *str == '\v'
		|| *str == '\t' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str++ - '0');
		if ((number > INT32_MAX && sign == 1)
			|| (number > (uint64_t)INT32_MAX + 1 && sign == -1))
			return (*flag = 1);
	}
	if (*str != '\0')
		return (*flag = 1);
	return ((int)(number * sign));
}