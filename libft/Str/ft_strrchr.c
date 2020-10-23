/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:18:13 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:06:17 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *return_val;

	return_val = NULL;
	while (*str)
	{
		if (*str == (char)c)
			return_val = (char *)str;
		str++;
	}
	if (*str == (char)c)
		return_val = (char *)str;
	return (return_val);
}
