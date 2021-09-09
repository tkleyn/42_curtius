/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_diux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:24:35 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/04 19:13:26 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frintf.h"

static int		is_z(char *str)
{
	if (*str == '-')
		str++;
	if (*str == '0')
		return (1);
	return (0);
}

char			*conv_diux(t_utils *data, t_flags *flgs, char *str)
{
	if (!str)
		return (NULL);
	if (flgs->prec == 0 && is_z(str))
	{
		free(str);
		if (!(str = (ft_strdup(""))))
			return (NULL);
	}
	if (flgs->prec > 0 && ft_add_l(&str, flgs->prec, '0', 1) != 0)
		return (error_free(str));
	if (flgs->width > 0 && !flgs->ljust && !flgs->pad &&
				ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (error_free(str));
	if ((flgs->width < 0 || flgs->ljust) &&
						ft_add_r(&str, flgs->width, ' ', 0) != 0)
		return (error_free(str));
	if (flgs->pad && !flgs->ljust && flgs->width > 0 && flgs->prec < 0
					&& ft_add_l(&str, flgs->width, '0', 0) != 0)
		return (error_free(str));
	if (flgs->pad && !flgs->ljust && flgs->width > 0
					&& ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (error_free(str));
	data->size_ret = ft_strlen(str);
	return (str);
}
