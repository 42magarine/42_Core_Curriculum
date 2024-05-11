/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/11 18:36:48 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>	// memset
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <unistd.h>	// write, usleep
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread_create, pthread_detach, pthread_join,
						// pthread_mutex_init, pthread_mutex_destroy,
						// pthread_mutex_lock, pthread_mutex_unlock
# include <stdbool.h>

typedef struct s_data
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_eaten;
	long	start_time;
	bool	philo_died;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	t_data			*data;
}	t_philo;

typedef enum e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_status;

// main.c
int		main(int argc, char **argv);
int		print_status(t_philo *philo, t_status status);
// input.c
int		parse_input(t_data *data, char **argv);
// time.c
int		get_time(long *time);
void	ft_usleep(int msec);
// mutex.c
int		init_philo_mutex(t_data *data, t_philo **philo);
int		destroy_mutex(int num_philo, t_philo **philo);
// threads.c
int		pthread_create_join(int num_philo, t_philo **philo);
// philo.c
void	philo_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
bool	philo_die(t_philo *philo, int philo_action);

#endif
