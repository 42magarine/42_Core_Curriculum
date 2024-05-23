/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:36:50 by mott              #+#    #+#             */
/*   Updated: 2024/05/23 19:37:20 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data, t_philo **philo)
{
	int	i;

	if (pthread_mutex_init(&data->printer, NULL) != 0)
		return (ft_error("pthread_mutex_init"));
	if (pthread_mutex_init(&data->finish, NULL) != 0)
		return (ft_error("pthread_mutex_init"));
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&(*philo)[i].left_fork, NULL) != 0)
			return (ft_error("pthread_mutex_init"));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_mutex(t_data *data, t_philo **philo)
{
	int	i;

	if (pthread_mutex_destroy(&data->printer) != 0)
		return (ft_error("pthread_mutex_destroy1"));
	if (pthread_mutex_destroy(&data->finish) != 0)
		return (ft_error("pthread_mutex_destroy2"));
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_destroy(&(*philo)[i].left_fork) != 0)
			return (ft_error("pthread_mutex_destroy3"));
		i++;
	}
	return (EXIT_SUCCESS);
}
