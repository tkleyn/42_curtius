/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:06:57 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/28 10:07:36 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*rm_spaces(char *str)
{
	char	*str_cpy;
	char	*new_str;
	char	*new_str_cpy;
	int		cnt;

	if (!str)
		return (NULL);
	cnt = 0;
	str_cpy = str;
	while (*str_cpy)
		if (!ft_isspace(*str_cpy++))
			cnt++;
	if (!(new_str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	str_cpy = str;
	new_str_cpy = new_str;
	while (*str_cpy)
	{
		if (!ft_isspace(*str_cpy))
			*new_str_cpy++ = *str_cpy;
		str_cpy++;
	}
	*new_str_cpy = '\0';
	return (new_str);
}
