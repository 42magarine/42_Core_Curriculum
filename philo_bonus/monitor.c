/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:54:45 by mott              #+#    #+#             */
/*   Updated: 2024/05/23 15:32:49 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_philos(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		kill((*philo)[i].philo_pid, SIGKILL);
		i++;
	}
}

static void	*dead_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	if (sem_wait(data->dead) == -1)
		ft_error("sem_wait");
	if (sem_post(data->finish) == -1)
		ft_error("sem_post");
	i = 0;
	while (i < data->num_philo)
	{
		if (sem_post(data->eaten) == -1)
			ft_error("sem_post");
		i++;
	}
	return (NULL);
}

static void	*eaten_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->num_philo)
	{
		if (sem_wait(data->eaten) == -1)
			ft_error("sem_wait");
		i++;
	}
	if (sem_post(data->finish) == -1)
		ft_error("sem_post");
	if (sem_post(data->dead) == -1)
		ft_error("sem_post");
	return (NULL);
}

int	monitor_threads(t_data *data, t_philo **philo)
{
	pthread_t	tid_dead;
	pthread_t	tid_eaten;

	if (pthread_create(&tid_dead, NULL, &dead_monitor, data) != 0)
		return (ft_error("pthread_create"));
	if (pthread_detach(tid_dead) != 0)
		return (ft_error("pthread_detach"));
	if (data->num_eaten > 0)
	{
		if (pthread_create(&tid_eaten, NULL, &eaten_monitor, data) != 0)
			return (ft_error("pthread_create"));
		if (pthread_detach(tid_eaten) != 0)
			return (ft_error("pthread_detach"));
	}
	if (sem_wait(data->finish) == -1)
		ft_error("sem_wait");
	kill_philos(data, philo);
	return (EXIT_SUCCESS);
}
