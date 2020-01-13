/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:45:33 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/13 16:49:53 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*is_flag(t_utils *data)
{
	char		*f_work;
	t_flags		flgs;
	
	flgs.width = 0;
	f_work = data->f_cpy;
	if (*f_work && *f_work == '-' && f_work++)
		flgs.ljust = 1;
	if (*f_work && *f_work == '0' && f_work++)
		flgs.pad = 1;
	while (*f_work && ft_isdigit(*f_work))
		flgs.width = (flgs.width * 10) + (*f_work++ - '0');
	if (*f_work && *f_work == '*' && flgs.width == 0 && f_work++)
		flgs.width = va_arg(data->args, int);
	if (*f_work && *f_work == '.' && f_work++)
		while (*f_work && ft_isdigit(*f_work))
			flgs.prec = (flgs.prec * 10) + (*f_work++ - '0');
	if (*f_work && *f_work == '*' && flgs.prec == 0 && f_work++)
		flgs.prec = va_arg(data->args, int);
	f_work = ft_strdup(f_work);
	free(data->f_cpy);
	data->f_cpy = f_work;
	return (is_convert(data, &flgs));
}

char					*is_convert(t_utils *data, t_flags *flgs)
{
	char		*r;
	char		*f_work;
	
	if (*data->f_cpy == 'd' || *data->f_cpy == 'i')
		r = (conv_diu(data, flgs, ft_itoa(va_arg(data->args, int))));
	else if (*data->f_cpy == 'c')
		r = (conv_c(data, flgs, (char)va_arg(data->args, int)));
	else if (*data->f_cpy == 's')
		r = (conv_s(data, flgs, va_arg(data->args, char *)));
	else if (*data->f_cpy == 'u')
		r = (conv_diu(data, flgs, ft_utoa(va_arg(data->args, UI))));
	else if (*data->f_cpy == 'x')
		r = (conv_x(data, flgs, itohex(va_arg(data->args, int), X_MIN)));
	else if (*data->f_cpy == 'X')
		r = (conv_x(data, flgs, itohex(va_arg(data->args, int), X_MAJ)));
	else if (*data->f_cpy == 'p')
		r = (conv_p(data, flgs, ptohex(va_arg(data->args, UL), X_MIN)));
	else
		r = (NULL);
	f_work = ft_strdup(data->f_cpy + 1);
	free(data->f_cpy);
	data->f_cpy = f_work;
	return (r);
}
