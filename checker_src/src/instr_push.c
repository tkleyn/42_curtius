/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:34:13 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/06 14:06:01 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

uint8_t	instr_pa(t_stacks *stacks)
{
	int32_t	tmp;

	if (stacks->size_b < 1)
		return (0);
	tmp = stacks->stack_b[0];
	offset_up(stacks->stack_b, stacks->size_b);
	offset_down(stacks->stack_a, stacks->size_a);
	stacks->stack_a[0] = tmp;
	stacks->size_a++;
	stacks->size_b--;
	return (0);
}

uint8_t	instr_pb(t_stacks *stacks)
{
	int32_t	tmp;

	if (stacks->size_a < 1)
		return (0);
	tmp = stacks->stack_a[0];
	offset_up(stacks->stack_a, stacks->size_a);
	offset_down(stacks->stack_b, stacks->size_b);
	stacks->stack_b[0] = tmp;
	stacks->size_a--;
	stacks->size_b++;
	return (0);
}