/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:10:13 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/21 14:09:26 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (number > 2147483647 && sign == 1)
			return (-1);
		else if (number > 2147483648 && sign == -1)
			return (0);
	}
	return (number * sign);
}
