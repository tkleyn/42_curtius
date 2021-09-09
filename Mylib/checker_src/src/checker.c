/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:56:20 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 12:50:04 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_error(t_stacks *stacks, t_instr **lst)
{
	write(2, "Error\n", 6);
	if (stacks->size_a)
		free(stacks->stack_a);
	if (stacks->size_b)
		free(stacks->stack_b);
	lst_free(lst);
	exit (-42);
}

static u_int8_t	ft_read(t_instr **lst)
{
	char	*instr;

	while (ft_gnl(0, &instr) > 0)
		if (lst_add_back(lst, instr))
			return (-1);
	return (0);
}

uint8_t	check_instr(char	*instr, t_stacks	*stacks)
{
	if (!ft_strncmp(instr, "sa", 3))
		return (instr_sa(stacks));
	else if (!ft_strncmp(instr, "sb", 3))
		return (instr_sb(stacks));
	else if (!ft_strncmp(instr, "ss", 3))
		return (instr_ss(stacks));
	else if (!ft_strncmp(instr, "pa", 3))
		return (instr_pa(stacks));
	else if (!ft_strncmp(instr, "pb", 3))
		return (instr_pb(stacks));
	else if (!ft_strncmp(instr, "ra", 3))
		return (instr_ra(stacks));
	else if (!ft_strncmp(instr, "rb", 3))
		return (instr_rb(stacks));
	else if (!ft_strncmp(instr, "rr", 3))
		return (instr_rr(stacks));
	else if (!ft_strncmp(instr, "rra", 4))
		return (instr_rra(stacks));
	else if (!ft_strncmp(instr, "rrb", 4))
		return (instr_rrb(stacks));
	else if (!ft_strncmp(instr, "rrr", 4))
		return (instr_rrr(stacks));
	return (-1);
}

static uint8_t	instr_exec(t_stacks *stacks, t_instr **lst)
{
	t_instr	*tmp;

	tmp = lst_rm_head(lst);
	while (tmp)
	{
		if (check_instr(tmp->instr, stacks) != 0)
			return (-1);
		tmp = lst_rm_head(lst);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_instr		*lst;
	t_stacks	stacks;

	if (argc <= 1)
		return (0);
	if (check_arg(argc, argv, &stacks) != 0)
		ft_error(&stacks, &lst);
	if (ft_read(&lst))
		ft_error(&stacks, &lst);
	if (instr_exec(&stacks, &lst) != 0)
		ft_error(&stacks, &lst);
	if (is_sorted(stacks.stack_a, stacks.size_a))
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
