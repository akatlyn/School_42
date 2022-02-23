/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:54:59 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/16 13:05:06 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitoring(void		*phil)
{
	t_philo		*philo;

	philo = (t_philo *)phil;
	while (1)
	{
		if (get_time() - philo->last_eat > philo->data->time_die)
		{
			sem_wait(philo->data->sem_print);
			printf("At %ld, philo %d is dead\n", \
			get_time() - philo->data->start_time, philo->id);
			exit(1);
		}
	}
}

void	ft_start_process(void	*phil)
{
	t_philo		*philo;

	philo = (t_philo *)phil;
	if (pthread_create(&philo->thread, NULL, ft_monitoring, philo))
		exit(1);
	while (1)
	{
		if (!philo->count_eat)
			exit(0);
		ft_take_forks(philo);
		ft_eating(philo);
		ft_sleep(philo);
		ft_thinking(philo);
	}
}

void	ft_create_philos(t_data	*data)
{
	int		i;
	pid_t	pid;

	i = 0;
	data->start_time = get_time();
	while (i < data->all_philos)
	{
		data->philos[i].count_eat = data->must_eat;
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].last_eat = get_time();
		pid = fork();
		if (pid == 0)
		{
			ft_start_process(&data->philos[i]);
			usleep(100);
		}
		else
			data->philos[i].pid = pid;
		i++;
	}
}

void	ft_init(t_data	*data)
{
	data->philos = malloc(sizeof(t_philo) * data->all_philos);
	sem_unlink("forks");
	sem_unlink("print");
	data->sem_forks = sem_open("forks", O_CREAT, 0644, data->all_philos);
	data->sem_print = sem_open("print", O_CREAT, 0644, 1);
	ft_create_philos(data);
}

int	ft_kill_pid(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->all_philos)
	{
		waitpid(-1, &data->some_pid, 0);
		if (WEXITSTATUS(data->some_pid))
		{
			while (j < data->all_philos)
				kill(data->philos[j++].pid, SIGKILL);
			return (0);
		}
		i++;
	}
	printf("All philos eated\n");
	return (0);
}
