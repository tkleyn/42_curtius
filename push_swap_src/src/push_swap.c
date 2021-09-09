/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:00:43 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 15:23:50 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stacks	*stacks)
{
	write(2, "Error\n", 6);
	if (stacks->size_a)
		free(stacks->stack_a);
	if (stacks->size_b)
		free(stacks->stack_b);
	exit (-42);
}

uint8_t	write_instr(t_stacks	*stacks, char	*str, uint8_t	len,
	uint8_t	(*fct)(t_stacks	*))
{
	write(1, str, len);
	(void) str;
	(void) len;
	(*fct)(stacks);
	return (0);
}

uint8_t	ft_sort(t_stacks	*stacks)
{
	if (is_sorted(stacks->stack_a, stacks->size_a))
		return (0);
	if (stacks->size_a == 2)
		sort_2(stacks);
	if (stacks->size_a == 3)
		sort_3(stacks);
	if (stacks->size_a == 4)
		sort_4(stacks);
	if (stacks->size_a == 5)
		sort_5(stacks);
	if (stacks->size_a > 5 && stacks->size_a < 250)
		sort_100(stacks, 5);
	if (stacks->size_a >= 250 && stacks->size_a <= 750)
		sort_100(stacks, 9);
	if (stacks->size_a > 750)
		sort_100(stacks, stacks->size_a * 5 / 100);
	return (0);
}

int	main(int	argc, char *argv[])
{
	t_stacks	stacks;

	if (argc <= 1)
		ft_error(&stacks);
	if (check_arg(argc, argv, &stacks) != 0)
		ft_error(&stacks);
	ft_sort(&stacks);
	return (0);
}
