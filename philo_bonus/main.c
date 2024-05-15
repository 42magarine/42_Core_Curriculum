/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/15 14:17:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (ft_error("Invalid number of arguments"));
	if (init_data(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (open_semaphore(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_child_process(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (unlink_semaphore(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// system("leaks philo");
	return (EXIT_SUCCESS);
}

void	print_status(t_data *data, int philo_id, t_status status)
{
	long	time;

	if (sem_wait(data->printer) == -1)
		ft_error("sem_wait");
	time = get_time() - data->start_time;
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, philo_id);
	else if (status == EAT)
		printf("%ld %d is eating\n", time, philo_id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, philo_id);
	else if (status == DIE)
		printf("%ld %d died\n", time, philo_id);
	if (sem_post(data->printer) == -1)
		ft_error("sem_post");
}

int	ft_error(char *str)
{
	printf("\x1b[31mError: %s!\n\x1b[0m", str);
	return (EXIT_FAILURE);
}
