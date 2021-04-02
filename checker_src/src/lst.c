/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:24:50 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/02 15:33:05 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_instr	*lst_new(char *str)
{
	t_instr	*new_instr;

	new_instr = malloc(sizeof(t_instr));
	if (new_instr == NULL)
		return (NULL);
	new_instr->instr = str;
	new_instr->next = NULL;
	return (new_instr);
}

t_instr	*ft_lstlast(t_instr *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

u_int8_t	lst_add_back(t_instr **lst, char *str)
{
	if (!lst || !str)
		return (-42);
	if (*lst == NULL)
		*lst = lst_new(str);
	else
		ft_lstlast(*lst)->next = lst_new(str);
	return (0);
}

t_instr	*lst_rm_head(t_instr **lst)
{
	t_instr	*temp;

	if (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		return (temp);
	}
	return (NULL);
}

uint8_t	lst_free(t_instr **lst)
{
	t_instr	*nxt;
	t_instr	*curr;

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
