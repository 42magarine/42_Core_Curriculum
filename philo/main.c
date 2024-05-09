/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/09 20:20:35 by mott             ###   ########.fr       */
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

	if (argc < 5 || argc > 6)
		return (ft_error("Wrong number of arguments"));
	if (parse_input(&input, argv) == EXIT_FAILURE)
		return (ft_error("Wrong input"));
	input.start_time = get_time();
	if (input.start_time == -1)
		return (ft_error("gettimeofday"));
	pthread_create_join(&input);
	// printf("starttime: %ld\n", input.start_time);
	// print_input(&input);
	// print_status();
	return (EXIT_SUCCESS);
}
