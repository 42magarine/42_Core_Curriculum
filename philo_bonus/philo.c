/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:43 by mott              #+#    #+#             */
/*   Updated: 2024/05/16 20:04:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_data *data, t_philo *philo)
{
	long	time;

	time = get_time() - data->start_time;
	if (time < philo->last_meal + data->time_to_die)
	{
		philo_lock_fork(data, time, philo->philo_id);
		philo_lock_fork(data, time, philo->philo_id);
		philo->last_meal = time;
		print_status(data, EAT, time, philo->philo_id);
		ft_usleep(data->time_to_eat);
		philo_unlock_fork(data);
		philo_unlock_fork(data);
	}
	else
	{
		ft_usleep(data->time_to_die - time);
		philo_die(data, philo->philo_id);
		// return ;
	}
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	long	time;

	time = get_time() - data->start_time;
	if (time + data->time_to_sleep <= philo->last_meal + data->time_to_die)
	{
		print_status(data, SLEEP, time, philo->philo_id);
		ft_usleep(data->time_to_sleep);
	}
	else
	{
		ft_usleep(data->time_to_die - time);
		philo_die(data, philo->philo_id);
		// return ;
	}
}

void	philo_think(t_data *data, t_philo *philo)
{
	long	time;

	time = get_time() - data->start_time;
	if (time <= philo->last_meal + data->time_to_die)
	{
		print_status(data, THINK, time, philo->philo_id);
	}
}

void	philo_die(t_data *data, int philo_id)
{
	long	time;

	if (sem_wait(data->printer) == -1)
		ft_error("sem_post");
	time = get_time() - data->start_time;
	printf("%ld %d died\n", time, philo_id);
	// print_status(data, DIE, time, philo_id);
	if (sem_post(data->dead) == -1)
		ft_error("sem_post");
	exit(EXIT_SUCCESS);
}
