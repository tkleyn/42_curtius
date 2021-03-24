/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:52:43 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/24 15:51:03 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

uint8_t	offset_up(int32_t	*stack, int32_t size)
{
	int32_t	i;

	i = 1;
	while (i < size)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	return (0);
}

uint8_t	offset_down(int32_t	*stack, int32_t size)
{
	int32_t	i;

	i = size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	return (0);
}