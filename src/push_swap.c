/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:18:23 by mott              #+#    #+#             */
/*   Updated: 2024/02/02 18:28:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	stack_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	ps_init_stack(argc, argv, &stack_a);
	if (ps_is_sorted(stack_a) == false)
	{
		stack_size = ps_stack_size(stack_a);
		if (stack_size == 2)
			ps_swap_a(&stack_a, true);
		else if (stack_size == 3)
			ps_sort_three(&stack_a);
		else
			ps_sort_more(&stack_a, &stack_b, stack_size);
	}
	ps_free_stack(stack_a);
	return (EXIT_SUCCESS);
}

void	ps_error(char *error, char **strs, t_stack *stack)
{
	ps_free_strs(strs);
	ps_free_stack(stack);
	ft_putstr_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ps_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

// void	ps_free_strs(char **strs)
// {
// 	if (strs == NULL)
// 		return ;
// 	while (*strs != NULL)
// 		free((*strs)++);
// 	free(strs);
// }

void	ps_free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

// void	ps_print_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	ft_printf("stack a: ");
// 	while (stack_a != NULL)
// 	{
// 		ft_printf("%d ", stack_a->num);
// 		stack_a = stack_a->next;
// 	}
// 	ft_printf("\n");
// 	ft_printf("stack b: ");
// 	while (stack_b != NULL)
// 	{
// 		ft_printf("%d ", stack_b->num);
// 		stack_b = stack_b->next;
// 	}
// 	ft_printf("\n");
// }
