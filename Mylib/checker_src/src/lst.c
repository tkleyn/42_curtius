/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:24:50 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 12:50:30 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_instr	*lst_new(char *str)
{
	t_instr	*new_instr;

	new_instr = (t_instr *)malloc(sizeof(t_instr));
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
	t_instr	*tmp;

	if (!lst || !str)
		return (-42);
	tmp = lst_new(str);
	if (!tmp)
		return (-42);
	if (*lst == NULL)
		*lst = tmp;
	else
		ft_lstlast(*lst)->next = tmp;
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
