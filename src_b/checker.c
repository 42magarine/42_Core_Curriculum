/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:10:28 by mott              #+#    #+#             */
/*   Updated: 2024/02/10 12:47:19 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*next_op;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	ps_init_stack(argc, argv, &stack_a);
	next_op = get_next_line(STDIN_FILENO);
	while (next_op != NULL)
	{
		ps_execute_op(&stack_a, &stack_b, next_op);
		free(next_op);
		next_op = get_next_line(STDIN_FILENO);
	}
	if (ps_is_sorted(stack_a) == true && stack_b == NULL)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ps_free_stack(stack_a);
	return (EXIT_SUCCESS);
}

void	ps_execute_op(t_stack **stack_a, t_stack **stack_b, char *next_op)
{
	if (ft_strncmp(next_op, "sa\n", 3) == 0)
		ps_swap_a(stack_a, false);
	else if (ft_strncmp(next_op, "sb\n", 3) == 0)
		ps_swap_b(stack_b, false);
	else if (ft_strncmp(next_op, "ss\n", 3) == 0)
		ps_swap_ab(stack_a, stack_b, false);
	else if (ft_strncmp(next_op, "pa\n", 3) == 0)
		ps_push_a(stack_a, stack_b, false);
	else if (ft_strncmp(next_op, "pb\n", 3) == 0)
		ps_push_b(stack_a, stack_b, false);
	else if (ft_strncmp(next_op, "ra\n", 3) == 0)
		ps_rotate_a(stack_a, false);
	else if (ft_strncmp(next_op, "rb\n", 3) == 0)
		ps_rotate_b(stack_b, false);
	else if (ft_strncmp(next_op, "rr\n", 3) == 0)
		ps_rotate_ab(stack_a, stack_b, false);
	else if (ft_strncmp(next_op, "rra\n", 4) == 0)
		ps_reverse_rotate_a(stack_a, false);
	else if (ft_strncmp(next_op, "rrb\n", 4) == 0)
		ps_reverse_rotate_b(stack_b, false);
	else if (ft_strncmp(next_op, "rrr\n", 4) == 0)
		ps_reverse_rotate_ab(stack_a, stack_b, false);
	else
		ps_error_checker(next_op, *stack_a, *stack_b);
}

bool	ps_is_sorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ps_error_checker(char *next_op, t_stack *stack_a, t_stack *stack_b)
{
	get_next_line(-1);
	free(next_op);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
