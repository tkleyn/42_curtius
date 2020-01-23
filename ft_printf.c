/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 07:43:57 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/22 18:08:31 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	char		*pc;
	t_utils		data;
	int			c_printed;
	size_t		to_print;

	to_print = 0;
	va_start(data.args, format);
	data.f_cpy = ft_strdup(format);
	data.buff = NULL;
	while ((pc = ft_strchr(data.f_cpy, '%')))
	{
		data.buff = ft_strnjoin3(data.buff, data.f_cpy, to_print, pc - data.f_cpy);
		to_print += (pc - data.f_cpy);
		pc = ft_strdup(++pc);
		data.f_cpy = pc;
		if (!(pc = is_flag(&data)))
			return (0);
		data.buff = ft_strnjoin3(data.buff, pc, to_print, data.size_ret);
		to_print += data.size_ret;
	}
	va_end(data.args);
	data.buff = ft_strnjoin3(data.buff, data.f_cpy, to_print, ft_strlen(data.f_cpy));
	to_print += ft_strlen(data.f_cpy);
	c_printed = write(1, data.buff, to_print);
	if (data.buff)
		free(data.buff);
	return (c_printed);
}
