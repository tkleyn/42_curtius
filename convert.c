/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:11:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/09 16:16:55 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*conv_c(t_utils *data, t_flags *flgs, char *str)
{

}

static char			*conv_s(t_utils *data, t_flags *flgs, char *str)
{
	if (!str)
		ft_strjoin(data->buff, "(null)");
}

static char			*conv_diu(t_utils *data, t_flags *flgs, char *str)
{

}

static char			*conv_x(t_utils *data, t_flags *flgs, char *str)
{

}

static char			*conv_p(t_utils *data, t_flags *flgs, char *str)
{

}

void				is_convert(t_utils *data, t_flags *flgs)
{
	if (*data->f_cpy == 'd' || *data->f_cpy == 'i')
		conv_diu(data, flgs, ft_itoa(va_arg(data->args, int)));
	else if (*data->f_cpy == 'c')
		conv_c(data, flgs, (char)va_arg(data->args, int));
	else if (*data->f_cpy == 's')
		conv_s (data, flgs, va_arg(data->args, char *));
	else if (*data->f_cpy == 'u')
		conv_diu (data, flgs, ft_utoa(va_arg(data->args, unsigned int)));
	else if (*data->f_cpy == 'x')
		conv_x (data, flgs, itohex(va_arg(data->args, int), "0123456789abcdef"));
	else if (*data->f_cpy == 'X')
		conv_x (data, flgs, itohex(va_arg(data->args, int), "0123456789ABCDEF"));
	else if (*data->f_cpy == 'p')
		conv_p(data, flgs, va_arg(data->args, unsigned long), "0123456789abcdef");
}
