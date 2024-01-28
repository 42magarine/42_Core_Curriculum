/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:53:46 by mott              #+#    #+#             */
/*   Updated: 2024/01/28 14:57:14 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_rotate_a(t_stack **stack_a, int print)
{
	t_stack	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	ps_lstadd_back(stack_a, temp);
	if (print == 1)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	ps_rotate_b(t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	ps_lstadd_back(stack_b, temp);
	if (print == 1)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	ps_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ps_rotate_a(stack_a, 0);
	ps_rotate_b(stack_b, 0);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
