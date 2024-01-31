/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:13:07 by mott              #+#    #+#             */
/*   Updated: 2024/01/31 15:27:35 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ps_lstsize(t_stack *stack)
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

t_stack	*ps_lstnew(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->num = num;
	new_node->movestotop = 0;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ps_lstlast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ps_lstadd_front(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

void	ps_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = ps_lstlast(*stack);
		last_node->next = new_node;
	}
}
