/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/14 15:47:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// #define	SEMAPHORE_NAME "/semaphore_name"

// sem_t	*semaphore;

// void	*start_routine(void *id)
// {
// 	pthread_t	tid;

// 	tid = (pthread_t)id;
// 	sem_wait(semaphore);
// 	printf("start pthread: %ld\n", tid->__sig);
// 	sleep(1);
// 	printf("end pthread: %ld\n", tid->__sig);
// 	sem_post(semaphore);
// 	return (NULL);
// }

// int	main(void)
// {
// 	pthread_t	tid[8];
// 	int			i;

// 	semaphore = sem_open(SEMAPHORE_NAME, O_CREAT, 0644, 4);

// 	i = 0;
// 	while (i++ < 8)
// 	{
// 		if (pthread_create(&tid[i], NULL, start_routine, &tid[i]) != 0)
// 			return (1);
// 	}

// 	i = 0;
// 	while (i++ < 8)
// 	{
// 		if (pthread_join(tid[i], NULL) != 0)
// 			return (2);
// 	}

// 	sem_close(semaphore);
// 	sem_unlink(SEMAPHORE_NAME);

// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (ft_error("Invalid number of arguments"));
	if (init_data(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (init_philo_mutex(&data, &philo) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	if (create_child_process(data.num_philo, &philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (destroy_mutex(&data, &philo) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// system("leaks philo");
	return (EXIT_SUCCESS);
}

void	print_status(t_philo *philo, t_status status)
{
	long	time;

	time = get_time() - philo->data->start_time;
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
}

int	ft_error(char *str)
{
	printf("\x1b[31mError: %s!\n\x1b[0m", str);
	return (EXIT_FAILURE);
}
