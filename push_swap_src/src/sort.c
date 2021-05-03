/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:11:02 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 13:12:12 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	sort_2(t_stacks	*stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		write_instr(stacks, "ra\n", 3, &instr_ra);
	return (0);
}

uint8_t	sort_3(t_stacks	*stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1]
		< stacks->stack_a[2] && stacks->stack_a[0] < stacks->stack_a[2])
		write_instr(stacks, "sa\n", 3, &instr_sa);
	else if (stacks->stack_a[0] > stacks->stack_a[1]
		&& stacks->stack_a[1] > stacks->stack_a[2])
		write_instr(stacks, "sa\n", 3, &instr_sa);
	else if (stacks->stack_a[0] < stacks->stack_a[1] && stacks->stack_a[1]
		> stacks->stack_a[2] && stacks->stack_a[0] < stacks->stack_a[2])
		write_instr(stacks, "sa\n", 3, &instr_sa);
	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[2]
		> stacks->stack_a[1] && stacks->stack_a[2] < stacks->stack_a[0])
		write_instr(stacks, "ra\n", 3, &instr_ra);
	else if (stacks->stack_a[0] < stacks->stack_a[1] && stacks->stack_a[1]
		> stacks->stack_a[2] && stacks->stack_a[0] > stacks->stack_a[2])
		write_instr(stacks, "rra\n", 4, &instr_rra);
	return (0);
}

uint8_t	sort_4(t_stacks	*stacks)
{
	push_smallest(stacks);
	sort_3(stacks);
	write_instr(stacks, "pa\n", 3, &instr_pa);
	return (0);
}

uint8_t	sort_5(t_stacks	*stacks)
{
	push_smallest(stacks);
	push_smallest(stacks);
	sort_3(stacks);
	write_instr(stacks, "pa\n", 3, &instr_pa);
	write_instr(stacks, "pa\n", 3, &instr_pa);
	return (0);
}

uint8_t	sort_100(t_stacks	*stacks, int32_t	n_chuncks)
{
	int32_t	**chuncks;
	int32_t	i;

	chuncks = chunckify(stacks, n_chuncks);
	i = 0;
	while (i < n_chuncks)
	{
		while (find_chunck(stacks, chuncks[i][0], chuncks[i][1]) >= 0)
		{
			push_in_b(stacks, find_chunck(stacks, chuncks[i][0],
					chuncks[i][1]));
		}
		i++;
	}
	while (stacks->size_b != 0)
		push_bigest(stacks);
	return (0);
}
