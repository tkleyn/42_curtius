/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:45:33 by tkleynts          #+#    #+#             */
/*   Updated: 2019/12/11 16:36:49 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			is_flag(t_utils *data, t_flags *flgs)
{
	char		*f_work;

	//set struct to 0
	f_work = data->f_cpy;
	if (f_work && *f_work == '0')
	{
		flgs->pad = 1;
		f_work++;
	}
	while (*f_work && !(check_conversion(*f_work)))
	{
		
	}
}

int				check_conversion(char c)
{
	char		*c_set;
	int			i;

	c_set = ft_strdup("discxXpu");
	i = 0;

	while (i < 8)
	{
		if (c != c_set[i])
			i++;
		else
			break;
	}
	free(c_set);
	return (i != 8);
}
