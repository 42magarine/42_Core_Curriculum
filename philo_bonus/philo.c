/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/08 17:05:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define	SEMAPHORE_NAME "/semaphore_name"

sem_t	*semaphore;

void	*start_routine(void *id)
{
	pthread_t	tid;

	tid = (pthread_t)id;
	sem_wait(semaphore);
	printf("start pthread: %ld\n", tid->__sig);
	sleep(1);
	printf("end pthread: %ld\n", tid->__sig);
	sem_post(semaphore);
	return (NULL);
}

int	main(void)
{
	pthread_t	tid[8];
	int			i;

	semaphore = sem_open(SEMAPHORE_NAME, O_CREAT, 0644, 4);

	i = 0;
	while (i++ < 8)
	{
		if (pthread_create(&tid[i], NULL, start_routine, &tid[i]) != 0)
			return (1);
	}

	i = 0;
	while (i++ < 8)
	{
		if (pthread_join(tid[i], NULL) != 0)
			return (2);
	}

	sem_close(semaphore);
	sem_unlink(SEMAPHORE_NAME);

	return (EXIT_SUCCESS);
}
