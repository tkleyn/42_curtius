/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunckify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:10:32 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 13:37:06 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	c_fill(int32_t	**c_val, int32_t	*cpy, int	chucks, int32_t	size)
{
	int32_t	i;
	int32_t	prev;

	i = 0;
	prev = -1;
	while (i < chucks)
	{
		c_val[i] = (int32_t *) malloc(sizeof(int32_t) * 2);
		if (c_val[i] == NULL)
		{
			free(c_val);
			return (-1);
		}
		c_val[i][0] = cpy[prev + 1];
		c_val[i][1] = cpy[prev + size / chucks - 1];
		prev = prev + size / chucks - 1;
		i++;
	}
	c_val[i - 1][1] = cpy[size - 1];
	return (0);
}

int32_t	**chunckify(t_stacks	*stacks, int32_t	chucks)
{
	int32_t	*stck_cpy;
	int32_t	**chunck_val;

	stck_cpy = copy_stack(stacks->stack_a, stacks->size_a);
	if (!stck_cpy)
		return (NULL);
	insertion_sort(stck_cpy, stacks->size_a);
	chunck_val = (int32_t **) malloc(sizeof(int32_t *) * chucks);
	if (chunck_val == NULL)
		return (NULL);
	if (c_fill(chunck_val, stck_cpy, chucks, stacks->size_a))
		return (NULL);
	free(stck_cpy);
	return (chunck_val);
}
