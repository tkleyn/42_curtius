/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 07:43:57 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/29 14:05:50 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			is_convert(t_utils *data)
{
	return ;
}

void			is_flag(t_utils *data)
{
	is_convert(data);
}

char			*pc_find(const char *str)
{
	while (str && *str)
	{
		if (*str == '%')
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int				ft_printf(const char *format, ...)
{
	char		*pc;
	t_utils		data;

	va_start(data.args, format);
	data.f_cpy = strdup(format);
	data.to_print = NULL;
	while ((pc = pc_find(data.f_cpy)))
	{
		ft_strnjoin2(data.to_print, data.f_cpy, pc - data.f_cpy);
		pc = strdup(pc);
		free(data.f_cpy);
		data.f_cpy = pc;
		is_flag(&data);
	}
	va_end(data.args);
	ft_strjoin2(data.to_print, data.f_cpy);
	write(1, data.to_print, ft_strlen(data.to_print));
	return 1;
}
