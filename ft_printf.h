/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 07:44:40 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/07 15:51:34 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct
{
    va_list     args;
    char        *f_cpy;
    char        *buff;
}               t_utils;

typedef struct
{    
    int         ljust;//-
    int         pad;//0
    int         prec;//.num
    int         width;//num
}               t_flags;

int             ft_printf(const char *format, ...);
char			*is_convert(t_utils *data);

#endif