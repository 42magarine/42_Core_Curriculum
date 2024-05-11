/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:30:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/11 16:44:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo *philo)
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

void	philo_eat(t_philo *philo)
{
	print_status(philo, EAT);
	if (get_time(&philo->last_meal) == EXIT_FAILURE)
		return ;
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
	print_status(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, THINK);
}

void	philo_die(t_philo *philo)
{
	long	time;

	if (get_time(&time) == EXIT_FAILURE)
		return ;
	// printf("time: %ld\n", time);
	// printf("philo->last_meal: %ld\n", philo->last_meal);
	// printf("philo->data->time_to_die: %d\n", philo->data->time_to_die);
	if (time > philo->last_meal + philo->data->time_to_die)
	{
		philo->data->philo_died = true;
		print_status(philo, DIE);
	}
}
