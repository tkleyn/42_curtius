/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:11:55 by tkleynts          #+#    #+#             */
/*   Updated: 2019/12/04 17:13:39 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*is_convert(t_utils *data)
{
	char	*to_join;

	if (*data->f_cpy == 'd' || *data->f_cpy == 'i')
		return (itoa(va_arg(data->args, int)));
	else if (*data->f_cpy == 'c')
		return (ctoa(va_arg(data->args, char)));
	else if (*data->f_cpy == 's')
		return (ft_strdup(va_arg(data->args, char *)));
	else if (*data->f_cpy == 'u')
		return (ctoa(va_arg(data->args, unsigned int)));
	else if (*data->f_cpy == 'x' || *data->f_cpy == 'X')
		return (itohex(va_arg(data->args, char)));
	else if (*data->f_cpy == 'p')
		return (ctoa(va_arg(data->args, unsigned long)));
	else
		return (NULL);
}

void			is_flag(t_utils *data)
{
	char	*to_join;

	if(!(to_join = is_convert(data)))
		return (-1);
}

char			*itohex()
{
	
}

char			*ctoa(char *c)
{
	return (ft_strndup(c, 1));
}