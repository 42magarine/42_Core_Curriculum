/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:12:42 by mott              #+#    #+#             */
/*   Updated: 2024/01/28 12:51:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_swap_a(t_stack **stack_a, int print)
{
	t_stack	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (print == 1)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	ps_swap_b(t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print == 1)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ps_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ps_swap_a(stack_a, 0);
	ps_swap_b(stack_b, 0);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

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
