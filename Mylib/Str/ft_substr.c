/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:53:54 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/18 14:18:52 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ret = (char *)malloc(sizeof(char));
		if (!ret)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	return (ft_strndup(&s[start], len));
}
