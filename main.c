/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:31:36 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/17 15:17:24 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *jean;
	//printf("printf :%04i\n", -532);

	//ft_printf("frintf :%04i\n", -532);


	// To resolve : 

	// ft_printf("%00-s", s_hidden);

	// ft_printf("t3 %50.0d\n", 10);
	// ft_printf("st3 %*.*d\n", 0, 0, 50);
	// ft_printf("st5 %*.*d\n", 10, 0, 50);
	// ft_printf("neg4 %*.*d\n", 0, 0, -30);
	// ft_printf("%20.0d", 1024);
	// ft_printf("%20.d", -1024);

	// ft_printf("%020i", -1024);
	// ft_printf("%07i", -54);
	// ft_printf("%04i", -532);

	// ft_printf("%20.u", 1024u);
	// ft_printf("%20.0u", -1024u);

	// ft_printf("%2.9p\n", 1234);
	// ft_printf("%.5p", 0);
	// ft_printf("%.0p", 0);
	// ft_printf("%.p", &ncm_p);
	// ft_printf("%.0p, %.p", 0, 0);
	// ft_printf("%.5p", 0);
	// ft_printf("%2.9p", 1234);
	// ft_printf("%2.9p", 1234567);
	// ft_printf("%.p, %.0p", 0, 0);
	// ft_printf("p6 %.0d\n", 100);
	// ft_printf("p14 %.0i\n", 100);
	// ft_printf("p30 %.0u\n", 100);
	// ft_printf("%015p\n", NULL);

	// ft_printf("%5c", '\0');
	// ft_printf("%-5c", '\0');
	// ft_printf("%05c", '\0');
	// ft_printf("%-05c", '\0');

	// ft_printf("%x", 4294967295u);
	// ft_printf("%x, %x", 0, UINT_MAX);
	// ft_printf("%20.x", 0x1234abcdu);
	// ft_printf("%20.0x", -0x1234abcdu);
	// ft_printf("p22 %.0x\n", 100);
	// ft_printf("%x\n", -2147483648);
	// ft_printf("%X\n", -2147483648);
	// ft_printf("%010x\n", -20);
	// ft_printf("%10.2x\n", -20);
	// ft_printf("%x\n", -1);
	// ft_printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
	// ft_printf("%X", -0x1234abcdu);
	// ft_printf("%1X", -0x1234abcdu);
	// ft_printf("%20X", -0x1234abcdu);
	// ft_printf("%-20X", -0x1234abcdu);
	// ft_printf("%020X", -0x1234abcdu);
	// ft_printf("%-020X", -0x1234abcdu);
	// ft_printf("%*X", 20, -0x1234abcdu);
	// ft_printf("%.20x", -0x1234abcdu);
	// ft_printf("%020.10x", -0x1234abcdu);

	// ft_printf("{%3c}", 0);
	//ft_printf("{%010d}", -42);
	 //ft_printf("{%*c}", 0, 0);
	// ft_printf("{%*c}", -15, 0);
	// ft_printf("{%.*d}", 0, 42);
	// ft_printf("{%*3d}", 5, 0);
	// ft_printf("{%05.*d}", -15, 42);
}