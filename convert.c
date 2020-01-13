/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:11:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/13 15:23:03 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conv_c(t_utils *data, t_flags *flgs, char c)
{
	//only number and *
	return(0);
}

char			*conv_s(t_utils *data, t_flags *flgs, char *str)
{
	if (!str)
		return ("(null)");
	else
		return (ft_strdup(str));
		
}

char			*conv_diu(t_utils *data, t_flags *flgs, char *str)
{
	return(0);
}

char			*conv_x(t_utils *data, t_flags *flgs, char *str)
{
	return(0);
}

char			*conv_p(t_utils *data, t_flags *flgs, char *str)
{
	return(0);
}


ft_add_width(char **str, int width, char c)
{
	char *tmp;

	tmp = (char *)malloc(width + 1);
	

}