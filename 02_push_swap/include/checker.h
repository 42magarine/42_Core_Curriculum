/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:09:54 by mott              #+#    #+#             */
/*   Updated: 2024/02/09 20:18:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "../Libft/libft.h"

// checker.c
int		main(int argc, char **argv);
void	ps_execute_op(t_stack **stack_a, t_stack **stack_b, char *next_op);
bool	ps_is_sorted(t_stack *stack);
void	ps_error_checker(char *next_op, t_stack *stack_a, t_stack *stack_b);

#endif
