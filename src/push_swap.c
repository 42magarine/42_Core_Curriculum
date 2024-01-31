/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:18:23 by mott              #+#    #+#             */
/*   Updated: 2024/01/30 17:36:16 by mott             ###   ########.fr       */
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
	if (ps_issorted(stack_a) == 1)
	{
		ps_free_stack(stack_a);
		return (EXIT_SUCCESS);
	}
	lst_size = ps_lstsize(stack_a);
	if (lst_size == 2)
		ps_swap_a(&stack_a, 1);
	else if (lst_size == 3)
		ps_sort_3(&stack_a);
	else
		ps_sort_5(&stack_a, &stack_b);
	ps_print_stack(stack_a, stack_b);
	ps_free_stack(stack_a);
	return (EXIT_SUCCESS);
}

void	ps_init_stack(int argc, char **argv, t_stack **stack)
{
	char	**temp;
	size_t	i;
	long	num;
	t_stack	*new_node;

	if (argv[1][0] == '\0')
		ps_error("Error\n", NULL, NULL);
	temp = ps_parse_input(argc, argv);
	i = 0;
	while (temp[i] != NULL)
	{
		if (ps_valid_num(temp[i]) == -1)
			ps_error("Error\n", temp, *stack);
		num = ps_atoi(temp[i]);
		if (ps_minmaxint(num) == -1)
			ps_error("Error\n", temp, *stack);
		if (ps_isdup((int)num, *stack) == -1)
			ps_error("Error\n", temp, *stack);
		new_node = ps_lstnew((int)num);
		if (new_node == NULL)
			ps_error("malloc\n", temp, *stack);
		ps_lstadd_back(stack, new_node);
		i++;
	}
	ps_free_strs(temp);
}

int	ps_issorted(t_stack *stack_a)
{
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if (stack_a->num >= stack_a->next->num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
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
