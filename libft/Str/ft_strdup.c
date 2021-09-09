/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:48:28 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:05:31 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char *new_str;
	char *new_cpy;

	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1))))
		return (0);
	new_cpy = new_str;
	while (*s1)
	{
		*new_cpy = *s1;
		new_cpy++;
		s1++;
	}
	*new_cpy = '\0';
	return (new_str);
}
