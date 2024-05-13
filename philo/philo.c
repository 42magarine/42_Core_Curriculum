/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:30:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/13 17:01:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_lock_forks(t_philo *philo)
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
		// usleep (thinking)
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->left_fork);
		print_status(philo, FORK);
	}
}

static void	philo_unlock_forks(t_philo *philo)
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

void	philo_eat(t_philo *philo)
{
	if (someone_died(philo) == true)
		return ;
	philo_lock_forks(philo);
	print_status(philo, EAT);
	if (philo->data->time_to_eat >= philo->data->time_to_die)
		philo_die(philo, philo->data->time_to_die);
	else
		ft_usleep(philo->data->time_to_eat);
	philo_unlock_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (someone_died(philo) == true)
		return ;
	print_status(philo, SLEEP);
	if (philo->data->time_to_eat + philo->data->time_to_sleep
		>= philo->data->time_to_die)
		philo_die(philo, philo->data->time_to_die - philo->data->time_to_eat);
	else
		ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (someone_died(philo) == true)
		return ;
	print_status(philo, THINK);
}
