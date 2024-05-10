/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/10 16:21:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_error(const char *str)
{
	printf("Error: %s\n", str);
	return (EXIT_FAILURE);
}

// static void	print_status(void)
// {
	// printf("%d %d has taken a fork\n", 0, 0);
	// printf("%d %d is eating\n", 0, 0);
	// printf("%d %d is sleeping\n", 0, 0);
	// printf("%d %d is thinking\n", 0, 0);
	// printf("%d %d died\n", 0, 0);
// }

// static void	print_input(t_input *input)
// {
	// printf("num_philo: %d\n", input->num_philo);
	// printf("time_to_die: %d\n", input->time_to_die);
	// printf("time_to_eat: %d\n", input->time_to_eat);
	// printf("time_to_sleep: %d\n", input->time_to_sleep);
	// printf("num_eaten: %d\n", input->num_eaten);
// }

int	main(int argc, char **argv)
{
	t_input	input;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (ft_error("Wrong number of arguments"));
	if (parse_input(&input, argv) == EXIT_FAILURE)
		return (ft_error("Wrong input"));
	// print_input(&input);
	if (get_time(&input.start_time) == EXIT_FAILURE)
		return (ft_error("gettimeofday"));
	// printf("starttime: %ld\n", input.start_time);
	if (init_philo_mutex(input.num_philo, &philo) == EXIT_FAILURE)
		return (ft_error("mutex"));
	if (pthread_create_join(&input, &philo) == EXIT_FAILURE)
		return (ft_error("pthread"));
	// print_status();
	if (destroy_mutex(input.num_philo, &philo) == EXIT_FAILURE)
		return (ft_error("mutex"));
	system("leaks philo");
	return (EXIT_SUCCESS);
}
