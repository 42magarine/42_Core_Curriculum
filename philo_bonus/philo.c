/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:43 by mott              #+#    #+#             */
/*   Updated: 2024/05/21 21:10:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_data *data, t_philo *philo)
{
	long	time;

	philo_lock_fork(data, philo);
	philo_lock_fork(data, philo);
	time = get_time() - data->start_time;
	if (time <= philo->last_meal + data->time_to_die)
	{
		philo->last_meal = time;
		print_status(data, EAT, time, philo->philo_id);
		ft_usleep(data->time_to_eat);
		philo_unlock_fork(data);
		philo_unlock_fork(data);
	}
	else
	{
		ft_usleep(data->time_to_die - time);
		philo_die(data, philo);
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
		ft_usleep(data->time_to_die - data->time_to_eat);
		philo_die(data, philo);
	}
}

void	philo_think(t_data *data, t_philo *philo)
{
	long	time;
	long	time_to_think;

	time = get_time() - data->start_time;
	time_to_think = data->time_to_die - data->time_to_eat - data->time_to_sleep;
	if (data->num_philo % 2 == 0)
	{
		print_status(data, THINK, time, philo->philo_id);
	}
	else
	{
		if (time + data->time_to_eat <= philo->last_meal + data->time_to_die)
		{
			ft_usleep(data->time_to_eat);
		}
		else
		{
			ft_usleep(data->time_to_die - data->time_to_eat - data->time_to_sleep);
			philo_die(data, philo);
		}
	}
}

void	philo_die(t_data *data, t_philo *philo)
{
	long	time;

	time = get_time() - data->start_time;
	if (sem_wait(data->printer) == -1)
		ft_error("sem_wait");
	printf("%ld %d died\n", time, philo->philo_id);
	if (sem_post(data->dead) == -1)
		ft_error("sem_post");
}
