/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:17:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/24 17:41:16 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dinner_for_one(t_data *data, t_philo *philo)
{
	print_status(data, FORK, philo->philo_id);
	ft_usleep(data->time_to_die);
	philo_die(data, philo);
}

static void	wait_for_dinner(t_data *data, t_philo *philo)
{
	int	multi;

	multi = 1;
	if (philo->philo_id == data->num_philo)
		multi = 2;
	if (data->time_to_die < data->time_to_eat * multi)
	{
		ft_usleep(data->time_to_die);
		philo_die(data, philo);
	}
	else
		ft_usleep(data->time_to_eat * multi);
}

static void	start_routine(t_data *data, t_philo *philo)
{
	int	counter;

	if (data->num_philo == 1)
		return (dinner_for_one(data, philo));
	if (philo->philo_id % 2 != 0)
		wait_for_dinner(data, philo);
	counter = data->num_eaten;
	while (true)
	{
		philo_eat(data, philo);
		counter--;
		if (counter == 0)
		{
			if (sem_post(data->eaten) == -1)
				ft_error("sem_wait");
		}
		philo_sleep(data, philo);
		philo_think(data, philo);
	}
}

int	create_child_process(t_data *data, t_philo **philo)
{
	int	i;

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
	if (monitor_threads(data, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
	return (EXIT_SUCCESS);
}
