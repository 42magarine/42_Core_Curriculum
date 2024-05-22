/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:13:02 by mott              #+#    #+#             */
/*   Updated: 2024/05/22 21:03:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	unlink_semaphore(void)
{
	if (sem_unlink("/forks") == -1)
		return (ft_error("sem_unlink"));
	if (sem_unlink("/printer") == -1)
		return (ft_error("sem_unlink"));
	if (sem_unlink("/dead") == -1)
		return (ft_error("sem_unlink"));
	if (sem_unlink("/eaten") == -1)
		return (ft_error("sem_unlink"));
	if (sem_unlink("/finish") == -1)
		return (ft_error("sem_unlink"));
	return (EXIT_SUCCESS);
}

int	open_semaphore(t_data *data)
{
	data->forks = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR,
			data->num_philo);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	data->printer = sem_open("/printer", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	data->dead = sem_open("/dead", O_CREAT, S_IRUSR | S_IWUSR, 0);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	data->eaten = sem_open("/eaten", O_CREAT, S_IRUSR | S_IWUSR, 0);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	data->finish = sem_open("/finish", O_CREAT, S_IRUSR | S_IWUSR, 0);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	return (unlink_semaphore());
}

int	close_semaphore(t_data *data)
{
	if (sem_close(data->forks) == -1)
		return (ft_error("sem_close"));
	if (sem_close(data->printer) == -1)
		return (ft_error("sem_close"));
	if (sem_close(data->dead) == -1)
		return (ft_error("sem_close"));
	if (sem_close(data->eaten) == -1)
		return (ft_error("sem_close"));
	if (sem_close(data->finish) == -1)
		return (ft_error("sem_close"));
	return (EXIT_SUCCESS);
}

void	philo_lock_fork(t_data *data, t_philo *philo)
{
	long	time;

	if (sem_wait(data->forks) == -1)
		ft_error("sem_wait");
	time = get_time() - data->start_time;
	if (time <= philo->last_meal + data->time_to_die)
	{
		print_status(data, FORK, philo->philo_id);
	}
	else
	{
		// ft_usleep(data->time_to_die - time);
		philo_die(data, philo);
	}
}

void	philo_unlock_fork(t_data *data)
{
	if (sem_post(data->forks) == -1)
		ft_error("sem_post");
}
