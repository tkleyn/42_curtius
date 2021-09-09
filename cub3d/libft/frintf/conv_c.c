/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:24:03 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/04 19:13:19 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frintf.h"

char			*conv_c(t_utils *data, t_flags *flgs, char c)
{
	char	*str;
	int		bz_add;

	bz_add = 0;
	(c == '\0') ? (bz_add++) : (bz_add);
	if (!(str = ft_strndup(&c, 1)))
		return (NULL);
	if (flgs->width >= 1 && *str == '\0' && !flgs->ljust)
		flgs->width--;
	if (flgs->width >= 1 && !flgs->ljust && !flgs->pad
						&& ft_add_l(&str, flgs->width, ' ', 0) != 0)
		return (error_free(str));
	if (flgs->width != 0 && (flgs->ljust || flgs->width < 0) &&
		(bz_add += ft_add_r(&str, flgs->width, ' ', bz_add)) == -1)
		return (error_free(str));
	if (flgs->width != 0 && !flgs->ljust && flgs->pad
						&& ft_add_l(&str, flgs->width, '0', 0) != 0)
		return (error_free(str));
	data->size_ret = ft_strlen(str) + bz_add;
	return (str);
}
