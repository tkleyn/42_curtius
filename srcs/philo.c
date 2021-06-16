/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:48:24 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/16 12:31:48 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint8_t	struct_init(int argc, char **argv, t_data	*data)
{
	uint8_t flag;
	flag  = 0;
	data->n_philo = ft_fatoi(argv[1], &flag);
	if (flag)
		return (1);
	data->t2die = ft_fatoi(argv[2], &flag);
	if (flag)
		return (1);
	data->t2eat = ft_fatoi(argv[3], &flag);
	if (flag)
		return (1);
	data->t2sleep = ft_fatoi(argv[4], &flag);
	if (flag)
		return (1);
	if (argc == 6)
	{
		data->max_eat = ft_fatoi(argv[5], &flag);
		if (flag)
			return (-1);
	}
	else
		data->max_eat = -1;
	
	return (0);
}

uint8_t	philo_miner(t_data *data, t_philo_lst	**plst, uint32_t	i)
{
	lst_add_back(plst, data);
	ft_lstlast(*plst)->id = i;
	if (i == 0)
		(*plst)->left = &data->forks[data->n_philo - 1];
	else
		(*plst)->left = &data->forks[i - 1];
	(*plst)->left = &data->forks[i];
	if (!(i % 2))
	{
		(*plst)->left->prev_philo = (*plst)->id;
		(*plst)->right->prev_philo = (*plst)->id;
	}
	return(0);
}

uint8_t	mother_philo(t_data *data, t_philo_lst	**plst)
{
	uint32_t	i;

	i = 0;
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->n_philo);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
		i++;
	}
	i = 1;
	while (i <= data->n_philo)
	{
		philo_miner(data, plst, i);
		pthread_create(&ft_lstlast(*plst)->tid, NULL, &philo_life, (void	*)ft_lstlast(*plst));
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_data	data;
	t_philo_lst	*plst;
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of args\n"));
	if (struct_init(argc, argv, &data))
		return (printf("Invalid arg(s)\n"));
	mother_philo(&data, &plst);



	return (0);
}