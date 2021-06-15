/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:41:51 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/15 12:58:08 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_lst	*lst_new(pthread_t	tid)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->tid = tid;
	new->id = 1;
	new->next = NULL;
	return (new);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

u_int8_t	lst_add_back(t_lst **lst, pthread_t	tid)
{
	t_lst	*tmp;

	if (!lst)
		return (-42);
	tmp = lst_new(tid);
	if (!tmp)
		return (-42);
	if (*lst == NULL)
		*lst = tmp;
	else
	{
		tmp->id = ft_lstlast(*lst)->id + 1;
		ft_lstlast(*lst)->next = tmp;
	}
	return (0);
}

uint8_t	lst_free(t_lst **lst)
{
	t_lst	*nxt;
	t_lst	*curr;

	if (!lst || !*lst)
		return (0);
	curr = *lst;
	while (curr)
	{
		nxt = curr->next;
		free(curr);
		curr = nxt;
	}
	return (0);
}