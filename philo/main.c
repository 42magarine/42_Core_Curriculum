/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/13 13:34:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (ft_error("Invalid number of arguments"));
	if (init_data(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_philo_mutex(&data, &philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pthread_create_join(data.num_philo, &philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (destroy_mutex(&data, &philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// system("leaks philo");
	return (EXIT_SUCCESS);
}

int	print_status(t_philo *philo, t_status status)
{
	long	time;

	pthread_mutex_lock(&philo->data->printer);
	if (get_time(&time) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	time -= philo->data->start_time;
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, philo->philo_id);
	else if (status == EAT)
		printf("%ld %d is eating\n", time, philo->philo_id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, philo->philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, philo->philo_id);
	else if (status == DIE)
		printf("%ld %d died\n", time, philo->philo_id);
	pthread_mutex_unlock(&philo->data->printer);
	return (EXIT_SUCCESS);
}

int	ft_error(char *str)
{
	printf("\x1b[31mError: %s!\n\x1b[0m", str);
	return (EXIT_FAILURE);
}
