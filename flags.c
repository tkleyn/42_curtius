/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:45:33 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/27 14:00:30 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				flgs_set(t_flags *flgs)
{
	flgs->ljust = 0;
	flgs->pad = 0;
	flgs->prec = -1;
	flgs->width = 0;
}

static int skip_atoi(char **s)
{
	int i;
	
	i = 0;
	while (ft_isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return i;
}

static char				*is_convert(t_utils *data, t_flags *flgs)
{
	char		*r;
	char		*f_work;

	if (*data->f_cpy == 'd' || *data->f_cpy == 'i')
		r = (conv_diux(data, flgs, ft_itoa(va_arg(data->args, int))));
	else if (*data->f_cpy == 'c')
		r = (conv_c(data, flgs, (char)va_arg(data->args, int)));
	else if (*data->f_cpy == 's')
		r = (conv_s(data, flgs, va_arg(data->args, char *)));
	else if (*data->f_cpy == 'u')
		r = (conv_diux(data, flgs, ft_utoa(va_arg(data->args, t_ui))));
	else if (*data->f_cpy == 'x')
		r = (conv_diux(data, flgs, itohex(va_arg(data->args, t_ui), X_MIN)));
	else if (*data->f_cpy == 'X')
		r = (conv_diux(data, flgs, itohex(va_arg(data->args, t_ui), X_MAJ)));
	else if (*data->f_cpy == 'p')
		r = (conv_p(data, flgs, ptohex((t_ull)va_arg(data->args, void *), X_MIN)));
	else if (*data->f_cpy == '%')
		r = (conv_pc(data, flgs, "%"));
	else
		return (NULL);
	if (!(f_work = ft_strdup(data->f_cpy + 1)))
		return (NULL);
	free(data->f_cpy);
	data->f_cpy = f_work;
	return (r);
}

char					*is_flag(t_utils *data)
{
	char		*f_work;
	t_flags		flgs;
	int			ret;

	flgs_set(&flgs);
	f_work = data->f_cpy;
	while (*f_work && *f_work == '-' && f_work++)
		(flgs.ljust = 1);
	while (*f_work && *f_work == '0' && f_work++)
		(flgs.pad = 1);
	while (*f_work && *f_work == '-' && f_work++)
		(flgs.ljust = 1);
	flgs.width = skip_atoi(&f_work);
	if (*f_work && *f_work == '*' && flgs.width == 0 && f_work++)
		flgs.width = va_arg(data->args, int);
	((ret = skip_atoi(&f_work)) != 0) ? (flgs.width = ret) : (flgs.width);
	if (*f_work && *f_work == '.' && f_work++)
		flgs.prec = skip_atoi(&f_work);
	if (*f_work && *f_work == '*' && flgs.prec == 0 && f_work++)
		flgs.prec = va_arg(data->args, int);
	f_work = ft_strdup(f_work);
	free(data->f_cpy);
	data->f_cpy = f_work;
	return (is_convert(data, &flgs));
}
