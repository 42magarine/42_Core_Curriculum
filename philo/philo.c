/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:30:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/12 21:04:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_die(t_philo *philo, int time)
{
	if (philo->data->philo_died ==	true)
		return ;
	ft_usleep(time);
	philo->data->philo_died = true;
	print_status(philo, DIE);
}

void	philo_fork(t_philo *philo)
{
	if (philo->data->philo_died ==	true)
		return ;
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

void	philo_eat(t_philo *philo)
{
	// if (philo->data->philo_died ==	true)
	// 	return ;
	print_status(philo, EAT);
	if (philo->data->time_to_eat >= philo->data->time_to_die)
		philo_die(philo, philo->data->time_to_die);
	else
		ft_usleep(philo->data->time_to_eat);
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

void	philo_sleep(t_philo *philo)
{
	if (philo->data->philo_died ==	true)
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
	if (philo->data->philo_died ==	true)
		return ;
	print_status(philo, THINK);
}
