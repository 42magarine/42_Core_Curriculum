/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:13:07 by mott              #+#    #+#             */
/*   Updated: 2024/02/02 12:33:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ps_stack_new(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ps_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

size_t	ps_stack_size(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ps_stack_add_front(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

void	ps_stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = ps_stack_last(*stack);
		last_node->next = new_node;
	}
}
