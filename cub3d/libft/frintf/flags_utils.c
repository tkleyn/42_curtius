/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:14:00 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/04 19:29:47 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frintf.h"

static char		*add_l_utils(char **str, int width, char c, int w)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*str);
	width += w;
	if (!(tmp = (char *)malloc(width + 1)))
		return (NULL);
	if (!w && **str == '-' && c == '0')
		w++;
	ft_memset(tmp + w, (int)c, width - len);
	ft_strncpy(&tmp[width - len + w], (*str + w), len - w);
	return (tmp);
}

int				ft_add_l(char **str, int width, char c, int w)
{
	char		*tmp;
	int			len;

	(width < 0) ? (width = -width) : (width);
	len = ft_strlen(*str);
	if (len >= width + w)
		return (0);
	if (**str == '-' && c == '0')
	{
		if (!(tmp = add_l_utils(str, width, c, w)))
			return (-1);
		*tmp = '-';
	}
	else if (**str == '0' && *(*str + 1) == 'x' && w == 2)
	{
		if (!(tmp = add_l_utils(str, width, c, w)))
			return (-1);
		*tmp = '0';
		*(tmp + 1) = 'x';
	}
	else if (!(tmp = add_l_utils(str, width, c, 0)))
		return (-1);
	free(*str);
	*str = tmp;
	return (0);
}

int				ft_add_r(char **str, int width, char c, int is_z)
{
	char		*tmp;
	int			len;

	if (width < 0)
		width = -width;
	if (is_z)
		len = 1;
	else
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
	return ((is_z) ? (width - len) : (0));
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
