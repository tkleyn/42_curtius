/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:25:26 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:05:15 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *str;

	if (!dest || !src)
		return (NULL);
	str = dest;
	while (*str)
		str++;
	while (*src)
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';
	return (dest);
}
