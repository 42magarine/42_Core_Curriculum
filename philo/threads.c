/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:48:04 by mott              #+#    #+#             */
/*   Updated: 2024/05/13 16:01:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dinner_for_one(t_philo *philo)
{
	print_status(philo, FORK);
	philo_die(philo, philo->data->time_to_die);
	return (NULL);
}

static void	*start_routine(void *arg)
{
	t_philo	*philo;
	int		counter;

	philo = (t_philo *)arg;
	if (philo->data->num_philo == 1)
		return (dinner_for_one(philo));
	counter = philo->data->num_eaten;
	pthread_mutex_lock(&philo->data->dead);
	while (philo->data->philo_died == false && counter != 0)
	{
		pthread_mutex_unlock(&philo->data->dead);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		counter--;
		pthread_mutex_lock(&philo->data->dead);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (NULL);
}

void	philo_die(t_philo *philo, int time)
{
	ft_usleep(time);
	if (someone_died(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->dead);
	philo->data->philo_died = true;
	pthread_mutex_unlock(&philo->data->dead);
	print_status(philo, DIE);
}

bool	someone_died(t_philo *philo)
{
	bool	someone_died;

	pthread_mutex_lock(&philo->data->dead);
	someone_died = philo->data->philo_died;
	pthread_mutex_unlock(&philo->data->dead);
	return (someone_died);
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
