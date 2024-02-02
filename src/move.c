/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:05:13 by mott              #+#    #+#             */
/*   Updated: 2024/02/02 19:33:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// the idea is to move all elements from the upper half with "ra"
// and all elements from the lower half with "rra".
// the number of moves using "ra" is shown as a positive number,
// the number of moves using "rra' is shown as a negative number.
void	ps_set_moves_to_top(t_stack *stack)
{
	int		stack_size;
	int		i;

	stack_size = ps_stack_size(stack);
	i = 0;
	while (i < stack_size)
	{
		if (i <= stack_size / 2)
			stack->moves_to_top = i;
		else
			stack->moves_to_top = i - stack_size;
		stack = stack->next;
		i++;
	}
}

int	ps_calculate_moves(t_stack *stack_a, t_stack *matching_b)
{
	int	move_counter;

	if (stack_a->moves_to_top >= 0 && matching_b->moves_to_top >= 0)
	{
		if (stack_a->moves_to_top > matching_b->moves_to_top)
			move_counter = stack_a->moves_to_top;
		else
			move_counter = matching_b->moves_to_top;
	}
	else if (stack_a->moves_to_top <= 0 && matching_b->moves_to_top <= 0)
	{
		if (-stack_a->moves_to_top > -matching_b->moves_to_top)
			move_counter = -stack_a->moves_to_top;
		else
			move_counter = -matching_b->moves_to_top;
	}
	else
	{
		if (stack_a->moves_to_top > 0)
			move_counter = stack_a->moves_to_top + -matching_b->moves_to_top;
		else
			move_counter = -stack_a->moves_to_top + matching_b->moves_to_top;
	}
	return (move_counter);
}

void	ps_ab_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *a_to_top)
{
	while (*stack_a != a_to_top || *stack_b != a_to_top->matching_node)
	{
		if (a_to_top->moves_to_top > 0
			&& a_to_top->matching_node->moves_to_top > 0)
			ps_rotate_ab(stack_a, stack_b);
		else if (a_to_top->moves_to_top > 0)
			ps_rotate_a(stack_a, true);
		else if (a_to_top->matching_node->moves_to_top > 0)
			ps_rotate_b(stack_b, true);
		if (a_to_top->moves_to_top < 0
			&& a_to_top->matching_node->moves_to_top < 0)
			ps_reverse_rotate_ab(stack_a, stack_b);
		else if (a_to_top->moves_to_top < 0)
			ps_reverse_rotate_a(stack_a, true);
		else if (a_to_top->matching_node->moves_to_top < 0)
			ps_reverse_rotate_b(stack_b, true);
		ps_set_moves_to_top(*stack_a);
		ps_set_moves_to_top(*stack_b);
	}
}

void	ps_a_to_top(t_stack **stack_a, t_stack *a_to_top)
{
	ps_set_moves_to_top(*stack_a);
	while (*stack_a != a_to_top)
	{
		if (a_to_top->moves_to_top > 0)
			ps_rotate_a(stack_a, true);
		else
			ps_reverse_rotate_a(stack_a, true);
	}
}
