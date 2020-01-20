/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:14:00 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/20 19:16:09 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_add_l(char **str, int width, char c, int w)
{
	char		*tmp;
	int			len;
	
	if (width < 0)
		width = -width;
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

int				ft_add_r(char **str, int width, char c)
{
	char		*tmp;
	int			len;


	if (width < 0)
		width = -width;
	len = ft_strlen(*str);
	if (len >= width)
		return (0);
	if (!(tmp = (char *)malloc(width + 1)))
		return (-1);
	ft_strncpy(tmp, *str, len);
	ft_memset(&tmp[len], (int)c, width - len);
	tmp[width] = '\0';
	free(*str);
	*str = tmp;
	return (0);
}

int				ft_s_dow(char **str, int prec)
{
	char		*tmp;

	if (!(tmp = ft_strndup(*str, prec)))
		return (-1);
	if (*str)
		free(*str);
	*str = tmp;
	return (0);
}
