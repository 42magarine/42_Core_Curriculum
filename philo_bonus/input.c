/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:59:22 by mott              #+#    #+#             */
/*   Updated: 2024/05/14 11:59:39 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (get_time(&data->start_time) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->philo_died = false;
	return (EXIT_SUCCESS);
}
