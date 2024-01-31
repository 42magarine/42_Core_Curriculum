/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:12:42 by mott              #+#    #+#             */
/*   Updated: 2024/01/31 16:14:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	ps_swap_a(t_stack **stack_a, bool print)
{
	t_stack	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (print == true)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	ps_swap_b(t_stack **stack_b, bool print)
{
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print == true)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

// swap_a and swap_b at the same time.
void	ps_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ps_swap_a(stack_a, false);
	ps_swap_b(stack_b, false);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	ps_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	ps_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
