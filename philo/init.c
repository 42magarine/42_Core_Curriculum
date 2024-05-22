/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:46:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/22 21:04:48 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Converts a string into an integer.
// Returns EXIT_FAILURE if it is > INT_MAX or not contains only digits or is 0.
static int	ft_atoi(int *n, char *str)
{
	*n = 0;
	while (*str >= '0' && *str <= '9')
	{
		*n = *n * 10 + *str - '0';
		if (*n < 0)
			return (EXIT_FAILURE);
		str++;
	}
	if (*str != '\0' || *n == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_data(t_data *data, char **argv)
{
	if (ft_atoi(&data->num_philo, argv[1]) == EXIT_FAILURE)
		return (ft_error("Invalid number of philosophers"));
	if (ft_atoi(&data->time_to_die, argv[2]) == EXIT_FAILURE)
		return (ft_error("Invalid number of time to die"));
	if (ft_atoi(&data->time_to_eat, argv[3]) == EXIT_FAILURE)
		return (ft_error("Invalid number of time to eat"));
	if (ft_atoi(&data->time_to_sleep, argv[4]) == EXIT_FAILURE)
		return (ft_error("Invalid number of time to sleep"));
	if (argv[5] != NULL && ft_atoi(&data->num_eaten, argv[5]) == EXIT_FAILURE)
		return (ft_error("Invalid number of times each philosopher must eat"));
	else if (argv[5] == NULL)
		data->num_eaten = -1;
	data->start_time = get_time();
	data->is_finish = false;
	return (EXIT_SUCCESS);
}

int	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * data->num_philo);
	if (*philo == NULL)
		return (ft_error("malloc"));
	if (init_mutex(data, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->num_philo)
	{
		(*philo)[i].philo_id = i + 1;
		if (i + 1 < data->num_philo)
			(*philo)[i].right_fork = &(*philo)[i + 1].left_fork;
		else
			(*philo)[i].right_fork = &(*philo)[0].left_fork;
		(*philo)[i].philo_full = false;
		(*philo)[i].data = data;
		i++;
	}
	return (EXIT_SUCCESS);
}
