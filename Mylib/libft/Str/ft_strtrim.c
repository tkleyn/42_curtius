/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:29:57 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:06:20 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (!s1[i])
		i = j + 1;
	else
		while (j > 0 && ft_strchr(set, s1[j]))
			j--;
	return (ft_strndup(&s1[i], j - (i - 1)));
}
