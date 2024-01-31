/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:52:46 by mott              #+#    #+#             */
/*   Updated: 2024/01/30 17:24:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sorts the following cases:
// 1 2 3 -> OK
// 1 3 2 ->  sa -> 3 1 2 ->  ra -> 1 2 3 -> OK
// 2 1 3 ->  sa -> 1 2 3 ->  OK
// 2 3 1 -> rra -> 1 2 3 ->  OK
// 3 1 2 ->  ra	-> 1 2 3 ->  OK
// 3 2 1 ->  sa -> 2 3 1 -> rra -> 1 2 3 -> OK
void	ps_sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (first < second && first < third && second > third)
	{
		ps_swap_a(stack, 1);
		ps_rotate_a(stack, 1);
	}
	if (first > second && first < third && second < third)
		ps_swap_a(stack, 1);
	if (first < second && first > third && second > third)
		ps_reverse_rotate_a(stack, 1);
	if (first > second && first > third && second < third)
		ps_rotate_a(stack, 1);
	if (first > second && first > third && second > third)
	{
		ps_swap_a(stack, 1);
		ps_reverse_rotate_a(stack, 1);
	}
}

void	ps_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	size_t	lst_size;
	size_t	i;
	// int		smallest;
	size_t	position;

	lst_size = ps_lstsize(*stack_a);
	i = 3;
	while (lst_size-- > i)
	{
		// smallest = ps_find_smallest(*stack_a);
		position = ps_find_smallest(*stack_a);
		if ((lst_size / 2) >= position)
		{
			while (position-- > 0)
				ps_rotate_a(stack_a, 1);
		}
		else
		{
			while (position++ <= lst_size)
				ps_reverse_rotate_a(stack_a, 1);
		}
		// while ((*stack_a)->num != smallest)
		// 	ps_rotate_a(stack_a, 1);
		ps_push_b(stack_a, stack_b);
	}
	ps_sort_3(stack_a);
	lst_size = ps_lstsize(*stack_b);
	while (lst_size-- > 0)
		ps_push_a(stack_a, stack_b);
}

// t_stack	*ps_find_smallest(t_stack *stack)
size_t	ps_find_smallest(t_stack *stack)
{
	int		smallest;
	// t_stack	*smallest;
	size_t	i;
	size_t	position;

	smallest = stack->num;
	position = 0;
	// smallest = stack;
	i = 0;
	while (stack != NULL)
	{
		if (stack->num < smallest)
		{
			smallest = stack->num;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	// return (smallest);
	return (position);
}

// void	ps_set_index(t_stack stack)
// {

// }
