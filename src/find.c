/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:35:19 by mott              #+#    #+#             */
/*   Updated: 2024/02/10 13:41:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// searches for the smallest number in the stack.
t_stack	*ps_find_smallest(t_stack *stack)
{
	int		smallest_num;
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
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

// searches for the biggest number in the stack.
t_stack	*ps_find_biggest(t_stack *stack)
{
	int		biggest_num;
	t_stack	*biggest_node;

	if (stack == NULL)
		return (NULL);
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

// searches for the next smaller number,
// if there is no smaller number, it searches for the biggest number.
t_stack	*ps_find_smaller(int num, t_stack *stack)
{
	t_stack	*smaller_node;
	t_stack	*stack_copy;
	long	smaller_num;

	stack_copy = stack;
	smaller_num = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->num < num && stack->num > smaller_num)
		{
			smaller_num = stack->num;
			smaller_node = stack;
		}
		stack = stack->next;
	}
	stack = stack_copy;
	if (smaller_num == LONG_MIN)
		smaller_node = ps_find_biggest(stack);
	return (smaller_node);
}

// searches for the next bigger number,
// if there is no bigger number, it searches for the smallest number.
t_stack	*ps_find_bigger(int num, t_stack *stack)
{
	t_stack	*bigger_node;
	t_stack	*stack_copy;
	long	bigger_num;

	stack_copy = stack;
	bigger_num = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->num > num && stack->num < bigger_num)
		{
			bigger_num = stack->num;
			bigger_node = stack;
		}
		stack = stack->next;
	}
	stack = stack_copy;
	if (bigger_num == LONG_MAX)
		bigger_node = ps_find_smallest(stack);
	return (bigger_node);
}

// for each number in stack a, find the correct position in stack b
// and calculate the number of moves needed to move a to b.
t_stack	*ps_find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cheapest_node;
	int		move_counter;
	int		temp;

	move_counter = INT_MAX;
	while (stack_a != NULL)
	{
		stack_a->matching_node = ps_find_smaller(stack_a->num, stack_b);
		temp = ps_calculate_moves(stack_a, stack_a->matching_node);
		if (temp < move_counter)
		{
			move_counter = temp;
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
}
