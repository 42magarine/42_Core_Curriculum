/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:48:04 by mott              #+#    #+#             */
/*   Updated: 2024/05/09 20:42:43 by mott             ###   ########.fr       */
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

static void	*start_routine(void *arg)
{
	int	i;

	i = *(int *)arg;
	printf("Hello from thread: %d\n", i);
	free(arg);
	return (NULL);
}

int	pthread_create_join(t_input *input)
{
	pthread_t	*tid;
	int			i;
	int			*ptoi;

	tid = malloc(sizeof(pthread_t) * input->num_philo);
	if (tid == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < input->num_philo)
	{
		ptoi = malloc(sizeof(int));
		*ptoi = i;
		if (pthread_create(&tid[i], NULL, &start_routine, ptoi) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < input->num_philo)
	{
		if (pthread_join(tid[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(tid);
	return (EXIT_SUCCESS);
}
