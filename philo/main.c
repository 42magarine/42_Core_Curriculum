/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/11 15:36:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_error(const char *str)
{
	printf("Error: %s\n", str);
	return (EXIT_FAILURE);
}

// static void	print_input(t_data *data)
// {
	// printf("num_philo: %d\n", data->num_philo);
	// printf("time_to_die: %d\n", data->time_to_die);
	// printf("time_to_eat: %d\n", data->time_to_eat);
	// printf("time_to_sleep: %d\n", data->time_to_sleep);
	// printf("num_eaten: %d\n", data->num_eaten);
// }

int	print_status(t_philo *philo, t_status status)
{
	long	time;

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
		printf("\x1b[33m%ld %d died\n\x1b[0m", time, philo->philo_id);
		// printf("%ld %d died\n", time, philo->philo_id);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (ft_error("Wrong number of arguments"));
	if (parse_input(&data, argv) == EXIT_FAILURE)
		return (ft_error("Wrong data"));
	// print_input(&data);
	if (get_time(&data.start_time) == EXIT_FAILURE)
		return (ft_error("gettimeofday"));
	// printf("starttime: %ld\n", data.start_time);
	if (init_philo_mutex(&data, &philo) == EXIT_FAILURE)
		return (ft_error("mutex"));
	if (pthread_create_join(data.num_philo, &philo) == EXIT_FAILURE)
		return (ft_error("pthread"));
	if (destroy_mutex(data.num_philo, &philo) == EXIT_FAILURE)
		return (ft_error("mutex"));
	// system("leaks philo");
	return (EXIT_SUCCESS);
}
