/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:45:33 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/09 16:17:57 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*is_flag(t_utils *data, t_flags *flgs)
{
	char		*f_work;

	f_work = data->f_cpy;
	if (*f_work && *f_work == '-' && f_work++)
		flgs->ljust = 1;
	if (*f_work && *f_work == '0' && f_work++)
		flgs->pad = 1;
	while (*f_work && ft_isnum(*f_work))
		flgs->width = (flgs->width * 10) + (*f_work++ - '0');
	if (*f_work && *f_work == '*' && flgs->width == 0 && f_work++)
			flgs->width = va_arg(data->args, int);
	if (*f_work && *f_work == '.' && f_work++)
		while (*f_work && ft_isnum(*f_work))
			flgs->prec = (flgs->prec * 10) + (*f_work++ - '0');
	if (*f_work && *f_work == '*' && flgs->prec == 0 && f_work++)
			flgs->prec = va_arg(data->args, int);
	f_work = ft_strdup(f_work);
	free(data->f_cpy);
	data->f_cpy = f_work;
	is_convert(data, flgs);
}
