/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/13 17:58:23 by mott             ###   ########.fr       */
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
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eaten;
	long			start_time;
	bool			philo_died;
	pthread_mutex_t	printer;
	pthread_mutex_t	dead;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
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
int		ft_error(char *str);
// input.c
int		init_data(t_data *data, char **argv);
// time.c
int		get_time(long *time);
int		ft_usleep(long milliseconds);
// mutex.c
int		init_philo_mutex(t_data *data, t_philo **philo);
int		destroy_mutex(t_data *data, t_philo **philo);
// threads.c
void	philo_die(t_philo *philo, int time);
bool	someone_died(t_philo *philo);
int		pthread_create_join(int num_philo, t_philo **philo);
// philo.c
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

#endif

// who dies first?
// 5 400 200 200
// 5 400 300 100
// 5 400 100 300

// is someone dying?
// 200 200 100 <90
// 200 200 <90 100

// only print one dying message?
