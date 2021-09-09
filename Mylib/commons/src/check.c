/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:43:42 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 12:51:32 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

uint8_t	check_arg(int	argc, char	*argv[], t_stacks *stacks)
{
	int		i;
	uint8_t	flg;

	stacks->stack_a = malloc(sizeof(int32_t) * (argc - 1));
	stacks->stack_b = malloc(sizeof(int32_t) * (argc - 1));
	if (!stacks->stack_a || !stacks->stack_b)
		return (-1);
	i = 1;
	while (i < argc)
	{
		stacks->stack_a[i - 1] = ft_fatoi(argv[i], &flg);
		if (flg)
			return (-1);
		i++;
	}
	stacks->size_a = argc - 1;
	if (is_double(stacks))
		return (-1);
	return (0);
}

uint8_t	is_sorted(int32_t	*stack, int32_t	size)
{
	int32_t	i;

	if (size <= 1)
		return (1);
	i = 1;
	while (i < size)
	{
		if (stack[i - 1] >= stack[i])
			return (0);
		i++;
	}
	return (1);
}

uint8_t	is_double(t_stacks *stacks)
{
	int32_t	*cpy;
	int32_t	i;

	i = 0;
	cpy = copy_stack(stacks->stack_a, stacks->size_a);
	if (!cpy)
		return (1);
	insertion_sort(cpy, stacks->size_a);
	while (i < stacks->size_a - 1)
	{
		if (cpy[i] >= cpy[i + 1])
			return (1);
		i++;
	}
	free(cpy);
	return (0);
}
