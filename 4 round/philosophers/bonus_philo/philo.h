/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:01:15 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/08 22:37:14 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	pthread_t			thread;
	pid_t				pid;
	int					id;
	struct s_data		*data;
	int					count_eat;
	long				last_eat;
}				t_philo;

typedef struct s_data
{
	long				start_time;
	t_philo				*philos;
	sem_t				*sem_forks;
	sem_t				*sem_print;
	int					all_philos;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	int					some_pid;
}				t_data;

int		ft_atoi(char *ptr);
long	get_time(void);
void	*ft_life_cycle(void	*ptr);
void	ft_usleep_fix(long must_time);
void	*ft_monitoring(void		*phil);
void	ft_start_process(void	*phil);
void	ft_create_philos(t_data	*data);
void	ft_init(t_data	*data);
int		ft_kill_pid(t_data	*data);
void	ft_take_forks(t_philo	*philo);
void	ft_eating(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_thinking(t_philo *philo);

#endif