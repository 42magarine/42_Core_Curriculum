/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:18:23 by mott              #+#    #+#             */
/*   Updated: 2024/01/27 20:59:15 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (argc > 1)
	{
		ps_init_stack(argc, argv, &stack_a);
		ps_print_stack(stack_a);
		ps_free_stack(stack_a);
	}
	return (0);
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
	int	i;

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

void	ps_print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->num);
		stack = stack->next;
	}
	ft_printf("\n");
}
