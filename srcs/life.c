/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:28 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/23 16:26:02 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_mutex(t_philo_lst	*philo, char *msg, char *str)
{
	pthread_mutex_lock(&philo->data->alive_mutex);
	if (*philo->data->alive == 1)
		write(1, str, ft_strlen(str));
	if (!ft_strncmp(msg, D, sizeof(D)))
		*philo->data->alive = 0;
	pthread_mutex_unlock(&philo->data->alive_mutex);
}

uint8_t	eat(t_philo_lst	*philo)
{
	pthread_mutex_lock(&philo->right->fork);
	if (write_act(philo, F))
		return (1);
	pthread_mutex_lock(&philo->left->fork);
	if (write_act(philo, F))
		return (1);
	philo->eating = 1;
	if (write_act(philo, E))
		return (1);
	philo->eating = 0;
	usleep(philo->data->t2eat);
	philo->t_eaten++;
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
	philo->right->prev_philo = philo->id;
	philo->left->prev_philo = philo->id;
	return (0);
}

uint8_t	p_sleep(t_philo_lst	*philo)
{
	if (write_act(philo, S))
		return (1);
	usleep(philo->data->t2sleep);
	return (0);
}

void	*philo_life(void	*ptr)
{
	t_philo_lst	*philo;

	philo = (t_philo_lst *)ptr;
	philo->last_eaten = get_time() - philo->data->feast_start;
	while ((philo->t_eaten < philo->data->max_eat
			|| philo->data->max_eat == -1) && *philo->data->alive)
	{
		if (*philo->data->alive)
			write_act(philo, T);
		while (philo->right->prev_philo == philo->id && *philo->data->alive)
			continue ;
		if (*philo->data->alive)
			eat(philo);
		else
			return (0);
		if (*philo->data->alive)
			p_sleep(philo);
	}
	philo->data->end = 1;
	return (0);
}
