/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/04/25 19:15:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(void)
{
	int	usec;
	int	i;

	usec = 999999;
	i = usleep(usec);
	printf("usleep: %i\n", i);
}

void	*ft_usleep2(void *arg)
{
	int	usec;
	int	i;

	usec = *(int *)arg;
	i = usleep(usec);
	printf("usleep2: %i\n", i);
	return (NULL);
}

void	ft_gettimeofday(void)
{
	struct timeval	tv;
	int				i;

	i = gettimeofday(&tv, NULL);
	printf("i: %d\n", i);
	printf("tv_sec: %ld\n", tv.tv_sec);		// seconds since 01.01.1970 00:00:00
	printf("tv_usec: %d\n", tv.tv_usec);	// microseconds within the current second (1.000.000 usec = 1 sec)
}

pthread_t	ft_pthread_create(void)
{
	pthread_t	tid;
	int			usec;

	usec = 999999;
	pthread_create(&tid, NULL, ft_usleep2, (void *)&usec);
	printf("pthread_create: %li\n", tid->__sig);
	return (tid);
}

void	ft_pthread_detach(pthread_t tid)
{
	int	i;

	i = pthread_detach(tid);
	printf("pthread_detach: %i\n", i);
}

void	ft_pthread_join(pthread_t tid)
{
	int	i;

	i = pthread_join(tid, NULL);
	printf("pthread_join: %i\n", i);
}

int	main(void)
{
	pthread_t	tid;

	// ft_usleep();
	// ft_gettimeofday();
	tid = ft_pthread_create();
	ft_pthread_detach(tid);
	// ft_pthread_join(tid);
	return (EXIT_SUCCESS);
}
