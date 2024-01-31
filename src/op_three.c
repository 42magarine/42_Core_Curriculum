/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:54:03 by mott              #+#    #+#             */
/*   Updated: 2024/01/31 16:17:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	ps_reverse_rotate_a(t_stack **stack_a, bool print)
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
	if (print == true)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ps_reverse_rotate_b(t_stack **stack_b, bool print)
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
	if (print == true)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

// reverse_rotate_a and reverse_rotate_b at the same time.
void	ps_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ps_reverse_rotate_a(stack_a, false);
	ps_reverse_rotate_b(stack_b, false);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
