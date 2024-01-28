/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:52:46 by mott              #+#    #+#             */
/*   Updated: 2024/01/28 17:30:14 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (first < second && first < third && second > third)
	{
		ps_swap_a(stack, 1);
		ps_rotate_a(stack, 1);
	}
	if (first > second && first < third && second < third)
		ps_swap_a(stack, 1);
	if (first < second && first > third && second > third)
		ps_reverse_rotate_a(stack, 1);
	if (first > second && first > third && second < third)
		ps_rotate_a(stack, 1);
	if (first > second && first > third && second > third)
	{
		ps_swap_a(stack, 1);
		ps_reverse_rotate_a(stack, 1);
	}
}

void	ps_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}
