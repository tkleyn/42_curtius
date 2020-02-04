/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:25:29 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/04 19:29:17 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frintf.h"

char			*conv_pc(t_utils *data, t_flags *flgs, char *str)
{
	if (str && !(str = (ft_strdup(str))))
		return (NULL);
	if (flgs->prec < (int)ft_strlen(str) && flgs->prec > 0 &&
						ft_s_dow(&str, flgs->prec) != 0)
		return (error_free(str));
	if ((flgs->ljust || flgs->width < 0) && flgs->width &&
					ft_add_r(&str, flgs->width, ' ', 0) != 0)
		return (error_free(str));
	if (flgs->pad && flgs->width && ft_add_l(&str, flgs->width, '0', 0) != 0)
		return (error_free(str));
	if (flgs->width >= 0 && ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (error_free(str));
	if (flgs->width < 0 && ft_add_r(&str, flgs->width, ' ', 0) != 0)
		return (error_free(str));
	data->size_ret = ft_strlen(str);
	return (str);
}
