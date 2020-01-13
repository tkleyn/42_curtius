/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:11:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/13 17:08:56 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int				ft_add_width(char **str, int width, char c)
{
	char		*tmp;
	int			len;

	len = ft_strlen(*str);
	if (len >= width)
		return (0);
	if(!(tmp = (char *)malloc(width + 1)))
		return (-1);
	ft_memset(tmp, (int)c, width - len);
	ft_strncpy(&tmp[ width - len], *str, len);
	free(*str);
	*str = tmp;
	return (0);
}

char			*conv_c(t_utils *data, t_flags *flgs, char c)
{
	char *str;
	str = ft_strndup(&c, 1);
	if (flgs->width > 1 && ft_add_width(&str, flgs->width, ' ') != 0)
		return (NULL);
	else
		return (str);
}

char			*conv_s(t_utils *data, t_flags *flgs, char *str)
{
	if (!str)
		return ("(null)");
	else
		return (ft_strdup(str));
		
}

char			*conv_diu(t_utils *data, t_flags *flgs, char *str)
{
	return(0);
}

char			*conv_x(t_utils *data, t_flags *flgs, char *str)
{
	return(0);
}

char			*conv_p(t_utils *data, t_flags *flgs, char *str)
{
	return(0);
}
