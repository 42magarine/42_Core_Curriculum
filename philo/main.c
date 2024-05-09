/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/09 19:28:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_mutex_t	g_mutex;
// pthread_mutex_t	g_mutex2 = PTHREAD_MUTEX_INITIALIZER;

// void	*start_routine(void *id)
// {
// 	pthread_t	tid;
// 	int			*i;

// 	tid = (pthread_t)id;
// 	printf("start pthread: %ld\n", tid->__sig);

// 	i = malloc(sizeof(int));
// 	*i = 0;
// 	while ((*i)++ < 1000000)
// 	{
// 		pthread_mutex_lock(&g_mutex);
// 		// n++;
// 		pthread_mutex_unlock(&g_mutex);
// 	}

// 	printf("end pthread: %ld\n", tid->__sig);
// 	return ((void *)i);
// }

// int	main(void)
// {
// 	pthread_t	tid[8];
// 	int			*result[8];
// 	int			i;

// 	pthread_mutex_init(&g_mutex, NULL);

// 	i = 0;
// 	while (i++ < 8)
// 	{
// 		if (pthread_create(&tid[i], NULL, start_routine, &tid[i]) != 0)
// 			return (1);
// 	}

// 	pthread_mutex_destroy(&g_mutex);

// 	i = 0;
// 	while (i++ < 8)
// 	{
// 		if (pthread_join(tid[i], (void **)&result[i]) != 0)
// 			return (2);
// 	}

// 	i = 0;
// 	while (i++ < 8)
// 	{
// 		printf("i: %d result: %d\n", i, *result[i]);
// 		free(result[i]);
// 	}

// 	return (EXIT_SUCCESS);
// }

static int	ft_error(const char *str)
{
	printf("Error: %s\n", str);
	return (EXIT_FAILURE);
}

static void print_status(void)
{
	printf("%d %d has taken a fork\n", 0, 0);
	printf("%d %d is eating\n", 0, 0);
	printf("%d %d is sleeping\n", 0, 0);
	printf("%d %d is thinking\n",0, 0);
	printf("%d %d died\n", 0, 0);
}

static void	print_input(t_input *input)
{
	printf("num_philo: %d\n", input->num_philo);
	printf("time_to_die: %d\n", input->time_to_die);
	printf("time_to_eat: %d\n", input->time_to_eat);
	printf("time_to_sleep: %d\n", input->time_to_sleep);
	printf("num_eaten: %d\n", input->num_eaten);
}

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
	printf("starttime: %ld\n", input.start_time);
	print_input(&input);
	print_status();
	return (EXIT_SUCCESS);
}
