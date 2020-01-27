/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:25:24 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/27 15:26:09 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conv_p(t_utils *data, t_flags *flgs, char *str)
{
	if (!str)
		return (NULL);
	if (flgs->prec == 0 && str[2] == '0')
	{
		free(str);		
		if (!(str = (ft_strdup("0x"))))
				return (NULL);
	}
	if (flgs->prec > 0 && ft_add_l(&str, flgs->prec, '0', 2) != 0)
		return (NULL);
	if (flgs->width > 0 && !flgs->ljust && !flgs->pad && ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if ((flgs->width < 0 || flgs->ljust) && ft_add_r(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if (flgs->pad && !flgs->ljust && flgs->width > 0 && flgs->prec == -1 
						&& str[2] == '0' && ft_add_r(&str, flgs->width, '0', 0) != 0)
		return (NULL);
	if (flgs->pad && !flgs->ljust && flgs->width > 0 && ft_add_l(&str, flgs->width, ' ', 0) != 0)
    	return (NULL);
	data->size_ret = ft_strlen(str);
	return (str);
}