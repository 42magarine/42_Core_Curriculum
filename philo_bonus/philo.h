/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:24 by mott              #+#    #+#             */
/*   Updated: 2024/04/23 17:56:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>	// memset
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free, exit
# include <unistd.h>	// write, usleep, fork
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread_create, pthread_detach, pthread_join,
# include <signal.h>	// kill
# include <sys/wait.h>	// waitpid
# include <semaphore.h>	// sem_open, sem_close, sem_post, sem_wait, sem_unlink

#endif
