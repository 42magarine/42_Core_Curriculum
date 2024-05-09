/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:45:21 by mott              #+#    #+#             */
/*   Updated: 2024/05/09 19:28:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

// void	ft_usleep(void)
// {
// 	int	usec;

// 	usec = 999999;
// 	usleep(usec);
// }


// tv.tv_sec	seconds since 01.01.1970 00:00:00
// tv.tv_usec	microseconds within the current second
//				1 sec = 1.000 millisec = 1.000.000 mircosec
long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	// printf("tv_sec: %ld\n", tv.tv_sec);
	// printf("tv_usec: %d\n", tv.tv_usec);
	// printf("Maximum value for long: %ld\n", LONG_MAX);
	// printf("Maximum value for long long: %lld\n", LLONG_MAX);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
