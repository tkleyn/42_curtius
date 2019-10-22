/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:07:00 by tkleynts          #+#    #+#             */
/*   Updated: 2019/10/21 14:41:56 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
