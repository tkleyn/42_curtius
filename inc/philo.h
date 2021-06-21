/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:48:20 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/21 13:20:30 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
#include <sys/time.h>

# define F "has taken a fork"
# define E "is eating"
# define  S "is sleeping"
# define T "is thinking"
# define  D "died"

typedef struct s_fork
{
	uint32_t prev_philo;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_data
{
	uint32_t	n_philo;
	int32_t		t2die;
	int32_t		t2eat;
	int32_t		t2sleep;
	int32_t		max_eat;
	t_fork		*forks;
	int64_t		feast_start;
}	t_data;

typedef struct s_philo_data
{
	pthread_t	tid;
	uint32_t		id;
	int32_t	t_eaten;
	int64_t	last_eaten;
	t_data	*data;
	t_fork	*right;
	t_fork	*left;
	struct s_philo_data *next;
}	t_philo_lst;


t_philo_lst	*ft_lstlast(t_philo_lst *pls);
u_int8_t	lst_add_back(t_philo_lst **plst, t_data	*data);
uint8_t	lst_free(t_philo_lst **plst);

void	*philo_life(void	*d);

int	ft_fatoi(const char	*str, uint8_t	*flag);

uint64_t get_time(void);





#endif