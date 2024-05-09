/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:46:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/09 18:21:56 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	n;

	n = 0;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		if (n < 0)
			return (-1);
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (n);
}

int	parse_input(t_philo *philo, char **argv)
{
	philo->num_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (philo->num_philo < 1 || philo->time_to_die < 1
		|| philo->time_to_eat < 1 || philo->time_to_sleep < 1)
		return (EXIT_FAILURE);
	if (argv[5] != NULL)
	{
		philo->num_eaten = ft_atoi(argv[5]);
		if (philo->num_eaten < 1)
			return (EXIT_FAILURE);
	}
	else
		philo->num_eaten = -1;
	return (EXIT_SUCCESS);
}
