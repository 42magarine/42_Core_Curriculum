/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:35:19 by mott              #+#    #+#             */
/*   Updated: 2024/02/01 20:32:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	// ft_printf("smallest_node: %d\n", smallest_node->num);
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
	// ft_printf("biggest_node: %d\n", biggest_node->num);
	return (biggest_node);
}

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
	// ft_printf("num: %d smaller_node: %d\n", num, smaller_node->num);
	return (smaller_node);
}

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
	// ft_printf("num: %d bigger_node: %d\n", num, bigger_node->num);
	return (bigger_node);
}

t_stack	*ps_find_cheapest(t_stack **stack_a, t_stack *stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*stack_copy;
	int		move_counter;
	int		temp;

	stack_copy = *stack_a;
	move_counter = INT_MAX;
	while (stack_copy != NULL)
	{
		stack_copy->matching = ps_find_smaller(stack_copy->num, stack_b);
		temp = ps_calculate_moves(stack_copy, stack_copy->matching);
		if (temp < move_counter)
		{
			move_counter = temp;
			cheapest_node = stack_copy;
		}
		stack_copy = stack_copy->next;
	}
	return (cheapest_node);
}

t_stack	*ps_find_cheapest2(t_stack **stack_a, t_stack *stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*stack_copy;
	int		move_counter;
	int		temp;

	stack_copy = *stack_a;
	move_counter = INT_MAX;
	while (stack_copy != NULL)
	{
		stack_copy->matching = ps_find_bigger(stack_copy->num, stack_b);
		temp = ps_calculate_moves(stack_copy, stack_copy->matching);
		if (temp < move_counter)
		{
			move_counter = temp;
			cheapest_node = stack_copy;
		}
		stack_copy = stack_copy->next;
	}
	return (cheapest_node);
}

void	ps_move_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *nodetomove)
{
	while (*stack_a != nodetomove || *stack_b != nodetomove->matching)
	{
		if (nodetomove->movestotop > 0 && nodetomove->matching->movestotop > 0)
		{
			ps_rotate_ab(stack_a, stack_b);
			nodetomove->movestotop--;
			nodetomove->matching->movestotop--;
		}
		else if (nodetomove->movestotop > 0)
		{
			ps_rotate_a(stack_a, true);
			nodetomove->movestotop--;
		}
		else if (nodetomove->matching->movestotop > 0)
		{
			ps_rotate_b(stack_b, true);
			nodetomove->matching->movestotop--;
		}
		if (nodetomove->movestotop < 0 && nodetomove->matching->movestotop < 0)
		{
			ps_reverse_rotate_ab(stack_a, stack_b);
			nodetomove->movestotop++;
			nodetomove->matching->movestotop++;
		}
		else if (nodetomove->movestotop < 0)
		{
			ps_reverse_rotate_a(stack_a, true);
			nodetomove->movestotop++;
		}
		else if (nodetomove->matching->movestotop < 0)
		{
			ps_reverse_rotate_b(stack_b, true);
			nodetomove->matching->movestotop++;
		}
	}
}

void	ps_move_stacks2(t_stack **stack_b, t_stack **stack_a, t_stack *nodetomove)
{
	while (*stack_b != nodetomove || *stack_a != nodetomove->matching)
	{
		if (nodetomove->movestotop > 0 && nodetomove->matching->movestotop > 0)
		{
			ps_rotate_ab(stack_b, stack_a);
			nodetomove->movestotop--;
			nodetomove->matching->movestotop--;
		}
		else if (nodetomove->movestotop > 0)
		{
			ps_rotate_b(stack_b, true);
			nodetomove->movestotop--;
		}
		else if (nodetomove->matching->movestotop > 0)
		{
			ps_rotate_a(stack_a, true);
			nodetomove->matching->movestotop--;
		}
		if (nodetomove->movestotop < 0 && nodetomove->matching->movestotop < 0)
		{
			ps_reverse_rotate_ab(stack_b, stack_a);
			nodetomove->movestotop++;
			nodetomove->matching->movestotop++;
		}
		else if (nodetomove->movestotop < 0)
		{
			ps_reverse_rotate_b(stack_b, true);
			nodetomove->movestotop++;
		}
		else if (nodetomove->matching->movestotop < 0)
		{
			ps_reverse_rotate_a(stack_a, true);
			nodetomove->matching->movestotop++;
		}
	}
}
