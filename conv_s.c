/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:25:06 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/27 16:04:09 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conv_s(t_utils *data, t_flags *flgs, char *str)
{
	int check;

	check = 1;
	if (flgs->prec == 0 && ft_strncmp(str, "%", 2) && check--
						&& !(str = (ft_strdup(""))))
		return (NULL);
	if (str && check && !(str = (ft_strdup(str))))
		return (NULL);
	if (!str && check && !(str = (ft_strdup("(null)"))))
		return (NULL);
	if (flgs->prec < ft_strlen(str) && flgs->prec > 0 &&
						ft_s_dow(&str, flgs->prec) != 0)
		return (NULL);
	if (flgs->ljust && flgs->width && ft_add_r(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if (flgs->pad && flgs->width && ft_add_l(&str, flgs->width, '0', 0) != 0)
		return (NULL);
	if (flgs->width >= 0 && ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if (flgs->width < 0 && ft_add_r(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	data->size_ret = ft_strlen(str);
	return (str);
}
