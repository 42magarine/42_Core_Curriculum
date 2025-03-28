/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/24 17:08:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <unistd.h>	// usleep
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread_create, pthread_join,
						// pthread_mutex_init, pthread_mutex_destroy,
						// pthread_mutex_lock, pthread_mutex_unlock
# include <stdbool.h>

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				num_eaten;
	long			start_time;
	bool			is_finish;
	pthread_mutex_t	printer;
	pthread_mutex_t	finish;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	bool			philo_full;
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
long	print_status(t_philo *philo, t_status status);
int		ft_error(char *str);
// init.c
int		init_data(t_data *data, char **argv);
int		init_philo(t_data *data, t_philo **philo);
// mutex.c
int		init_mutex(t_data *data, t_philo **philo);
int		destroy_mutex(t_data *data, t_philo **philo);
void	philo_lock_forks(t_philo *philo);
void	philo_unlock_forks(t_philo *philo);
// threads.c
int		pthread_create_join(int num_philo, t_philo **philo);
// philo.c
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_die(t_philo *philo);
bool	philo_finish(t_philo *philo);
// time.c
long	get_time(void);
void	ft_usleep(long milliseconds);

#endif

// 2 200 300 200
// 2 1000 750 200 3
// 2 1000 200 750 3
// 5 400 200 200
// 5 400 300 100
// 5 400 100 300
// 200 200 100 <90
// 200 200 <90 100
