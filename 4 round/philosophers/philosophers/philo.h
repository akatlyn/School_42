/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:01:15 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/07 14:34:36 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_data		*data;
	int					count_eat;
	long				last_eat;
}				t_philo;

typedef struct s_data
{
	long				start_time;
	t_philo				*philos;
	pthread_mutex_t		*mutex_forks;
	pthread_mutex_t		mutex_print;
	int					all_philos;
	int					finish_eat_count;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
}				t_data;

int		ft_atoi(char *ptr);
long	get_time(void);
void	*ft_life_cycle(void	*ptr);
void	ft_usleep_fix(long must_time);
int		ft_create_thread_philo(t_data	*data);

#endif