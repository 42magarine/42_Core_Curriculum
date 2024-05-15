/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:13:02 by mott              #+#    #+#             */
/*   Updated: 2024/05/15 17:57:19 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	open_semaphore(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/printer");
	sem_unlink("/dead");

	data->forks = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR, data->num_philo);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	data->printer = sem_open("/printer", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	data->dead = sem_open("/dead", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	return (EXIT_SUCCESS);
}

int	unlink_semaphore(t_data *data)
{
	if (sem_close(data->forks) == -1)
		ft_error("sem_close");
	if (sem_close(data->printer) == -1)
		ft_error("sem_close");
	if (sem_close(data->dead) == -1)
		ft_error("sem_close");
	if (sem_unlink("/forks") == -1)
		return (ft_error("sem_unlink"));
	if (sem_unlink("/printer") == -1)
		return (ft_error("sem_unlink"));
	if (sem_unlink("/dead") == -1)
		return (ft_error("sem_unlink"));
	return (EXIT_SUCCESS);
}

void	philo_lock_fork(t_data *data, int philo_id)
{
	long	time;

	if (sem_wait(data->forks) == -1)
		ft_error("sem_wait");
	time = get_time() - data->start_time;
	print_status(data, FORK, time, philo_id);
}

void	philo_unlock_fork(t_data *data)
{
	if (sem_post(data->forks) == -1)
		ft_error("sem_post");
}
