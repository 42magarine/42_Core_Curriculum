/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:30:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/24 17:06:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	long	time;

	philo_lock_forks(philo);
	time = print_status(philo, EAT);
	if (time <= philo->last_meal + philo->data->time_to_die)
	{
		philo->last_meal = time;
		ft_usleep(philo->data->time_to_eat);
	}
	else
	{
		ft_usleep(philo->last_meal + philo->data->time_to_die - time);
		philo_die(philo);
	}
	philo_unlock_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	long	time;

	time = print_status(philo, SLEEP);
	if (time + philo->data->time_to_sleep
		<= philo->last_meal + philo->data->time_to_die)
		ft_usleep(philo->data->time_to_sleep);
	else
	{
		ft_usleep(philo->last_meal + philo->data->time_to_die - time);
		philo_die(philo);
	}
}

void	philo_think(t_philo *philo)
{
	long	time;

	time = print_status(philo, THINK);
	if (time + philo->data->time_to_think
		< philo->last_meal + philo->data->time_to_die)
		ft_usleep(philo->data->time_to_think);
	else
	{
		ft_usleep(philo->last_meal + philo->data->time_to_die - time);
		philo_die(philo);
	}
}

void	philo_die(t_philo *philo)
{
	print_status(philo, DIE);
	pthread_mutex_lock(&philo->data->finish);
	philo->data->is_finish = true;
	pthread_mutex_unlock(&philo->data->finish);
}

bool	philo_finish(t_philo *philo)
{
	bool	is_finish;

	pthread_mutex_lock(&philo->data->finish);
	is_finish = philo->data->is_finish;
	pthread_mutex_unlock(&philo->data->finish);
	return (is_finish);
}
