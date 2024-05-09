/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:46:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/09 17:30:09 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(int *n, const char *str)
{
	*n = 0;
	if (*str == '\0')
		return (EXIT_FAILURE);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		*n = *n * 10 + *str - '0';
		if (*n < 0)
			return (EXIT_FAILURE);
		str++;
	}
	if (*str != '\0' || *n == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_input(t_philo *philo, char **argv)
{
	if (ft_atoi(&philo->num_philo, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_atoi(&philo->time_to_die, argv[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_atoi(&philo->time_to_eat, argv[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_atoi(&philo->time_to_sleep, argv[4]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (argv[5] != NULL)
	{
		if (ft_atoi(&philo->num_eaten, argv[5]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		philo->num_eaten = -1;
	return (EXIT_SUCCESS);
}
