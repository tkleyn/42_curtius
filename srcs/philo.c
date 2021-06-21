/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:48:24 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/21 13:27:56 by tkleynts         ###   ########.fr       */
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
	ft_lstlast(*plst)->right = &data->forks[i - 1];
	if (i == 1)
		ft_lstlast(*plst)->left = &data->forks[data->n_philo - 1];
	else
		ft_lstlast(*plst)->left = &data->forks[i - 2];
	if ((i + 1) % 2)
	{
		ft_lstlast(*plst)->left->prev_philo = i;
		ft_lstlast(*plst)->right->prev_philo = i;
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
	data->feast_start = get_time();
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

	plst = NULL;
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of args\n"));
	if (struct_init(argc, argv, &data))
		return (printf("Invalid arg(s)\n"));
	mother_philo(&data, &plst);

	while (plst)
	{
		pthread_join(plst->tid, NULL);
		plst = plst->next;
	}
	
	return (0);
}