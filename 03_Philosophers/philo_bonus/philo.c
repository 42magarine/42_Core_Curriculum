/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:43 by mott              #+#    #+#             */
/*   Updated: 2024/05/25 13:27:32 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_data *data, t_philo *philo)
{
	long	time;

	if (sem_wait(data->forks) == -1)
		ft_error("sem_wait");
	print_status(data, FORK, philo->philo_id);
	if (sem_wait(data->forks) == -1)
		ft_error("sem_wait");
	print_status(data, FORK, philo->philo_id);
	time = print_status(data, EAT, philo->philo_id);
	if (time <= philo->last_meal + data->time_to_die)
	{
		philo->last_meal = time;
		ft_usleep(data->time_to_eat);
		if (sem_post(data->forks) == -1)
			ft_error("sem_post");
		if (sem_post(data->forks) == -1)
			ft_error("sem_post");
	}
	else
	{
		ft_usleep(philo->last_meal + data->time_to_die - time);
		philo_die(data, philo);
	}
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	long	time;

	time = print_status(data, SLEEP, philo->philo_id);
	if (time + data->time_to_sleep <= philo->last_meal + data->time_to_die)
		ft_usleep(data->time_to_sleep);
	else
	{
		ft_usleep(philo->last_meal + data->time_to_die - time);
		philo_die(data, philo);
	}
}

void	philo_think(t_data *data, t_philo *philo)
{
	long	time;

	time = print_status(data, THINK, philo->philo_id);
	if (time + data->time_to_think < philo->last_meal + data->time_to_die)
		ft_usleep(data->time_to_think);
	else
	{
		ft_usleep(philo->last_meal + data->time_to_die - time);
		philo_die(data, philo);
	}
}

void	philo_die(t_data *data, t_philo *philo)
{
	print_status(data, DIE, philo->philo_id);
	if (sem_post(data->dead) == -1)
		ft_error("sem_post");
}
