/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:02:19 by tkleynts          #+#    #+#             */
/*   Updated: 2020/11/04 15:20:42 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	printf("\nSTRLEN NORMAL : %zu\n", strlen("strlentest12\n"));
	printf("STRLEN LIBASM : %zu\n", ft_strlen("strlentest12\n"));
	printf("\nSTRCMP NORMAL : %d\n", strcmp("test", "test"));
	printf("STRCMP LIBASM : %d\n", ft_strcmp("test", "test"));
	return (0);
}