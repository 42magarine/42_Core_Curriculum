/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:18:23 by mott              #+#    #+#             */
/*   Updated: 2024/01/31 16:24:55 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	lst_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	ps_init_stack(argc, argv, &stack_a);
	if (ps_issorted(stack_a) == false)
	{
		lst_size = ps_lstsize(stack_a);
		if (lst_size == 2)
			ps_swap_a(&stack_a, true);
		else if (lst_size == 3)
			ps_sort_three(&stack_a);
		else
			ps_sort(&stack_a, &stack_b, lst_size);
		ps_print_stack(stack_a, stack_b);
	}
	ps_free_stack(stack_a);
	return (EXIT_SUCCESS);
}

bool	ps_issorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ps_print_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("stack a: ");
	while (stack_a != NULL)
	{
		ft_printf("%d ", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	ft_printf("stack b: ");
	while (stack_b != NULL)
	{
		ft_printf("%d ", stack_b->num);
		stack_b = stack_b->next;
	}
	ft_printf("\n");
}
