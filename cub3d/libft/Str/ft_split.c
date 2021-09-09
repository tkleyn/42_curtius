/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:39:58 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/12 17:04:47 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char		**desaloc(char **tab, int allocated)
{
	while (0 < allocated--)
		free(tab[allocated]);
	free(tab);
	return (NULL);
}

static char		**tab_fill(char **tab, const char *str, char c, int size)
{
	int		i;
	int		j;
	int		allocated;

	allocated = 0;
	i = 0;
	while (size > 0)
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		j = i;
		while (str[j] != c && str[j] != '\0')
			j++;
		if (!(tab[allocated++] = ft_strndup(&str[i], j - i)))
			return (desaloc(tab, allocated));
		size--;
		i = j;
	}
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	*str;
	int		size;
	char	**tab;

	if (!s)
		return (NULL);
	str = (char *)s;
	size = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			continue;
		}
		size++;
		while (*str && *str != c)
			str++;
	}
	if (!(tab = (char**)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	tab[size] = 0;
	return (tab_fill(tab, s, c, size));
}
