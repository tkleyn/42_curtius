/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:28 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/16 14:13:47 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint8_t	eat(t_philo_lst	*philo)
{
	(void)philo;
	/*
	while (philo->right->prev_philo == philo->id)
		continue;
	pthread_mutex_lock();
	pthread_mutex_lock();
	*/
	return(0);
}

uint8_t	p_sleep()
{
	return (0);
}

uint8_t	die()
{
	return (0);
}

void	*philo_life(void	*ptr)
{
	t_philo_lst	*philo;

	philo = (t_philo_lst	*)ptr;
	printf("I'm philo number: %d -------- %d\n", philo->id, philo->data->forks[3].prev_philo);

	/*
	eat();
	sleep();
	*/
	return (0);
}
