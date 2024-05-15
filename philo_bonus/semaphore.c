/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:13:02 by mott              #+#    #+#             */
/*   Updated: 2024/05/15 14:07:41 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	init_philo(t_data *data, t_philo **philo)
// {
// 	int	i;

// 	*philo = malloc(sizeof(t_philo) * data->num_philo);
// 	if (*philo == NULL)
// 		return (ft_error("malloc"));
// 	// if (init_mutex(data, philo) == EXIT_FAILURE)
// 	// 	return (EXIT_FAILURE);
// 	i = 0;
// 	while (i < data->num_philo)
// 	{
// 		(*philo)[i].philo_id = i + 1;
// 		(*philo)[i].data = data;
// 		// if (i + 1 < data->num_philo)
// 		// 	(*philo)[i].right_fork = &(*philo)[i + 1].left_fork;
// 		// else
// 		// 	(*philo)[i].right_fork = &(*philo)[0].left_fork;
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);
// }

int	open_semaphore(t_data *data)
{
	data->forks = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR, data->num_philo);
	if (data->forks == SEM_FAILED)
		return (ft_error("sem_open"));
	data->printer = sem_open("/printer", O_CREAT, S_IRUSR | S_IWUSR, 1);
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
	if (sem_unlink("/forks") == -1)
		return (ft_error("sem_unlink"));
	if (sem_unlink("/printer") == -1)
		return (ft_error("sem_unlink"));
	return (EXIT_SUCCESS);
}
