/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:14:49 by mott              #+#    #+#             */
/*   Updated: 2024/01/30 16:23:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**ps_parse_input(int argc, char **argv)
{
	char	**temp;
	int		i;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (temp == NULL)
			ps_error("malloc\n", NULL, NULL);
	}
	else
	{
		temp = malloc(argc * sizeof(char *));
		if (temp == NULL)
			ps_error("malloc\n", NULL, NULL);
		i = 0;
		while (i < argc - 1)
		{
			temp[i] = ft_strdup(argv[i + 1]);
			if (temp[i] == NULL)
				ps_error("malloc\n", temp, NULL);
			i++;
		}
		temp[argc - 1] = NULL;
	}
	return (temp);
}

int	ps_valid_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str++) == 1)
	{
		if (*str == '\0')
			return (0);
	}
	return (-1);
}

long	ps_atoi(char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
		num = num * 10 + *str++ - '0';
	num *= sign;
	return (num);
}

int	ps_minmaxint(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (-1);
	return (0);
}

int	ps_isdup(int num, t_stack *stack)
{
	while (stack != NULL)
	{
		if (num == stack->num)
		{
			return (-1);
		}
		stack = stack->next;
	}
	return (0);
}
