/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:48:04 by mott              #+#    #+#             */
/*   Updated: 2024/05/10 18:26:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->fork);
	printf("Hello from Philosopher[%d]\n", philo->philo_id);
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}

int	pthread_create_join(int num_philo, t_philo **philo)
{
	pthread_t	*tid;
	t_philo		*temp;
	int			i;

	tid = malloc(sizeof(pthread_t) * num_philo);
	if (tid == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < num_philo)
	{
		temp = &(*philo)[i];
		if (pthread_create(&tid[i], NULL, &start_routine, temp) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < num_philo)
	{
		if (pthread_join(tid[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(tid);
	return (EXIT_SUCCESS);
}
