/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:56:02 by tkleynts          #+#    #+#             */
/*   Updated: 2021/05/03 13:15:20 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "commons.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_instr
{
	char			*instr;
	struct s_instr	*next;
}	t_instr;

t_instr		*lst_new(char *str);
t_instr		*ft_lstlast(t_instr *lst);
u_int8_t	lst_add_back(t_instr **lst, char *str);
t_instr		*lst_rm_head(t_instr **lst);
uint8_t		lst_free(t_instr **lst);

#endif