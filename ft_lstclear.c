/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:07:06 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/17 15:06:16 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *elem;
	t_list *nxt;

	if (!lst || !del)
		return ;
	nxt = *lst;
	while (nxt)
	{
		elem = nxt;
		nxt = elem->next;
		(*del)(elem->content);
		free(elem);
	}
	*lst = NULL;
}
