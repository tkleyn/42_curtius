/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:34:10 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/24 15:47:41 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

uint8_t	instr_ra(t_stacks *stacks)
{
	int32_t	tmp;

	tmp = stacks->stack_a[0];
	offset_up(stacks->stack_a, stacks->size_a);
	stacks->stack_a[stacks->size_a - 1] = tmp;
	return (0);
}

uint8_t	instr_rb(t_stacks *stacks)
{
	int32_t	tmp;

	tmp = stacks->stack_b[0];
	offset_up(stacks->stack_b, stacks->size_b);
	stacks->stack_b[stacks->size_b - 1] = tmp;
	return (0);
}

uint8_t	instr_rr(t_stacks *stacks)
{

}