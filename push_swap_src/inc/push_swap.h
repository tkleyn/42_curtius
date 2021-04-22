/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:00:10 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/22 15:49:55 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "commons.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

uint8_t	write_instr(t_stacks *stacks, char	*str, uint8_t	len, uint8_t	(*fct)(t_stacks	*));

uint8_t	push_in_b(t_stacks	*stacks, int32_t	index);
uint8_t	push_in_a(t_stacks	*stacks, int32_t	index);
uint8_t	push_smallest(t_stacks	*stacks);

uint32_t	find_smallest(int32_t	*stack, int32_t	size);
uint32_t	find_bigest(int32_t	*stack, int32_t	size);
int32_t	find_chunck(t_stacks	*stacks, int32_t	min, int32_t	max);


#endif