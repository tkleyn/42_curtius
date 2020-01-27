/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 07:43:57 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/27 17:25:46 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	char		*pc;
	int			c_printed;
	t_utils		data;
	size_t		to_print;

	to_print = 0;
	va_start(data.args, format);
	if (!(data.f_cpy = ft_strdup(format)))
		return (0);
	data.buff = NULL;
	while ((pc = ft_strchr(data.f_cpy, '%')))
	{
		data.buff = ft_strnjoin(data.buff, data.f_cpy, to_print, pc - data.f_cpy);
		to_print += (pc - data.f_cpy);
		pc = ft_strdup(++pc);
		free(data.f_cpy);
		data.f_cpy = pc;
		if (!(pc = is_flag(&data)))
			return (0);
		data.buff = ft_strnjoin2(data.buff, pc, to_print, data.size_ret);
		to_print += data.size_ret;
	}
	va_end(data.args);
	data.buff = ft_strnjoin(data.buff, data.f_cpy, to_print, ft_strlen(data.f_cpy));
	to_print += ft_strlen(data.f_cpy);
	c_printed = write(1, data.buff, to_print);
	if (data.buff)
		free(data.buff);
	if (data.f_cpy)
		free(data.f_cpy);
	return (c_printed);
}
