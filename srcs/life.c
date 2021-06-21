/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:28 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/21 16:32:56 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint8_t	write_act(t_philo_lst	*philo, char *msg)
{
	char *str;

	str = ft_strjoin(ft_ltoa(get_time() - philo->data->feast_start), " ");
	if (str == NULL)
		return (1);
	str = ft_strjoin(str, ft_ltoa((int64_t)philo->id));
	if (str == NULL)
		return (1);
	str = ft_strjoin(str, " ");
	if (str == NULL)
		return (1);
	str = ft_strjoin(str, msg);
	if (str == NULL)
		return (1);
	write(1, str, ft_strlen(str));
	free(str);
}

uint8_t	dead(t_philo_lst	*philo)
{
	int64_t cur_t;
	cur_t = get_time() - philo->data->feast_start;
	if(*philo->data->alive == 0)
		return (1);
	if (cur_t - philo->last_eaten < philo->data->t2die)
		return (0);
	write_act(philo, D);
	*philo->data->alive = 0;
	return (1);
}

uint8_t	eat(t_philo_lst	*philo)
{
	pthread_mutex_lock(&philo->right->fork);
	if (write_act(philo, F))
		return (1);
	pthread_mutex_lock(&philo->left->fork);
	if (write_act(philo, F))
		return (1);
	if (!dead(philo))
	{
		if (write_act(philo, E))
			return (1);
		philo->right->prev_philo = philo->id;
		philo->left->prev_philo = philo->id;
		usleep(philo->data->t2eat);
		philo->t_eaten++;
		philo->last_eaten = get_time()  - philo->data->feast_start;
		pthread_mutex_unlock(&philo->right->fork);
		pthread_mutex_unlock(&philo->left->fork);
	}
	return(0);
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
	philo = (t_philo_lst	*)ptr;
	philo->last_eaten = get_time() - philo->data->feast_start;
	while ((philo->t_eaten < philo->data->max_eat || philo->data->max_eat == -1) && *philo->data->alive)
	{
		if (!dead(philo))
			if (write_act(philo, T))
				return (1);
		while (philo->right->prev_philo == philo->id && *philo->data->alive)
			continue;
		if (!dead(philo))
			eat(philo);
		if (!dead(philo))
			p_sleep(philo);
	}
	return (0);
}
