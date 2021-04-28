/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunckify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:10:32 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/28 15:52:03 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	*copy_stack(int32_t	*stack, int32_t size)
{
	int32_t	*to_sort;
	int32_t	i;

	to_sort = (int32_t	*)malloc(sizeof(int32_t) * size);
	if (to_sort == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		to_sort[i] = stack[i];
		i++;
	}
	return (to_sort);
}

void insertion_sort(int32_t	*array, uint32_t	length)
{
	uint32_t	j;
	uint32_t	i;
	int	tmp;

	i = 1;
	while (i < length)
	{
		tmp = array[i];
		j = i;
		while (j > 0 && array[j - 1] > tmp)
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = tmp;
		i++;
	}
}

int32_t	**chunckify(t_stacks	*stacks, int32_t	chucks)
{
	int32_t	*stck_cpy;
	int32_t	**chunck_val;
	int32_t	i;
	int32_t	prev;

	stck_cpy = copy_stack(stacks->stack_a, stacks->size_a);
	if (!stck_cpy)
		return (NULL);
	insertion_sort(stck_cpy, stacks->size_a);
	chunck_val = (int32_t **) malloc(sizeof(int32_t	*) * chucks);
	if (chunck_val == NULL)
		return (NULL);
	i = 0;
	prev = -1;
	while (i < chucks)
	{
		chunck_val[i] = (int32_t	*) malloc(sizeof(int32_t) * 2);
		if (chunck_val[i] == NULL)
			return (NULL);
		chunck_val[i][0] = stck_cpy[prev + 1];
		chunck_val[i][1] = stck_cpy[prev + stacks->size_a / chucks - 1];
		prev = prev + stacks->size_a / chucks - 1;
		i++;
	}
	chunck_val[i - 1][1] = stck_cpy[stacks->size_a - 1];
	return (chunck_val);
}