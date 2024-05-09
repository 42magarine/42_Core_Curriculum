/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:46:10 by mott              #+#    #+#             */
/*   Updated: 2024/05/09 18:46:50 by mott             ###   ########.fr       */
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

int	parse_input(t_input *input, char **argv)
{
	input->num_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (input->num_philo < 1 || input->time_to_die < 1
		|| input->time_to_eat < 1 || input->time_to_sleep < 1)
		return (EXIT_FAILURE);
	if (argv[5] != NULL)
	{
		input->num_eaten = ft_atoi(argv[5]);
		if (input->num_eaten < 1)
			return (EXIT_FAILURE);
	}
	else
		input->num_eaten = -1;
	return (EXIT_SUCCESS);
}
