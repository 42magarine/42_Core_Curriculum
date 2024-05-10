/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:36:50 by mott              #+#    #+#             */
/*   Updated: 2024/05/10 16:17:39 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_mutex(int num_philo, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * num_philo);
	if (*philo == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < num_philo)
	{
		philo[i]->id_philo = i + 1;
		if (pthread_mutex_init(&philo[i]->fork, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_mutex(int num_philo, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		if (pthread_mutex_destroy(&philo[i]->fork) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(*philo);
	return (EXIT_SUCCESS);
}
