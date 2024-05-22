/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:30:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/22 21:18:56 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_finish(t_philo *philo)
{
	bool	is_finish;

	pthread_mutex_lock(&philo->data->finish);
	is_finish = philo->data->is_finish;
	pthread_mutex_unlock(&philo->data->finish);
	return (is_finish);
}

void	philo_eat(t_philo *philo)
{
	if (is_finish(philo) == true)
		return ;
	philo_lock_forks(philo);
	print_status(philo, EAT);
	if (philo->data->time_to_eat >= philo->data->time_to_die)
	// ft_usleep; philo->data->time_to_die
		philo_die(philo);
	else
		ft_usleep(philo->data->time_to_eat);
	philo_unlock_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (is_finish(philo) == true)
		return ;
	print_status(philo, SLEEP);
	if (philo->data->time_to_eat + philo->data->time_to_sleep
		>= philo->data->time_to_die)
		// ft_usleep; philo->data->time_to_die - philo->data->time_to_eat
		philo_die(philo);
	else
		ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (is_finish(philo) == true)
		return ;
	print_status(philo, THINK);
}

void	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->finish);
	philo->data->is_finish = true;
	pthread_mutex_unlock(&philo->data->finish);
	print_status(philo, DIE);
}
