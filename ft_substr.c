/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:53:54 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/21 18:24:39 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(ret = (char *)malloc(sizeof(char))))
			return (NULL);
		return (ret);
	}
	return (ft_strndup(&s[start], len));
}
