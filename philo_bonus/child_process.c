/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:17:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/15 13:21:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_routine(t_data *data, int philo_id)
{
	int	counter;

	// if (philo->data->num_philo == 1)
	// 	return (dinner_for_one(philo));
	counter = data->num_eaten;
	// pthread_mutex_lock(&philo->data->dead);
	while (data->someone_died == false && counter != 0)
	{
		// pthread_mutex_unlock(&philo->data->dead);
		printf("Hello from philosopher [%d]\n", philo_id);
		philo_eat(data, philo_id);
		philo_sleep(data, philo_id);
		philo_think(data, philo_id);
		counter--;
		// pthread_mutex_lock(&philo->data->dead);
	}
	// pthread_mutex_unlock(&philo->data->dead);
}

int	create_child_process(t_data *data)
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
			start_routine(data, i + 1);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
	return (EXIT_SUCCESS);
}
