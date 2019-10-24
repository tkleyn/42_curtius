/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:07:29 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/24 13:32:23 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*liste2;
	t_list	*new_elem;

	liste2 = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&liste2, new_elem);
		lst = lst->next;
	}
	return (liste2);
}
