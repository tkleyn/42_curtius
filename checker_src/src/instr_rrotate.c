/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:34:07 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/24 16:01:05 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

uint8_t	instr_rra(t_stacks *stacks)
{
	int32_t	tmp;

	tmp = stacks->stack_a[stacks->size_a - 1];
	offset_down(stacks->stack_a, stacks->size_a - 1);
	stacks->stack_a[0] = tmp;
	return (0);
}

uint8_t	instr_rrb(t_stacks *stacks)
{
	int32_t	tmp;

	tmp = stacks->stack_b[stacks->size_b - 1];
	offset_down(stacks->stack_b, stacks->size_b - 1);
	stacks->stack_b[0] = tmp;
	return (0);
}

uint8_t	instr_rrr(t_stacks *stacks)
{

}