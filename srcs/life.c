/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:28 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/18 12:51:42 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_act(t_philo_lst	*philo, char *msg)
{
	printf("%llu %d %s\n", get_time() - philo->data->feast_start, philo->id, msg);
}

uint8_t	eat(t_philo_lst	*philo)
{	
	while (philo->right->prev_philo == philo->id)
		continue;
	pthread_mutex_lock(&philo->right->fork);
	write_act(philo, F);
	pthread_mutex_lock(&philo->left->fork);
	write_act(philo, F);
	write_act(philo, E);
	usleep(philo->data->t2eat);
	philo->t_eaten++;
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
	return(0);
}

uint8_t	p_sleep(t_philo_lst	*philo)
{
	write_act(philo, S);
	usleep(philo->data->t2sleep);
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
	philo->last_eaten = get_time();
	while (philo->t_eaten < philo->data->max_eat || philo->data->max_eat == -1)
	{
		write_act(philo, T);
		eat(philo);
		p_sleep(philo);
	}
	return (0);
}


