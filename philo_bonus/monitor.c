/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:54:45 by mott              #+#    #+#             */
/*   Updated: 2024/05/21 21:13:27 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitor_function(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	if (sem_wait(data->dead) == -1)
		ft_error("sem_wait");
	i = 0;
	while (i < data->num_philo)
	{
		printf("pid: %d\n", data->philo[i].philo_pid);
		kill(data->philo[i].philo_pid, SIGKILL);
		i++;
	}
	return (NULL);
}

int	monitor_thread(t_data *data, t_philo **philo)
{
	pthread_t	tid;

	data->philo = *philo;
	if (pthread_create(&tid, NULL, &monitor_function, data) != 0)
		return (ft_error("pthread_create"));
	// if (pthread_join(tid, NULL) != 0)
	// 	return (ft_error("pthread_join"));
	if (pthread_detach(tid) != 0)
		return (ft_error("pthread_detach"));
	return (EXIT_SUCCESS);
}
