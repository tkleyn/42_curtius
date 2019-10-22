/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:07:29 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/22 15:11:18 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*liste2;
	t_list	*new_elem;

	liste2 = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!(new_elem = (*f)(lst->content)))
		{
			ft_lstclear(&liste2, del);
			return (NULL);
		}
		ft_lstadd_back(&liste2, new_elem);
		lst = lst->next;
	}
	return (liste2);
}
