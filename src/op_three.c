/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:54:03 by mott              #+#    #+#             */
/*   Updated: 2024/01/28 14:52:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_reverse_rotate_a(t_stack **stack_a, int print)
{
	t_stack	*last;
	t_stack	*last_before;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	while (last->next != NULL)
	{
		last_before = last;
		last = last->next;
	}
	last_before->next = NULL;
	ps_lstadd_front(stack_a, last);
	if (print == 1)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	ps_reverse_rotate_b(t_stack **stack_b, int print)
{
	t_stack	*last;
	t_stack	*last_before;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	while (last->next != NULL)
	{
		last_before = last;
		last = last->next;
	}
	last_before->next = NULL;
	ps_lstadd_front(stack_b, last);
	if (print == 1)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	ps_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ps_reverse_rotate_a(stack_a, 0);
	ps_reverse_rotate_b(stack_b, 0);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
