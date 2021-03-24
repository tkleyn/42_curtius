/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:56:20 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/24 13:02:23 by tkleynts         ###   ########.fr       */
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

void	ft_error()
{
	write(2, "Error\n", 6);
	exit (-42);
}

u_int8_t ft_read(t_instr **lst)
{
	char *instr;

	while (ft_gnl(0, &instr) > 0)
		lst_add_back(lst, instr);
	
	return (0);

}

int	main(int argc, char *argv[])
{
	t_instr *lst;
	t_instr *tmp;

	(void) argv;

	if (argc <= 1)
		ft_error();
	ft_read(&lst);

	tmp = lst_rm_head(&lst);
	while (tmp)
	{
		printf("%s\n", tmp->instr);
		free(tmp);
		tmp = lst_rm_head(&lst);
	}

	return (0);
}
