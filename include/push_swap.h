/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:15:05 by mott              #+#    #+#             */
/*   Updated: 2024/01/28 17:38:22 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	// int				index;
	struct s_stack	*next;
}	t_stack;

// push_swap.c
int		main(int argc, char **argv);
void	ps_init_stack(int argc, char **argv, t_stack **stack);
int		ps_issorted(t_stack *stack_a);
void	ps_print_stack(t_stack *stack_a, t_stack *stack_b);

// utils.c
void	ps_error(char *error, char **strs, t_stack *stack);
void	ps_free_strs(char **strs);
void	ps_free_stack(t_stack *stack);

// list.c
size_t	ps_lstsize(t_stack *stack);
t_stack	*ps_lstnew(int num);
t_stack	*ps_lstlast(t_stack *stack);
void	ps_lstadd_front(t_stack **stack, t_stack *new_node);
void	ps_lstadd_back(t_stack **stack, t_stack *new_node);

// init.c
char	**ps_parse_input(int argc, char **argv);
int		ps_valid_num(char *str);
long	ps_atoi(char *str);
int		ps_minmaxint(long num);
int		ps_isdup(int num, t_stack *stack);

// op_one.c
void	ps_swap_a(t_stack **stack_a, int print);
void	ps_swap_b(t_stack **stack_b, int print);
void	ps_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ps_push_a(t_stack **stack_a, t_stack **stack_b);
void	ps_push_b(t_stack **stack_a, t_stack **stack_b);

// op_two.c
void	ps_rotate_a(t_stack **stack_a, int print);
void	ps_rotate_b(t_stack **stack_b, int print);
void	ps_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// op_three.c
void	ps_reverse_rotate_a(t_stack **stack_a, int print);
void	ps_reverse_rotate_b(t_stack **stack_b, int print);
void	ps_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// sort.c
void	ps_sort_3(t_stack **stack_a);
void	ps_sort_5(t_stack **stack_a, t_stack **stack_b);

#endif

// ./push_swap 2 1 3 6 5 8 2147483647 -2147483648
// ARG="4 67 3 87 23"; ./push_swap $ARG
// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG

// -> ./push_swap <arguments, first argument should be at the top of the stack>
// -> check for duplicates, no int, bigger than int = "Error\n" (fd = stderr)
// -> no arguments = return
//
// -> sort in ascending order into stack a
//
//    -> sa (swap a) = swap the first 2 elements
//    -> sb (swap b) = swap the first 2 elements
//    -> ss = sa and sb
//
//    -> pa (push a) = take the first element of b and put it at the top of a
//    -> pb (push b) = take the first element of a and put it at the top of b
//
//    -> ra (rotate a) = shift up all elements by 1, first element becomes last
//    -> rb (rotate b) = shift up all elements by 1, first element becomes last
//    -> rr = ra and rb
//
//    -> rra (reverse rotate a) = shift down all elements by 1, last -> first
//    -> rrb (reverse rotate b) = shift down all elements by 1, last -> first
//    -> rrr = rra and rrb

/*
linear search
binary search
*/
