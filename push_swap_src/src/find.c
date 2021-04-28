/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:33:19 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/28 15:35:51 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint32_t	find_smallest(int32_t	*stack, int32_t	size)
{
	uint32_t	smallest;
	int32_t		i;

	smallest = 0;
	i = 0;
	while (i < size)
	{
		if (stack[i] < stack[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

uint32_t	find_bigest(int32_t	*stack, int32_t	size)
{
	uint32_t	bigest;
	int32_t		i;

	bigest = 0;
	i = 0;
	while (i < size)
	{
		if (stack[i] > stack[bigest])
			bigest = i;
		i++;
	}
	return (bigest);
}

int32_t	find_chunck(t_stacks	*stacks, int32_t	min, int32_t	max)
{
	int32_t	i;
	int32_t	first;
	int32_t	sec;

	i = 0;
	first = -1;
	sec = -1;
	while (i < stacks->size_a / 2)
	{
		if (stacks->stack_a[i] >= min && stacks->stack_a[i] <= max)
		{
			first = i;
			break;
		}
		i++;
	}

	i = stacks->size_a / 2;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] >= min && stacks->stack_a[i] <= max)
		{
			sec = i;
			break;
		}
		i++;
	}
	if((first == -1) && (sec == -1))
		return (-1);
	

	if (first != -1 && first < stacks->size_a - sec)
		return (first);
	return (sec);
}
