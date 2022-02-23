/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:18:51 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/06 16:23:16 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_start(t_data *data)
{
	int		i;

	i = 0;
	data->start_time = get_time();
	data->finish_eat_count = data->all_philos;
	while (i < data->all_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].count_eat = data->must_eat;
		data->philos[i].left_fork = &data->mutex_forks[i];
		data->philos[i].last_eat = get_time();
		if (i == data->all_philos - 1)
			data->philos[i].right_fork = &data->mutex_forks[0];
		else
			data->philos[i].right_fork = &data->mutex_forks[i + 1];
		if (pthread_create(&data->philos[i].thread, NULL, ft_life_cycle, \
			&data->philos[i]))
			return (1);
		usleep(30);
		i += 2;
		if (i >= data->all_philos && i % 2 == 0)
			i = 1;
	}
	return (0);
}

static int	ft_init_mutex(t_data	*data)
{
	int		i;

	i = 0;
	while (i < data->all_philos)
	{
		if (pthread_mutex_init(&data->mutex_forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->mutex_print, NULL))
		return (1);
	return (0);
}

int	ft_create_thread_philo(t_data	*data)
{
	data->philos = malloc(sizeof(t_philo) * data->all_philos);
	data->mutex_forks = malloc(sizeof(pthread_mutex_t) * data->all_philos);
	if (ft_init_mutex(data))
		return (1);
	if (ft_philo_start(data))
		return (1);
	return (0);
}
