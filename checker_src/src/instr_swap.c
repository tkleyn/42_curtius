/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:24:54 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/02 16:19:14 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

uint8_t	instr_sa(t_stacks *stacks)
{
	printf("in instr_sa\n");
	int32_t	tmp;
	
	if (stacks->size_a < 2)
		return (0);
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
	return (0);
}

uint8_t	instr_sb(t_stacks *stacks)
{
	printf("in instr_sb\n");
	int32_t	tmp;

	if (stacks->size_b < 2)
		return (0);
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
	return (0);
}

uint8_t	instr_ss(t_stacks *stacks)
{
	printf("in instr_ss\n");
	return (instr_sa(stacks) + instr_sb(stacks));
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
