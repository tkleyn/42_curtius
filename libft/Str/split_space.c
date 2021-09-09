/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:18:59 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/18 14:18:24 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**desaloc(char **tab, int allocated)
{
	while (0 < allocated--)
		free(tab[allocated]);
	free(tab);
	return (NULL);
}

static char	**tab_fill(char **tab, const char *str, int size)
{
	int		i;
	int		j;
	int		allocated;

	allocated = 0;
	i = 0;
	while (size > 0)
	{
		while (ft_isspace(str[i]) && str[i] != '\0')
			i++;
		j = i;
		while ((!ft_isspace(str[j])) && str[j] != '\0')
			j++;
		tab[allocated] = ft_strndup(&str[i], j - i);
		if (!tab[allocated++])
			return (desaloc(tab, allocated));
		size--;
		i = j;
	}
	return (tab);
}

char	**split_space(char const *s)
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
		if (ft_isspace(*str))
		{
			str++;
			continue ;
		}
		size++;
		while (*str && (!ft_isspace(*str)))
			str++;
	}
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = 0;
	return (tab_fill(tab, s, size));
}
