/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:52:46 by mott              #+#    #+#             */
/*   Updated: 2024/02/01 20:31:04 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ps_issorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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
void	ps_sort_more(t_stack **stack_a, t_stack **stack_b, size_t lst_size)
{
	t_stack	*nodetomove;

	if (lst_size-- > 3 && ps_issorted(*stack_a) == false)
		ps_push_b(stack_a, stack_b);
	if (lst_size-- > 3 && ps_issorted(*stack_a) == false)
		ps_push_b(stack_a, stack_b);
	while (lst_size-- > 3 && ps_issorted(*stack_a) == false)
	{
		ps_set_movestotop(stack_a);
		ps_set_movestotop(stack_b);
		nodetomove = ps_find_cheapest(stack_a, *stack_b);
		ps_move_stacks(stack_a, stack_b, nodetomove);
		ps_push_b(stack_a, stack_b);
	}
	ps_sort_three(stack_a);
	lst_size = ps_lstsize(*stack_b);
	while (lst_size-- > 0)
	{
		ps_set_movestotop(stack_a);
		ps_set_movestotop(stack_b);
		nodetomove = ps_find_cheapest2(stack_b, *stack_a);
		ps_move_stacks2(stack_b, stack_a, nodetomove);
		ps_push_a(stack_a, stack_b);
	}
	ps_set_movestotop(stack_a);
	nodetomove = ps_find_smallest(*stack_a);
	while (*stack_a != nodetomove)
	{
		if (nodetomove->movestotop > 0)
		{
			ps_rotate_a(stack_a, true);
			nodetomove->movestotop--;
		}
		else if (nodetomove->movestotop < 0)
		{
			ps_reverse_rotate_a(stack_a, true);
			nodetomove->movestotop++;
		}
	}
}

// the idea is to move all elements from the upper half with "ra"
// and all elements from the lower half with "rra".
// the number of moves using "ra" is shown as a positive number,
// the number of moves using "rra' is shown as a negative number.
void	ps_set_movestotop(t_stack **stack)
{
	t_stack	*temp;
	int		lst_size;
	int		i;

	temp = *stack;
	lst_size = ps_lstsize(*stack);
	i = 0;
	// while (temp != NULL)
	while (i < lst_size)
	{
		if (i <= lst_size / 2)
			temp->movestotop = i;
		else
			temp->movestotop = i - lst_size;
		temp = temp->next;
		i++;
	}
}

int	ps_calculate_moves(t_stack *stack_a, t_stack *matching_b)
{
	int	move_counter;

	if (stack_a->movestotop > 0 && matching_b->movestotop > 0)
	{
		if (stack_a->movestotop > matching_b->movestotop)
			move_counter = stack_a->movestotop;
		else
			move_counter = matching_b->movestotop;
	}
	else if (stack_a->movestotop < 0 && matching_b->movestotop < 0)
	{
		if (-stack_a->movestotop > -matching_b->movestotop)
			move_counter = -stack_a->movestotop;
		else
			move_counter = -matching_b->movestotop;
	}
	else
	{
		if (stack_a->movestotop > 0)
			move_counter = stack_a->movestotop - -matching_b->movestotop;
		else
			move_counter = -stack_a->movestotop + matching_b->movestotop;
	}
	return (move_counter);
}
