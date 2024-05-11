/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:30:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/11 12:17:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_status(philo->philo_id, FORK);
	sleep(1);
	pthread_mutex_unlock(&philo->left_fork);
}

void	philo_eat(t_philo *philo)
{
	print_status(philo->philo_id, EAT);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo->philo_id, SLEEP);
}

void	philo_think(t_philo *philo)
{
	print_status(philo->philo_id, THINK);
}

void	philo_die(t_philo *philo)
{
	print_status(philo->philo_id, DIE);
}
