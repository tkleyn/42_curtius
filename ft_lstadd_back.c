/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:07:00 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/24 13:05:13 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	if (!ft_lstlast(*alst))
		*alst = new;
	else
	{
		new->next = NULL;
		ft_lstlast(*alst)->next = new;
	}
}
