/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:11:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/24 14:20:44 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int is_z(char	*str)
{
	if(*str == '-')
		str++;
	if(*str == '0')
		return (1);
	return (0);
}

char			*conv_c(t_utils *data, t_flags *flgs, char c)
{
	char *str;
	int bz_add;

	bz_add = 0;
	(c == '\0') ? (bz_add++) : (bz_add);
	if (!(str = ft_strndup(&c, 1)))
		return (NULL);
	if (flgs->width > 1 && *str == '\0' && !flgs->ljust)
		flgs->width--;
	if (flgs->width > 1 && !flgs->ljust && !flgs->pad 
						&& ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if (flgs->width > 1 && flgs->ljust && 
		(bz_add += ft_add_r(&str, flgs->width, ' ', bz_add)) == -1)
		return (NULL);
	if (flgs->width > 1 && !flgs->ljust && flgs->pad 
						&& ft_add_l(&str, flgs->width, '0', 0) != 0)
		return (NULL);
	data->size_ret = ft_strlen(str) + bz_add;
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
		return (NULL);
	if (flgs->width > 0 && !flgs->ljust && !flgs->pad && ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
	if ((flgs->width < 0 || flgs->ljust) && ft_add_r(&str, flgs->width, ' ', 0) != 0)
		return (NULL);
    if (flgs->pad && !flgs->ljust && flgs->width > 0 && flgs->prec < 0 
						&& ft_add_l(&str, flgs->width, '0', 0) != 0)
    	return (NULL);
	if (flgs->pad && !flgs->ljust && flgs->width > 0 && ft_add_l(&str, flgs->width, ' ', 0) != 0)
    	return (NULL);
	data->size_ret = ft_strlen(str);
	return (str);
}

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