/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/15 17:39:47 by mott             ###   ########.fr       */
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
	if (init_philo(&data, &philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (open_semaphore(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_child_process(&data, &philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (unlink_semaphore(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(philo);
	// system("leaks philo");
	return (EXIT_SUCCESS);
}

void	print_status(t_data *data, t_status status, long time, int philo_id)
{
	if (sem_wait(data->printer) == -1)
		ft_error("sem_wait");
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
