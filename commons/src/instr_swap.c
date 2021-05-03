/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:24:54 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 12:53:04 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

uint8_t	instr_sa(t_stacks *stacks)
{
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
	return (instr_sa(stacks) + instr_sb(stacks));
}
