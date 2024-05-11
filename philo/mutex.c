/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:36:50 by mott              #+#    #+#             */
/*   Updated: 2024/05/11 16:04:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_mutex(t_data *data, t_philo **philo)
{
	t_philo	*temp;
	t_philo	*temp2;
	int		i;

	*philo = malloc(sizeof(t_philo) * data->num_philo);
	if (*philo == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->num_philo)
	{
		temp = &(*philo)[i];
		temp->philo_id = i + 1;
		temp->last_meal = 0;
		temp->data = data;
		if (pthread_mutex_init(&temp->left_fork, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		temp = &(*philo)[i];
		if (i + 1 < data->num_philo)
			temp2 = &(*philo)[i + 1];
		else
			temp2 = &(*philo)[0];
		temp->right_fork = &temp2->left_fork;
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
		if (pthread_mutex_destroy(&temp->left_fork) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(*philo);
	return (EXIT_SUCCESS);
}
