/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:48:04 by mott              #+#    #+#             */
/*   Updated: 2024/05/22 21:09:10 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dinner_for_one(t_philo *philo)
{
	print_status(philo, FORK);
	ft_usleep(philo->data->time_to_die);
	philo_die(philo);
	return (NULL);
}

static void	wait_for_dinner(t_philo *philo)
{
	int	multi;

	multi = 1;
	if (philo->philo_id == philo->data->num_philo)
		multi = 2;
	if (philo->data->time_to_die < philo->data->time_to_eat * multi)
	{
		ft_usleep (philo->data->time_to_die);
		philo_die(philo);
	}
	else
		ft_usleep (philo->data->time_to_eat * multi);
}

static void	*start_routine(void *arg)
{
	t_philo	*philo;
	int		counter;

	philo = (t_philo *)arg;
	if (philo->data->num_philo == 1)
		return (dinner_for_one(philo));
	if (philo->philo_id % 2 != 0)
		wait_for_dinner(philo);
	counter = philo->data->num_eaten;
	while (true)
	{
		philo_eat(philo);
		counter--;
		if (counter == 0)
			philo->philo_full = true;
		philo_sleep(philo);
		philo_think(philo);
		pthread_mutex_lock(&philo->data->finish);
		if (philo->data->is_finish == true)
		{
			pthread_mutex_unlock(&philo->data->finish);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->finish);
	}
	return (NULL);
}

static void	eaten_monitor(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < philo[i]->data->num_philo)
	{
		if (philo[i]->philo_full == true)
			i++;
		if (philo[i]->data->is_finish == true)
			break ;
		ft_usleep(1000);
	}
	pthread_mutex_lock(&philo[i]->data->finish);
	philo[i]->data->is_finish = true;
	pthread_mutex_unlock(&philo[i]->data->finish);
}

int	pthread_create_join(int num_philo, t_philo **philo)
{
	pthread_t	*tid;
	int			i;

	tid = malloc(sizeof(pthread_t) * num_philo);
	if (tid == NULL)
		return (ft_error("malloc"));
	i = 0;
	while (i < num_philo)
	{
		if (pthread_create(&tid[i], NULL, &start_routine, &(*philo)[i]) != 0)
			return (ft_error("pthread_create"));
		i++;
	}
	if (philo[i]->data->num_eaten > 0)
		eaten_monitor(philo);
	i = 0;
	while (i < num_philo)
	{
		if (pthread_join(tid[i], NULL) != 0)
			return (ft_error("pthread_join"));
		i++;
	}
	free(tid);
	return (EXIT_SUCCESS);
}
