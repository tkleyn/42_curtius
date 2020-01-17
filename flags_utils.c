/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:14:00 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/16 14:28:31 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_add_l(char **str, int width, char c)
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
		width++;
		if (!(tmp = (char *)malloc(width + 1)))
			return (-1);
		*tmp = '-';
		ft_memset(tmp + 1, (int)c, width - len);
		ft_strncpy(&tmp[width - len + 1],  (*str + 1), len - 1);
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
