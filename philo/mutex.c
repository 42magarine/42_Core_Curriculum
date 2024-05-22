/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:36:50 by mott              #+#    #+#             */
/*   Updated: 2024/05/22 21:10:48 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data, t_philo **philo)
{
	int	i;

	if (pthread_mutex_init(&data->printer, NULL) != 0)
		return (ft_error("pthread_mutex_init"));
	if (pthread_mutex_init(&data->finish, NULL) != 0)
		return (ft_error("pthread_mutex_init"));
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&(*philo)[i].left_fork, NULL) != 0)
			return (ft_error("pthread_mutex_init"));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_mutex(t_data *data, t_philo **philo)
{
	int	i;

	if (pthread_mutex_destroy(&data->printer) != 0)
		return (ft_error("pthread_mutex_destroy1"));
	if (pthread_mutex_destroy(&data->finish) != 0)
		return (ft_error("pthread_mutex_destroy2"));
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_destroy(&(*philo)[i].left_fork) != 0)
			return (ft_error("pthread_mutex_destroy3"));
		i++;
	}
	return (EXIT_SUCCESS);
}

void	philo_lock_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
	}
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->left_fork);
		print_status(philo, FORK);
	}
}

void	philo_unlock_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
	}
}
