/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:03:01 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/08 21:17:23 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker_args(t_data	*data, int argc, char **argv)
{
	if (argc > 6 || argc < 5)
		return (1);
	data->all_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (data->all_philos > 200 || data->all_philos <= 0 \
		|| data->time_die <= 0 || data->time_eat <= 0 || data->time_sleep <= 0)
		return (1);
	data->must_eat = -1;
	if (argc == 6)
	{
		data->must_eat = ft_atoi(argv[5]);
		if (data->must_eat <= 0)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (checker_args(&data, ac, av))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	ft_init(&data);
	ft_kill_pid(&data);
	sem_unlink("forks");
	sem_unlink("print");
	return (0);
}
