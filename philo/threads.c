/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:48:04 by mott              #+#    #+#             */
/*   Updated: 2024/05/11 19:34:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->philo_died == false)
	{
		if (philo->data->philo_died == true)
			break ;
		philo_fork(philo);
		philo_eat(philo);
		if (philo->data->philo_died == true)
			break ;
		philo_sleep(philo);
		if (philo->data->philo_died == true)
			break ;
		philo_think(philo);
	}
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
