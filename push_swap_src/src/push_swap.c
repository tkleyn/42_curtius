/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:00:43 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/22 15:49:23 by tkleynts         ###   ########.fr       */
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
	(void) str;
	(void) len;
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
	push_smallest(stacks);
	push_smallest(stacks);
	sort_3(stacks);
	write_instr(stacks, "pa\n", 3, &instr_pa);
	write_instr(stacks, "pa\n", 3, &instr_pa);
	return (0);
}

uint8_t	sort_100(t_stacks	*stacks)
{
	(void)stacks;
	return (0);
}

uint8_t	ft_sort(t_stacks	*stacks)
{
	if (is_sorted(stacks->stack_a, stacks->size_a))
		return (0);//envoyer eof
	if (stacks->size_a == 2)
		return (0);// a gerer
	if (stacks->size_a == 3)
		sort_3(stacks);
	if (stacks->size_a == 5)
		sort_5(stacks);
	if (stacks->size_a == 100)
		sort_100(stacks);
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
	//print_stacks(&stacks);
	return (0);
}