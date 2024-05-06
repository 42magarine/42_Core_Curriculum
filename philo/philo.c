/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/06 19:05:32 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	g_mutex;
pthread_mutex_t	g_mutex2 = PTHREAD_MUTEX_INITIALIZER;

void	ft_usleep(void)
{
	int	usec;

	usec = 999999;
	usleep(usec);
}

void	ft_gettimeofday(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("tv_sec: %ld\n", tv.tv_sec);		// seconds since 01.01.1970 00:00:00
	printf("tv_usec: %d\n", tv.tv_usec);	// microseconds within the current second (1.000.000 usec = 1 sec)
}

void	*start_routine(void *id)
{
	pthread_t	tid;
	int			*i;

	tid = (pthread_t)id;
	printf("start pthread: %ld\n", tid->__sig);

	i = malloc(sizeof(int));
	*i = 0;
	while ((*i)++ < 1000000)
	{
		pthread_mutex_lock(&g_mutex);
		// n++;
		pthread_mutex_unlock(&g_mutex);
	}

	printf("end pthread: %ld\n", tid->__sig);
	return ((void *)i);
}

int	main(void)
{
	pthread_t	tid[8];
	int			*result[8];
	int			i;

	pthread_mutex_init(&g_mutex, NULL);

	i = 0;
	while (i++ < 8)
	{
		if (pthread_create(&tid[i], NULL, start_routine, &tid[i]) != 0)
			return (1);
	}

	pthread_mutex_destroy(&g_mutex);

	i = 0;
	while (i++ < 8)
	{
		if (pthread_join(tid[i], (void **)&result[i]) != 0)
			return (2);
	}

	i = 0;
	while (i++ < 8)
	{
		printf("i: %d result: %d\n", i, *result[i]);
		free(result[i]);
	}

	return (EXIT_SUCCESS);
}
