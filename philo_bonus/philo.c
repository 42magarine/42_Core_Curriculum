/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:43 by mott              #+#    #+#             */
/*   Updated: 2024/05/14 15:53:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	// if (someone_died(philo) == true)
	// 	return ;
	// philo_lock_forks(philo);
	print_status(philo, EAT);
	if (philo->data->time_to_eat >= philo->data->time_to_die)
		philo_die(philo, philo->data->time_to_die);
	else
		ft_usleep(philo->data->time_to_eat);
	// philo_unlock_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	// if (someone_died(philo) == true)
	// 	return ;
	print_status(philo, SLEEP);
	if (philo->data->time_to_eat + philo->data->time_to_sleep
		>= philo->data->time_to_die)
		philo_die(philo, philo->data->time_to_die - philo->data->time_to_eat);
	else
		ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	// if (someone_died(philo) == true)
	// 	return ;
	print_status(philo, THINK);
}

void	philo_die(t_philo *philo, int time)
{
	ft_usleep(time);
	// if (someone_died(philo) == true)
	// 	return ;
	// pthread_mutex_lock(&philo->data->dead);
	philo->data->someone_died = true;
	// pthread_mutex_unlock(&philo->data->dead);
	print_status(philo, DIE);
}
