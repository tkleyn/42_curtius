/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:48:20 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/15 15:06:52 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_fork
{
	pthread_t prev_philo;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_data
{
	uint32_t	n_philo;
	int32_t		t2die;
	int32_t		t2eat;
	int32_t		t2sleep;
	int32_t		max_eat;
	pthread_mutex_t	*forks;

}	t_data;

typedef struct s_philo_data
{
	pthread_t	tid;
	uint8_t		id;
	uint32_t	t_eaten;
	uint32_t	last_eaten;
	t_data	*data;
	t_fork	right;
	t_fork	left;
	struct s_lst *next;
}	t_philo_lst;


t_philo_lst	*ft_lstlast(t_philo_lst *pls);
u_int8_t	lst_add_back(t_philo_lst **plst, t_data	*data);
uint8_t	lst_free(t_philo_lst **plst);

void	*philo_life(void	*d);







#endif