/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:48:04 by mott              #+#    #+#             */
/*   Updated: 2024/05/12 20:58:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start_routine(void *arg)
{
	t_philo	*philo;
	int		counter;

	philo = (t_philo *)arg;
	counter = philo->data->num_eaten;
	while (philo->data->philo_died == false && counter != 0)
	{
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		counter--;
	}
	return (NULL);
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
