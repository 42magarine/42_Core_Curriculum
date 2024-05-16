/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:17:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/16 20:09:55 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dinner_for_one(t_data *data, int philo_id)
{
	long	time;

	time = get_time() - data->start_time;
	philo_lock_fork(data, time, philo_id);
	ft_usleep(data->time_to_die - time);
	philo_die(data, philo_id);
}

static void	wait_for_dinner(t_data *data, int philo_id)
{
	int	multi;

	multi = 1;
	if (philo_id == data->num_philo)
		multi = 2;
	if (data->time_to_die < data->time_to_eat * multi)
	{
		ft_usleep (data->time_to_die);
		philo_die(data, philo_id);
	}
	else
		ft_usleep (data->time_to_eat * multi);
}

static void	start_routine(t_data *data, t_philo *philo)
{
	int	counter;

	if (data->num_philo == 1)
		return (dinner_for_one(data, philo->philo_id));
	if (philo->philo_id % 2 != 0)
		wait_for_dinner(data, philo->philo_id);
	counter = data->num_eaten;
	while (counter != 0)
	{
		philo_eat(data, philo);
		philo_sleep(data, philo);
		philo_think(data, philo);
		counter--;
	}
}

int	create_child_process(t_data *data, t_philo **philo)
{
	int	i;

	data->start_time = get_time();
	i = 0;
	while (i < data->num_philo)
	{
		(*philo)[i].philo_pid = fork();
		if ((*philo)[i].philo_pid == -1)
			return (ft_error("fork"));
		else if ((*philo)[i].philo_pid == 0)
		{
			start_routine(data, &(*philo)[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}

		sem_wait(data->dead);
	i = 0;
	while (i < data->num_philo)
	{
		kill((*philo)[i].philo_pid, SIGKILL);
		i++;
	}
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
	return (EXIT_SUCCESS);
}
