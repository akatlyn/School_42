/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:21:21 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/06 16:23:45 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%ld\t%d is thinking\n", \
		get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

static void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%ld\t%d is sleeping\n", \
		get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_print);
	ft_usleep_fix(philo->data->time_sleep);
}

static void	ft_eating(t_philo *philo)
{
	philo->last_eat = get_time();
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%ld\t%d is eating\n", \
		get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_print);
	ft_usleep_fix(philo->data->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->count_eat > 0)
		philo->count_eat -= 1;
}

static void	ft_take_forks(t_philo	*philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%ld\t%d has taken left fork \n", \
		get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_print);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%ld\t%d has taken right fork \n", \
		get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	*ft_life_cycle(void		*ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	while (1)
	{
		if (!philo->count_eat)
		{
			philo->data->finish_eat_count -= 1;
			break ;
		}
		ft_take_forks(philo);
		ft_eating(philo);
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (NULL);
}
