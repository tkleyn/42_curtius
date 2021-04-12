/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:00:43 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/11 12:00:02 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	if (stacks->size_a)
		free(stacks->stack_a);
	if (stacks->size_b)
		free(stacks->stack_b);
	exit (-42);
}

uint8_t	write_instr(t_stacks *stacks, char	*str, uint8_t	len, uint8_t	(*fct)(t_stacks	*))
{
	write(1, str, len);
	(*fct)(stacks);
	return (0);
}

uint8_t	sort_3(t_stacks	*stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1] < stacks->stack_a[2] && stacks->stack_a[0] < stacks->stack_a[2]) //cas 1
		write_instr(stacks, "sa\n", 3, &instr_sa);
	else if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1] > stacks->stack_a[2]) //cas 2
		write_instr(stacks, "sa\n", 3, &instr_sa);
	else if (stacks->stack_a[0] < stacks->stack_a[1] && stacks->stack_a[1] > stacks->stack_a[2] && stacks->stack_a[0] < stacks->stack_a[2]) //cas 4
		write_instr(stacks, "sa\n", 3, &instr_sa);
	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[2] > stacks->stack_a[1] && stacks->stack_a[2] < stacks->stack_a[0]) //cas 3 et 4.2
		write_instr(stacks, "ra\n", 3, &instr_ra);
	else if (stacks->stack_a[0] < stacks->stack_a[1] && stacks->stack_a[1] > stacks->stack_a[2] && stacks->stack_a[0] > stacks->stack_a[2]) //cas 5 et 2.2
		write_instr(stacks, "rra\n", 4, &instr_rra);
	//signal
	return (0);
}

uint8_t	sort_5(t_stacks	*stacks)
{
	(void) stacks;
	return (0);
}

uint8_t	ft_sort(t_stacks	*stacks)
{
	if (stacks->size_a == 1)
		return (0);
	if (stacks->size_a == 2)
		return (0);
	if (stacks->size_a == 3)
		sort_3(stacks);
	if (stacks->size_a == 5)
		sort_5(stacks);
	return (0);
}

int main(int	argc, char *argv[])
{
	t_stacks	stacks;

	if (argc <= 1)
		ft_error(&stacks);
	if (check_arg(argc, argv, &stacks) != 0)
		ft_error(&stacks);
	ft_sort(&stacks);
	
	return (0);
}