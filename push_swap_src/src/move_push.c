/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:36:10 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/22 15:50:28 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	push_in_b(t_stacks	*stacks, int32_t	index)
{
	if (index < (stacks->size_a / 2))
		while (index-- > 0)
			write_instr(stacks, "ra\n", 3, &instr_ra);
	else
		while (index++ < stacks->size_a)
			write_instr(stacks, "rra\n", 4, &instr_rra);	
	write_instr(stacks, "pb\n", 3, &instr_pb);
	return (0);
}

uint8_t	push_in_a(t_stacks	*stacks, int32_t	index)
{
	if (index < (stacks->size_b / 2))
		while (index-- > 0)
			write_instr(stacks, "rb\n", 3, &instr_rb);
	else
		while (index++ < stacks->size_b)
			write_instr(stacks, "rrb\n", 4, &instr_rrb);	
	write_instr(stacks, "pa\n", 3, &instr_pa);
	return (0);
}

uint8_t	push_smallest(t_stacks	*stacks)
{
	int32_t	i;

	i = find_smallest(stacks->stack_a, stacks->size_a);
	if (i < (stacks->size_a / 2))
		while (i-- > 0)
			write_instr(stacks, "ra\n", 3, &instr_ra);
	else
		while (i++ < stacks->size_a)
			write_instr(stacks, "rra\n", 4, &instr_rra);	
	write_instr(stacks, "pb\n", 3, &instr_pb);
	return (0);
}