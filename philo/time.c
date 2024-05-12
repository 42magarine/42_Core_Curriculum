/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:45:21 by mott              #+#    #+#             */
/*   Updated: 2024/05/12 17:29:24 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// tv.tv_sec	seconds since 01.01.1970 00:00:00
// tv.tv_usec	microseconds within the current second
//				1 seconds = 1.000 milliseconds = 1.000.000 mircoseconds
int	get_time(long *milliseconds)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_error("gettimeofday"));
	*milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (EXIT_SUCCESS);
}

int	ft_usleep(long milliseconds)
{
	long	time;
	long	stop_time;

	if (get_time(&time) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	stop_time = time + milliseconds;
	if (milliseconds > 5)
		usleep((milliseconds - 5) * 1000);
	while (stop_time > time)
	{
		usleep(50);
		if (get_time(&time) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
