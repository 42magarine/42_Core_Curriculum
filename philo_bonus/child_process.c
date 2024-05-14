/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:17:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/14 15:47:07 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_routine(t_philo *philo)
{
	int	counter;

	// if (philo->data->num_philo == 1)
	// 	return (dinner_for_one(philo));
	counter = philo->data->num_eaten;
	// pthread_mutex_lock(&philo->data->dead);
	while (philo->data->someone_died == false && counter != 0)
	{
		// pthread_mutex_unlock(&philo->data->dead);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		counter--;
		// pthread_mutex_lock(&philo->data->dead);
	}
	// pthread_mutex_unlock(&philo->data->dead);
}

int	create_child_process(int num_philo, t_philo **philo)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < num_philo)
	{
		pid = fork();
		if (pid == -1)
			return (ft_error("fork"));
		else if (pid == 0)
			start_routine(philo[i]);
		i++;
	}
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
	return (EXIT_SUCCESS);
}
