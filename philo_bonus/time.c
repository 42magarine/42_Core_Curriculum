/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:00:59 by mott              #+#    #+#             */
/*   Updated: 2024/05/14 15:22:16 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// long	tv.tv_sec	seconds since 01.01.1970 00:00:00
// int	tv.tv_usec	microseconds within the current second
//					1 seconds = 1.000 milliseconds = 1.000.000 mircoseconds
long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + (long)tv.tv_usec / 1000);
}

void	ft_usleep(long milliseconds)
{
	long	stop_time;

	stop_time = get_time() + milliseconds;
	if (milliseconds > 10)
		usleep((milliseconds - 10) * 1000);
	while (stop_time > get_time())
		usleep(100);
}
