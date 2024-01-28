/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:35:19 by mott              #+#    #+#             */
/*   Updated: 2024/01/28 15:35:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
