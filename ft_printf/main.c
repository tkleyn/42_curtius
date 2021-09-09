/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:53:37 by tkleynts          #+#    #+#             */
/*   Updated: 2020/01/30 14:28:34 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	char *jean;
	ft_printf("\t\tTesting basic input\n");
	ft_printf("\t\t-------------------\n");
	printf("Printf :%s, %c, %d, %i, %x, %X, %u, %p\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);
	ft_printf("ft_printf :%s, %c, %d, %i, %x, %X, %u, %p\n\n\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);

	ft_printf("\t\tTesting width\n");
	ft_printf("\t\t-------------\n");
	printf("Printf :%25s, %45c, %1d, %8i, %9x, %5X, %10u, %4p\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);
	ft_printf("ft_printf :%25s, %45c, %1d, %8i, %9x, %5X, %10u, %4p\n\n\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);

	ft_printf("\t\tTesting width with left just\n");
	ft_printf("\t\t----------------------------\n");
	printf("Printf :%-25s, %-45c, %-1d, %-8i, %-9x, %-5X, %-10u, %-4p\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);
	ft_printf("ft_printf :%-25s, %-45c, %-1d, %-8i, %-9x, %-5X, %-10u, %-4p\n\n\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);

	ft_printf("\t\tTesting width with padding\n");
	ft_printf("\t\t--------------------------\n");
	printf("Printf :%25s, %45c, %01d, %08i, %09x, %05X, %010u, %4p\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);
	ft_printf("ft_printf :%25s, %45c, %01d, %08i, %09x, %05X, %010u, %4p\n\n\n", "Hello", 'h', -121, 665, 4555214, 755145, 65661, &jean);

	ft_printf("\t\tTesting prec\n");
	ft_printf("\t\t-------------\n");
	printf("Printf :%.25s, %.1d, %.8i, %.9x, %.5X, %.10u\n", "Hello", -121, 665, 4555214, 755145, 65661);
	ft_printf("ft_printf :%.25s, %.1d, %.8i, %.9x, %.5X, %.10u\n\n\n", "Hello", -121, 665, 4555214, 755145, 65661);

	ft_printf("\t\tTesting prec with left just\n");
	ft_printf("\t\t----------------------------\n");
	printf("Printf :%-.25s, %-.1d, %-.8i, %-.9x, %-.5X, %-.10u\n", "Hello", -121, 665, 4555214, 755145, 65661);
	ft_printf("ft_printf :%-.25s, %-.1d, %-.8i, %-.9x, %-.5X, %-.10u\n\n\n", "Hello", -121, 665, 4555214, 755145, 65661);

	ft_printf("\t\tTesting prec with padding\n");
	ft_printf("\t\t--------------------------\n");
	printf("Printf :%.25s, %0.1d, %0.8i, %0.9x, %0.5X, %0.10u\n", "Hello", -121, 665, 4555214, 755145, 65661);
	ft_printf("ft_printf :%.25s, %0.1d, %0.8i, %0.9x, %0.5X, %0.10u\n\n\n", "Hello", -121, 665, 4555214, 755145, 65661);

	ft_printf("\t\tTesting prec *\n");
	ft_printf("\t\t--------------\n");
	printf("Printf :%.*s, %0.*d, %0.*i, %0.*x, %0.*X, %0.*u\n", 25, "Hello", 1, -121, 8, 665, 0, 4555214, -7, 755145, -1, 65661);
	ft_printf("ft_printf :%.*s, %0.*d, %0.*i, %0.*x, %0.*X, %0.*u\n\n\n", 25, "Hello", 1, -121, 8, 665, 0, 4555214, -7, 755145, -1, 65661);

	ft_printf("\t\tTesting width *\n");
	ft_printf("\t\t---------------\n");
	printf("Printf :%*s, %0*d, %0*i, %0*x, %0*X, %0*u\n", 25, "Hello", 1, -121, 8, 665, 0, 4555214, -7, 755145, -1, 65661);
	ft_printf("ft_printf :%*s, %0*d, %0*i, %0*x, %0*X, %0*u\n\n\n", 25, "Hello", 1, -121, 8, 665, 0, 4555214, -7, 755145, -1, 65661);

	ft_printf("\t\tTesting NULL *\n");
	ft_printf("\t\t---------------\n");
	printf("Printf :%*s, %0*d, %0*i, %0*x, %0*X, %0*u, %p, %c\n", 25, 0, 1, NULL, 8, NULL, 0, NULL, -7, NULL, -1, NULL, NULL, 0);
	ft_printf("ft_printf :%*s, %0*d, %0*i, %0*x, %0*X, %0*u, %p, %c\n\n\n", 25, 0, 1, NULL, 8, NULL, 0, NULL, -7, NULL, -1, NULL, NULL, 0);

	return (0);
}
