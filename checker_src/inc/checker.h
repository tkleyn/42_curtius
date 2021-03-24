/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:56:02 by tkleynts          #+#    #+#             */
/*   Updated: 2021/03/24 15:05:39 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_instr
{
	char			*instr;
	struct s_instr	*next;
}	t_instr;

typedef struct s_stacks
{
	int32_t	*stack_a;
	int32_t	size_a;
	int32_t	*stack_b;
	int32_t	size_b;
}	t_stacks;

uint8_t	instr_sa(t_stacks	*stacks);
uint8_t	instr_sb(t_stacks	*stacks);
uint8_t	instr_ss(t_stacks	*stacks);

uint8_t	instr_pa(t_stacks	*stacks);
uint8_t	instr_pb(t_stacks	*stacks);

uint8_t	instr_ra(t_stacks	*stacks);
uint8_t	instr_rb(t_stacks	*stacks);
uint8_t	instr_rr(t_stacks	*stacks);

uint8_t	instr_rra(t_stacks *stacks);
uint8_t	instr_rrb(t_stacks *stacks);
uint8_t	instr_rrr(t_stacks *stacks);

uint8_t	offset_up(int32_t	*stack, int32_t	size);
uint8_t	offset_down(int32_t	*stack, int32_t	size);

uint8_t	check_instr(char	*instr, t_stacks	*stacks);

#endif