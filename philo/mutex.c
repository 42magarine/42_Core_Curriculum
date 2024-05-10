/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:36:50 by mott              #+#    #+#             */
/*   Updated: 2024/05/10 18:27:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_mutex(int num_philo, t_philo **philo)
{
	t_philo	*temp;
	int		i;

	*philo = malloc(sizeof(t_philo) * num_philo);
	if (*philo == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < num_philo)
	{
		temp = &(*philo)[i];
		temp->philo_id = i + 1;
		if (pthread_mutex_init(&temp->fork, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_mutex(int num_philo, t_philo **philo)
{
	t_philo	*temp;
	int		i;

	i = 0;
	while (i < num_philo)
	{
		temp = &(*philo)[i];
		if (pthread_mutex_destroy(&temp->fork) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(*philo);
	return (EXIT_SUCCESS);
}
