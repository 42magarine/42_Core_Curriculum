/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:52:46 by mott              #+#    #+#             */
/*   Updated: 2024/01/31 17:19:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sorts a stack of 3 elements in ascending order.
// 3 1 2 ->  ra	-> 1 2 3 -> OK
// 3 2 1 ->  ra -> 2 1 3 -> sa -> 1 2 3 -> OK
// 1 3 2 -> rra -> 2 1 3 -> sa -> 1 2 3 -> OK
// 2 3 1 -> rra -> 1 2 3 -> OK
// 2 1 3 ->  sa -> 1 2 3 -> OK
void	ps_sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = ps_find_biggest(*stack);

	if (biggest_node == *stack)
		ps_rotate_a(stack, true);
	else if (biggest_node == (*stack)->next)
		ps_reverse_rotate_a(stack, true);
	if ((*stack)->num > (*stack)->next->num)
		ps_swap_a(stack, true);
}

// sorts a stack of more than 3 elements in ascending order.
void	ps_sort(t_stack **stack_a, t_stack **stack_b, size_t lst_size)
{
	ps_push_b(stack_a, stack_b);
	while (--lst_size > 3 && ps_issorted(*stack_a) == false)
	{
		ps_push_b(stack_a, stack_b);
		// find cheapest number to push to b
		// push this number to b
		// stack b should be sorted in descending order
	}
	ps_sort_three(stack_a);
	lst_size = ps_lstsize(*stack_b);
	while (lst_size-- > 0)
		ps_push_a(stack_a, stack_b);
}

// find cheapest number to push to b:
// loop through a and find the right position in b
// calculate how much it costs to bring both nodes to the top
// cheapest = stack_a->movestotop + stack_b->movetotop

// push this number to b:
// movetotop > 0 means ra (stack size / 2)
// movetotop < 0 means rra (stack size / 2)
// if both > 0 then rr
// if both < 0 then rrr
// else ra and rrb
// else rra and rb

t_stack	*ps_find_smallest(t_stack *stack)
{
	int		smallest_num;
	t_stack	*smallest_node;

	smallest_num = stack->num;
	smallest_node = stack;
	while (stack != NULL)
	{
		if (stack->num < smallest_num)
		{
			smallest_num = stack->num;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*ps_find_biggest(t_stack *stack)
{
	int		biggest_num;
	t_stack	*biggest_node;

	biggest_num = stack->num;
	biggest_node = stack;
	while (stack != NULL)
	{
		if (stack->num > biggest_num)
		{
			biggest_num = stack->num;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
