/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:24 by mott              #+#    #+#             */
/*   Updated: 2024/05/16 18:34:05 by mott             ###   ########.fr       */
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
# include <stdbool.h>
# include <errno.h>

typedef struct s_data
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_eaten;
	long	start_time;
	bool	someone_died;
	sem_t	*forks;
	sem_t	*printer;
	sem_t	*dead;
}	t_data;

typedef struct s_philo
{
	int		philo_id;
	pid_t	philo_pid;
	long	last_meal;
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
void	print_status(t_data *data, t_status status, long time, int philo_id);
int		ft_error(char *str);
// init.c
int		init_data(t_data *data, char **argv);
int		init_philo(t_data *data, t_philo **philo);
// time.c
long	get_time(void);
void	ft_usleep(long milliseconds);
// child_process.c
int		create_child_process(t_data *data, t_philo **philo);
// philo.c
void	philo_eat(t_data *data, t_philo *philo);
void	philo_sleep(t_data *data, t_philo *philo);
void	philo_think(t_data *data, t_philo *philo);
void	philo_die(t_data *data, int philo_id);
// semaphore.c
int		open_semaphore(t_data *data);
int		unlink_semaphore(t_data *data);
void	philo_lock_fork(t_data *data, long time, int philo_id);
void	philo_unlock_fork(t_data *data);

#endif
