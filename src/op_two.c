/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:53:46 by mott              #+#    #+#             */
/*   Updated: 2024/02/09 19:18:54 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ps_rotate_a(t_stack **stack_a, bool print)
{
	t_stack	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	ps_stack_add_back(stack_a, temp);
	if (print == true)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ps_rotate_b(t_stack **stack_b, bool print)
{
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	ps_stack_add_back(stack_b, temp);
	if (print == true)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

// rotate_a and rotate_b at the same time.
void	ps_rotate_ab(t_stack **stack_a, t_stack **stack_b, bool print)
{
	ps_rotate_a(stack_a, false);
	ps_rotate_b(stack_b, false);
	if (print == true)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}
