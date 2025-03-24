/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:14:49 by mott              #+#    #+#             */
/*   Updated: 2024/02/02 13:20:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_init_stack(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*new_node;
	char	**temp;
	long	num;
	size_t	i;

	if (argv[1][0] == '\0')
		ps_error("Error\n", NULL, NULL);
	temp = ps_parse_input(argc, argv);
	i = 0;
	while (temp[i] != NULL)
	{
		if (ps_valid_num(temp[i]) == false)
			ps_error("Error\n", temp, *stack_a);
		num = ps_atol(temp[i]);
		if (num > INT_MAX || num < INT_MIN)
			ps_error("Error\n", temp, *stack_a);
		if (ps_is_duplicate((int)num, *stack_a) == true)
			ps_error("Error\n", temp, *stack_a);
		new_node = ps_stack_new((int)num);
		if (new_node == NULL)
			ps_error("malloc\n", temp, *stack_a);
		ps_stack_add_back(stack_a, new_node);
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

bool	ps_valid_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str++) == 1)
	{
		if (*str == '\0')
			return (true);
	}
	return (false);
}

long	ps_atol(char *str)
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
	return (sign * num);
}

bool	ps_is_duplicate(int num, t_stack *stack)
{
	while (stack != NULL)
	{
		if (num == stack->num)
			return (true);
		stack = stack->next;
	}
	return (false);
}
