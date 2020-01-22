/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:31:36 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/22 14:31:48 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *jean;
	printf("printf :%.0p\n", 0);

	ft_printf("frintf :%.0p\n", 0);

	// To resolve : 

	// gestion 0x adr
	// taille - %c \0
	// gerer .p = p

}/*


int				ft_add_l(char **str, int width, char c, int w)
{
	char		*tmp;
	int			len;
	
	(width < 0) ? (width = -width) : (width = width);
	len = ft_strlen(*str);
	if (len > width)
		return (0);
	if (**str == '-' && c == '0')
	{
		if (w)
			width++;
		if (!(tmp = (char *)malloc(width + 1)))
			return (-1);
		*tmp = '-';
		ft_memset(tmp + 1, (int)c, width - len);
		ft_strncpy(&tmp[width - len + 1],  (*str + 1), len - 1);
	}
	else if (**str == '0' && *(*str + 1) == 'x' && w == 2)
	{
		width +=2;
		if (!(tmp = (char *)malloc(width + 1)))
			return (-1);
		*tmp = '0';
		*(tmp + 1) = 'x';
		ft_memset(tmp + 2, (int)c, width - len);
		ft_strncpy(&tmp[width - len + 2],  (*str + 2), len - 2);
	}
	else
	{
		if (!(tmp = (char *)malloc(width + 1)))
			return (-1);
		ft_memset(tmp, (int)c, width - len);
		ft_strncpy(&tmp[width - len], *str, len);
	}
	free(*str);
	*str = tmp;
	return (0);
}

*/