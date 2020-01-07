/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:11:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/07 14:48:23 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ctoa(char c)
{
	return (ft_strndup(&c, 1));
}

static char			*atoa(char *str)
{
	if (str)
		return (ft_strdup(str));
	return (ft_strdup("(null)"));
}

char				*is_convert(t_utils *data)
{
	if (*data->f_cpy == 'd' || *data->f_cpy == 'i')
		return (ft_itoa(va_arg(data->args, int)));
	else if (*data->f_cpy == 'c')
		return (ctoa((char)va_arg(data->args, int)));
	else if (*data->f_cpy == 's')
		return (atoa(va_arg(data->args, char *)));
	else if (*data->f_cpy == 'u')
		return (ft_utoa(va_arg(data->args, unsigned int)));
	else if (*data->f_cpy == 'x')
		return (itohex(va_arg(data->args, int), "0123456789abcdef"));
	else if (*data->f_cpy == 'X')
		return (itohex(va_arg(data->args, int), "0123456789ABCDEF"));
	else if (*data->f_cpy == 'p')
		return (ptohex(va_arg(data->args, unsigned long), "0123456789abcdef"));
	else
		return (NULL);
}
