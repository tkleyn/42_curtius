/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffrintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:11:05 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/18 14:38:46 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frintf.h"

int	ffrintf(int fd, const char *format, ...)
{
	char		*pc;
	t_utils		d;
	size_t		to_print;

	if (fd < 0)
		return (-1);
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
	return (free_struct(&d, write(fd, d.buff, to_print += ft_strlen(d.f_cpy))));
}
