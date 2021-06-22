/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:48:24 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/22 15:46:56 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint8_t	struct_init(int argc, char **argv, t_data	*data)
{
	uint8_t	flag;

	flag = 0;
	data->n_philo = ft_fatoi(argv[1], &flag);
	if (flag)
		return (1);
	data->t2die = ft_fatoi(argv[2], &flag) * 1000;
	if (flag)
		return (1);
	data->t2eat = ft_fatoi(argv[3], &flag) * 1000;
	if (flag)
		return (1);
	data->t2sleep = ft_fatoi(argv[4], &flag) * 1000;
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
	return (0);
}

void	death_check(t_philo_lst	*philo)
{
	t_philo_lst	*cpy;
	int64_t	curent_time;

	while (!philo->data->end)
	{
		cpy = philo;
		curent_time = get_time() - philo->data->feast_start;
		while (cpy && !philo->data->end)
		{
			if ((curent_time - cpy->last_eaten >= cpy->data->t2die) && !cpy->eating)
			{
				write_act(cpy, D);
				return ;
			}
			cpy = cpy->next;
		}
	}
}

uint8_t	mother_philo(t_data *data, t_philo_lst	**plst)
{
	uint32_t	i;

	i = 0;
	pthread_mutex_init(&data->alive_mutex, NULL);
	data->end = 0;
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->n_philo);
	if (data->forks == NULL)
		return (1);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL))
			return (1);
		i++;
	}
	i = 1;
	data->feast_start = get_time();
	while (i <= data->n_philo)
	{
		philo_miner(data, plst, i);
		if (pthread_create(&ft_lstlast(*plst)->tid, NULL
				, &philo_life, (void *)ft_lstlast(*plst)))
			return (1);
		i++;
	}
	return (0);
}

void	clean_data(t_philo_lst	**plst, t_data	*data)
{
	uint32_t	i;

	i = 0;
	while (i < data->n_philo)
		pthread_mutex_destroy(&data->forks[i++].fork);
	free(data->forks);
	lst_free(plst);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_philo_lst	*plst;
	t_philo_lst	*plst_cpy;
	uint32_t	i;
	uint8_t		life;

	data.alive = &life;
	*data.alive = 1;
	plst = NULL;
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of args\n"));
	if (struct_init(argc, argv, &data))
		return (printf("Invalid arg(s)\n"));
	if (mother_philo(&data, &plst))
		return (printf("Mallo-Mutex error\n"));
	death_check(plst);
	plst_cpy = plst;
	i = 0;
	while (i < data.n_philo)
	{
		pthread_join(plst_cpy->tid, NULL);
		plst_cpy = plst_cpy->next;
		i++;
	}
	clean_data(&plst, &data);
	return (0);
}
