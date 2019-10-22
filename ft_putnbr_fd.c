/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:32:46 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/21 15:18:42 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(long num, int fd)
{
	if (num > 9)
		convert(num / 10, fd);
	ft_putchar_fd(num % 10 + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long nb;

	if (fd < 0)
		return ;
	nb = n;
	if (n < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	convert(nb, fd);
}
