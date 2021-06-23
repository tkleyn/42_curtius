/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:52:02 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/23 09:54:45 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	if (!s1)
		return (-1);
	while (size != 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		size--;
		s1++;
		s2++;
	}
	return (0);
}

uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

uint8_t	write_act(t_philo_lst	*philo, char *msg)
{
	char	*str;

	if (!ft_strncmp(msg, E, sizeof(E)))
	{
		philo->last_eaten = (get_time() - philo->data->feast_start);
		str = ft_strjoin(ft_ltoa(philo->last_eaten / 1000), " ");
	}
	else
		str = ft_strjoin(ft_ltoa((get_time()
						- philo->data->feast_start) / 1000), " ");
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
	write_mutex(philo, msg, str);
	free(str);
	return (0);
}

void	clean_data(t_philo_lst	**plst, t_data	*data)
{
	uint32_t	i;

	i = 0;
	while (i < data->n_philo)
		pthread_mutex_destroy(&data->forks[i++].fork);
	pthread_mutex_destroy(&data->alive_mutex);
	free(data->forks);
	lst_free(plst);
}
