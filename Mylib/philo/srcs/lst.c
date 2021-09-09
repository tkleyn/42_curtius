/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:41:51 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/22 15:12:45 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_lst	*lst_new(t_data	*data)
{
	t_philo_lst	*new;

	new = (t_philo_lst *)malloc(sizeof(t_philo_lst));
	if (new == NULL)
		return (NULL);
	new->t_eaten = 0;
	new->data = data;
	new->next = NULL;
	new->eating = 0;
	return (new);
}

t_philo_lst	*ft_lstlast(t_philo_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

u_int8_t	lst_add_back(t_philo_lst **lst, t_data	*data)
{
	t_philo_lst	*tmp;

	if (!lst)
		return (-42);
	tmp = lst_new(data);
	if (!tmp)
		return (-42);
	if (*lst == NULL)
		*lst = tmp;
	else
		ft_lstlast(*lst)->next = tmp;
	return (0);
}

uint8_t	lst_free(t_philo_lst **lst)
{
	t_philo_lst	*nxt;
	t_philo_lst	*curr;

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
