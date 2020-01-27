/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 07:43:57 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/27 18:26:18 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		free_struct(t_utils *d, int c_printed)
{
	if (d)
	{
		if (d->buff)
			free(d->buff);
		if (d->f_cpy)
			free(d->f_cpy);
	}
	return (c_printed);
}

int				ft_printf(const char *format, ...)
{
	char		*pc;
	int			c_printed;
	t_utils		d;
	size_t		to_print;

	to_print = 0;
	va_start(d.args, format);
	if (!(d.f_cpy = ft_strdup(format)))
		return (0);
	d.buff = NULL;
	while ((pc = ft_strchr(d.f_cpy, '%')))
	{
		d.buff = ft_strnjoin(d.buff, d.f_cpy, to_print, pc - d.f_cpy);
		to_print += (pc - d.f_cpy);
		pc = ft_strdup(++pc);
		free(d.f_cpy);
		d.f_cpy = pc;
		if (!(pc = is_flag(&d)))
			return (free_struct(&d, 0));
		d.buff = ft_strnjoin2(d.buff, pc, to_print, d.size_ret);
		to_print += d.size_ret;
	}
	va_end(d.args);
	d.buff = ft_strnjoin(d.buff, d.f_cpy, to_print, ft_strlen(d.f_cpy));
	return (free_struct(&d, write(1, d.buff, to_print += ft_strlen(d.f_cpy))));
}
