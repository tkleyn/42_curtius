/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:48:24 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/15 12:40:53 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint8_t	struct_init(int argc, char **argv, uint32_t	*n_philo)
{
	uint8_t flag;
	flag  = 0;
	*n_philo = ft_fatoi(argv[1], &flag);
	if (flag)
		return (1);
	g_data.t2die = ft_fatoi(argv[2], &flag);
	if (flag)
		return (1);
	g_data.t2eat = ft_fatoi(argv[3], &flag);
	if (flag)
		return (1);
	g_data.t2sleep = ft_fatoi(argv[4], &flag);
	if (flag)
		return (1);
	if (argc == 6)
	{
		g_data.max_eat = ft_fatoi(argv[5], &flag);
		if (flag)
			return (-1);
	}
	else
		g_data.max_eat = -1;
	
	return (0);
}


uint8_t	mother_philo()
{
	while ()
	{
		pthread_create();
	}
	
}

int main(int argc, char *argv[])
{
	uint32_t	n_philo;
	
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of args\n"));
	if (struct_init(argc, argv, &n_philo))
		return (printf("Invalid arg(s)\n"));



	return (0);
}