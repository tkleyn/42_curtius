/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 07:43:57 by tkleynts          #+#    #+#             */
/*   Updated: 2019/12/10 20:37:51 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*pc_find(const char *str)
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
	data.f_cpy = ft_strdup(format);
	data.buff = NULL;
	while ((pc = pc_find(data.f_cpy)))
	{
		data.buff = ft_strnjoin2(data.buff, data.f_cpy, pc - data.f_cpy);
		pc = ft_strdup(++pc);
		data.f_cpy = pc;
		data.buff = ft_strjoin2(data.buff, is_convert(&data));
		data.f_cpy++;//a retirer
	}
	va_end(data.args);
	//data.buff = ft_strjoin2(data.buff, data.f_cpy);
	write(1, data.buff, ft_strlen(data.buff));
	return 1;
}
