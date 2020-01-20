/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:31:36 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/20 19:13:50 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *jean;
	printf("printf :%010.7i\n", 3267);

	ft_printf("frintf :%03.7i\n", 3267);

	// To resolve : 

	// gestion 0x adr
	// taille - %c \0
	// gerer .p = p

}/*



char		*jean(char **str, int width, char c, int len, int w)
{
	char	*tmp;

	width += w;
	if (!(tmp = (char *)malloc(width + 1)))
		return (NULL);
	if (!w && **str == '-' && c == '0')
	w++;
	ft_memset(tmp + w, (int)c, width - len);
	ft_strncpy(&tmp[width - len + w],  (*str + w), len - w);
	return (tmp);
}

int				ft_add_l(char **str, int width, char c, int w)
{
	char		*tmp;
	int			len;
	
	(width < 0) ? (width = -width) : (width = width);
	len = ft_strlen(*str);
	if (len >= width)
		return (0);
	if (**str == '-' && c == '0')
	{
		if(!(tmp = jean(str, width, c, len, w)))
			return (-1);
		*tmp = '-';
	}
	else if (**str == '0' && *(*str + 1) == 'x' && w == 2)
	{
		if(!(tmp = jean(str,width, c, len, w)))
			return (-1);
		*tmp = '0';
		*(tmp + 1) = 'x';
	}
	else if(!(tmp = jean(str,width, c, len, w)))
		return (-1);
	free(*str);
	*str = tmp;
	return (0);
}




*/