/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:21:21 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/08 21:21:48 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thinking(t_philo *philo)
{
	sem_wait(philo->data->sem_print);
	printf("%ld\t%d is thinking\n", \
		get_time() - philo->data->start_time, philo->id);
	sem_post(philo->data->sem_print);
}

void	ft_sleep(t_philo *philo)
{
	sem_wait(philo->data->sem_print);
	printf("%ld\t%d is sleeping\n", \
		get_time() - philo->data->start_time, philo->id);
	sem_post(philo->data->sem_print);
	ft_usleep_fix(philo->data->time_sleep);
}

void	ft_eating(t_philo *philo)
{
	philo->last_eat = get_time();
	sem_wait(philo->data->sem_print);
	printf("%ld\t%d is eating\n", \
		get_time() - philo->data->start_time, philo->id);
	sem_post(philo->data->sem_print);
	ft_usleep_fix(philo->data->time_eat);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
	if (philo->count_eat > 0)
		philo->count_eat -= 1;
}

void	ft_take_forks(t_philo	*philo)
{
	sem_wait(philo->data->sem_forks);
	sem_wait(philo->data->sem_print);
	printf("%ld\t%d has taken left fork \n", \
		get_time() - philo->data->start_time, philo->id);
	sem_post(philo->data->sem_print);
	sem_wait(philo->data->sem_forks);
	sem_wait(philo->data->sem_print);
	printf("%ld\t%d has taken right fork \n", \
		get_time() - philo->data->start_time, philo->id);
	sem_post(philo->data->sem_print);
}
