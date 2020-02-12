/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:39:41 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:03:23 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	dividing(unsigned int divider, long num, char *buff_cpy)
{
	int first_num;

	first_num = 0;
	while (divider > 0)
	{
		if (num / divider != 0 || first_num)
		{
			*buff_cpy++ = (num / divider) + '0';
			num = num - (num / divider) * divider;
			first_num = 1;
		}
		divider = divider / 10;
	}
	*buff_cpy = '\0';
}

char		*ft_utoa(unsigned int n)
{
	char			str_buff[12];
	char			*buff_cpy;
	unsigned int	divider;
	long			num;

	num = n;
	divider = 1000000000;
	buff_cpy = str_buff;
	if (num == 0)
		*buff_cpy++ = '0';
	dividing(divider, num, buff_cpy);
	return (ft_strdup(str_buff));
}
