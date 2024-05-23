/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:13:02 by mott              #+#    #+#             */
/*   Updated: 2024/05/23 19:37:09 by mott             ###   ########.fr       */
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
