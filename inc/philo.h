/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:48:20 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/15 12:43:42 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_data
{
	int32_t		t2die;
	int32_t		t2eat;
	int32_t		t2sleep;
	pthread_mutex_t	*forks;
	int32_t	feast_start;
	int32_t	max_eat;

}	t_data;

typedef struct s_philo_data
{
	uint8_t		id;
	uint32_t	t_eaten;
	uint32_t	last_eaten;
	
}	t_philo_data;

typedef struct	s_lst
{
	pthread_t	tid;
	uint8_t		id;
	struct s_lst *next;
}	t_lst;

t_data	g_data;







#endif