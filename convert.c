/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:11:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/20 17:28:44 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conv_c(t_utils *data, t_flags *flgs, char c)
{
	char *str;

	if (!(str = ft_strndup(&c, 1)))
		return (NULL);
	if (flgs->width > 1 && !flgs->ljust && !flgs->pad 
						&& ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if (flgs->width > 1 && flgs->ljust 
						&& ft_add_r(&str, flgs->width, ' ') != 0)
		return (NULL);
	if (flgs->width > 1 && !flgs->ljust && flgs->pad 
						&& ft_add_l(&str, flgs->width, '0', 0) != 0)
		return (NULL);
	return (str);
}

char			*conv_s(t_utils *data, t_flags *flgs, char *str)
{
	int check;

	check = 1;
	if (flgs->prec == 0 && check-- && !(str = (ft_strdup(""))))
		return (NULL);
	if (str && check && !(str = (ft_strdup(str))))
		return (NULL);
	if (!str && check && !(str = (ft_strdup("(null)"))))
		return (NULL);
	if (flgs->prec < ft_strlen(str) && flgs->prec > 0 &&
						ft_s_dow(&str, flgs->prec) != 0)
		return (NULL);
	if (flgs->ljust && flgs->width && ft_add_r(&str, flgs->width, ' ') != 0)
		return (NULL);
	if (flgs->pad && flgs->width && ft_add_l(&str, flgs->width, '0', 0) != 0)
		return (NULL);
	if (flgs->width >= 0 && ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if (flgs->width < 0 && ft_add_r(&str, flgs->width, ' ') != 0)
		return (NULL);
	
	return (str);
}

char			*conv_diux(t_utils *data, t_flags *flgs, char *str)
{
	if (!str)
		return (NULL);
	if (flgs->prec == 0 && (!flgs->width || ft_atoi(str) == 0))
	{
		free(str);		
		if (!(str = (ft_strdup(""))))
				return (NULL);
	}
	if (flgs->prec > 0 && ft_add_l(&str, flgs->prec, '0', 1) != 0)
		return (NULL);
	if (flgs->width > 0 && !flgs->ljust && !flgs->pad && ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if ((flgs->width < 0 || flgs->ljust) && ft_add_r(&str, flgs->width, ' ') != 0)
		return (NULL);
    if (flgs->pad && !flgs->ljust && flgs->width > 0 && flgs->prec == -1 
						&& ft_add_l(&str, flgs->width, '0', 0) != 0)
    	return (NULL);
	if (flgs->pad && !flgs->ljust && flgs->width > 0 && ft_add_l(&str, flgs->width, ' ', 0) != 0)
    	return (NULL);
	return (str);
}

char			*conv_p(t_utils *data, t_flags *flgs, char *str)
{
	if (!str)
		return (NULL);
	if (flgs->prec == 0 && (!flgs->width || ft_atoi(str) == 0))
	{
		free(str);		
		if (!(str = (ft_strdup(""))))
				return (NULL);
	}
	if (flgs->prec > 0 && ft_add_l(&str, flgs->prec, '0', 1) != 0)
		return (NULL);
	if (flgs->width > 0 && !flgs->ljust && !flgs->pad && ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if ((flgs->width < 0 || flgs->ljust) && ft_add_r(&str, flgs->width, ' ') != 0)
		return (NULL);
    if (flgs->pad && !flgs->ljust && flgs->width > 0 && flgs->prec == -1 
						&& ft_add_l(&str, flgs->width, '0', 2) != 0)
    	return (NULL);
	if (flgs->pad && !flgs->ljust && flgs->width > 0 && ft_add_l(&str, flgs->width, ' ', 0) != 0)
    	return (NULL);
	return (str);
}