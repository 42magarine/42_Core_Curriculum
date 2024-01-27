/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:14:49 by mott              #+#    #+#             */
/*   Updated: 2024/01/27 21:06:55 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_init_stack(int argc, char **argv, t_stack **stack)
{
	char	**temp;
	size_t	i;
	long	num;
	t_stack	*new_node;

	temp = ps_parse_input(argc, argv);
	i = 0;
	while (temp[i] != NULL)
	{
		if (ps_valid_num(temp[i]) == -1)
			ps_error("Error\n", temp, *stack);
		num = ps_atoi(temp[i]);
		if (ps_minmaxint(num) == -1)
			ps_error("Error\n", temp, *stack);
		if (ps_isdup((int)num, *stack) == -1)
			ps_error("Error\n", temp, *stack);
		new_node = ps_lstnew((int)num);
		if (new_node == NULL)
			ps_error("malloc\n", temp, *stack);
		ps_lstadd_back(stack, new_node);
		i++;
	}
	ps_free_strs(temp);
}

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
	while (ft_isdigit(*str) == 1)
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
			return (-1);
		stack = stack->next;
	}
	return (0);
}
