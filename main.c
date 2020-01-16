/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:31:36 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/16 11:05:08 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("printf :%0-10.5i", 216);
	ft_printf("frintf :%0-10.5i", 216);
}

/*

num = spaces right pad\
.num = 0 right pad
-num = spaces left pad
-.num = .num

*/
