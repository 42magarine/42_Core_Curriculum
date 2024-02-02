/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:52:46 by mott              #+#    #+#             */
/*   Updated: 2024/02/02 19:31:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sorts a stack of 3 elements in ascending order.
// 3 1 2 ->  ra	-> 1 2 3 -> OK
// 3 2 1 ->  ra -> 2 1 3 -> sa -> 1 2 3 -> OK
// 1 3 2 -> rra -> 2 1 3 -> sa -> 1 2 3 -> OK
// 2 3 1 -> rra -> 1 2 3 -> OK
// 2 1 3 ->  sa -> 1 2 3 -> OK
void	ps_sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = ps_find_biggest(*stack_a);
	if (biggest_node == *stack_a)
		ps_rotate_a(stack_a, true);
	else if (biggest_node == (*stack_a)->next)
		ps_reverse_rotate_a(stack_a, true);
	if ((*stack_a)->num > (*stack_a)->next->num)
		ps_swap_a(stack_a, true);
}

// sorts a stack of more than 3 elements in ascending order.
void	ps_sort_more(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	t_stack	*node_to_top;

	if (stack_size-- > 3 && ps_is_sorted(*stack_a) == false)
		ps_push_b(stack_a, stack_b);
	if (stack_size-- > 3 && ps_is_sorted(*stack_a) == false)
		ps_push_b(stack_a, stack_b);
	while (stack_size-- > 3 && ps_is_sorted(*stack_a) == false)
	{
		ps_set_moves_to_top(*stack_a);
		ps_set_moves_to_top(*stack_b);
		node_to_top = ps_find_cheapest(*stack_a, *stack_b);
		ps_ab_to_top(stack_a, stack_b, node_to_top);
		ps_push_b(stack_a, stack_b);
	}
	ps_sort_three(stack_a);
	while (*stack_b != NULL)
	{
		node_to_top = ps_find_bigger((*stack_b)->num, *stack_a);
		ps_a_to_top(stack_a, node_to_top);
		ps_push_a(stack_a, stack_b);
	}
	node_to_top = ps_find_smallest(*stack_a);
	ps_a_to_top(stack_a, node_to_top);
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
