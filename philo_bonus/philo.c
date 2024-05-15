/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:43 by mott              #+#    #+#             */
/*   Updated: 2024/05/15 14:17:59 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_data *data, int philo_id)
{
	// if (someone_died(philo) == true)
	// 	return ;
	// philo_lock_forks(philo);
	print_status(data, philo_id, EAT);
	if (data->time_to_eat >= data->time_to_die)
		philo_die(data, data->time_to_die, philo_id);
	else
		ft_usleep(data->time_to_eat);
	// philo_unlock_forks(philo);
}

void	philo_sleep(t_data *data, int philo_id)
{
	// if (someone_died(philo) == true)
	// 	return ;
	print_status(data, philo_id, SLEEP);
	if (data->time_to_eat + data->time_to_sleep	>= data->time_to_die)
		philo_die(data, data->time_to_die - data->time_to_eat, philo_id);
	else
		ft_usleep(data->time_to_sleep);
}

void	philo_think(t_data *data, int philo_id)
{
	// if (someone_died(philo) == true)
	// 	return ;
	print_status(data, philo_id, THINK);
}

void	philo_die(t_data *data, int philo_id, int time)
{
	ft_usleep(time);
	// if (someone_died(philo) == true)
	// 	return ;
	// pthread_mutex_lock(&philo->data->dead);
	data->someone_died = true;
	// pthread_mutex_unlock(&philo->data->dead);
	print_status(data, philo_id, DIE);
}
