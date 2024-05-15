/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:17:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/15 17:37:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dinner_for_one(t_data *data, int philo_id)
{
	philo_lock_fork(data, philo_id);
	ft_usleep(data->time_to_die);
	philo_die(data, philo_id);
}

static void	start_routine(t_data *data, t_philo *philo)
{
	int	counter;

	if (data->num_philo == 1)
		return (dinner_for_one(data, philo->philo_id));
	if (philo->philo_id % 2 == 0)
		ft_usleep (data->time_to_eat);
	counter = data->num_eaten;
	// pthread_mutex_lock(&philo->data->dead);
	while (data->someone_died == false && counter != 0)
	{
		// pthread_mutex_unlock(&philo->data->dead);
		philo_eat(data, philo);
		philo_sleep(data, philo);
		philo_think(data, philo);
		counter--;
		// pthread_mutex_lock(&philo->data->dead);
	}
	// pthread_mutex_unlock(&philo->data->dead);
}

int	create_child_process(t_data *data, t_philo **philo)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < data->num_philo)
	{
		pid = fork();
		if (pid == -1)
			return (ft_error("fork"));
		else if (pid == 0)
		{
			start_routine(data, &(*philo)[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
	return (EXIT_SUCCESS);
}
