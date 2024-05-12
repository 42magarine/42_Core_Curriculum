/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:36:50 by mott              #+#    #+#             */
/*   Updated: 2024/05/12 21:05:48 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->printer, NULL) != 0)
		return (ft_error("mutex_init"));
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&(*philo)[i].left_fork, NULL) != 0)
			return (ft_error("mutex_init"));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_philo_mutex(t_data *data, t_philo **philo)
{
	int		i;

	*philo = malloc(sizeof(t_philo) * data->num_philo);
	if (*philo == NULL)
		return (ft_error("malloc"));
	if (init_mutex(data, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->num_philo)
	{
		(*philo)[i].philo_id = i + 1;
		(*philo)[i].data = data;
		if (i + 1 < data->num_philo)
			(*philo)[i].right_fork = &(*philo)[i + 1].left_fork;
		else
			(*philo)[i].right_fork = &(*philo)[0].left_fork;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_mutex(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&data->printer) != 0)
		return (ft_error("mutex_destroy"));
	while (i < data->num_philo)
	{
		if (pthread_mutex_destroy(&(*philo)[i].left_fork) != 0)
			return (ft_error("mutex_destroy"));
		i++;
	}
	free(*philo);
	return (EXIT_SUCCESS);
}
