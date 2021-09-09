/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:12:47 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 12:56:04 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	ft_fatoi(const char	*str, uint8_t	*flag)
{
	uint64_t	number;
	int			sign;

	*flag = 0;
	sign = 1;
	number = 0;
	while (*str == '\r' || *str == '\f' || *str == '\n' || *str == '\v'
		|| *str == '\t' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str++ - '0');
		if ((number > INT32_MAX && sign == 1)
			|| (number > (uint64_t)INT32_MAX + 1 && sign == -1))
			return (*flag = 1);
	}
	if (*str != '\0')
		return (*flag = 1);
	return ((int)(number * sign));
}

uint8_t	instr_init(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	return (0);
}

uint8_t	print_stacks(t_stacks *stacks)
{
	int	i;

	i = 0;
	printf("a \t\t\tb\n-\t\t\t-\n");
	while (i < stacks->size_a || i < stacks->size_b)
	{
		if (i < stacks->size_a)
			printf("%d\t\t\t", stacks->stack_a[i]);
		else
			printf("/\t\t\t");
		if (i < stacks->size_b)
			printf("%d\n", stacks->stack_b[i]);
		else
			printf("/\n");
		i++;
	}
	return (0);
}

int32_t	*copy_stack(int32_t	*stack, int32_t size)
{
	int32_t	*to_sort;
	int32_t	i;

	to_sort = (int32_t *)malloc(sizeof(int32_t) * size);
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

void	insertion_sort(int32_t	*array, uint32_t	length)
{
	uint32_t	j;
	uint32_t	i;
	int			tmp;

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
