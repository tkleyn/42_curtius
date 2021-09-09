/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frintf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 07:43:57 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/18 14:49:26 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frintf.h"

int	free_struct(t_utils *d, int c_printed)
{
	if (d)
	{
		if (d->buff)
			free(d->buff);
		if (d->f_cpy)
			free(d->f_cpy);
		d->f_cpy = NULL;
		d->buff = NULL;
		va_end(d->args);
	}
	return (c_printed);
}

int	check_pc(t_utils *d, char *pc, size_t *to_print)
{
	d->buff = ft_strnjoin(d->buff, d->f_cpy, *to_print, pc - d->f_cpy);
	if (!d->buff)
		return (0);
	*to_print += (pc - d->f_cpy);
	pc = ft_strdup(++pc);
	if (!pc)
		return (0);
	free(d->f_cpy);
	d->f_cpy = pc;
	pc = is_flag(d);
	if (!pc)
		return (0);
	d->buff = ft_strnjoin2(d->buff, pc, *to_print, d->size_ret);
	if (!d->buff)
		return (0);
	*to_print += d->size_ret;
	return (1);
}

int	frintf(const char *format, ...)
{
	char		*pc;
	t_utils		d;
	size_t		to_print;

	to_print = 0;
	va_start(d.args, format);
	d.f_cpy = ft_strdup(format);
	if (!d.f_cpy)
		return (0);
	d.buff = NULL;
	pc = ft_strchr(d.f_cpy, '%');
	while (pc)
	{
		if (!(check_pc(&d, pc, &to_print)))
			return (free_struct(&d, 0));
		pc = ft_strchr(d.f_cpy, '%');
	}
	d.buff = ft_strnjoin(d.buff, d.f_cpy, to_print, ft_strlen(d.f_cpy));
	if (!d.buff)
		return (free_struct(&d, 0));
	return (free_struct(&d, write(1, d.buff, to_print += ft_strlen(d.f_cpy))));
}
