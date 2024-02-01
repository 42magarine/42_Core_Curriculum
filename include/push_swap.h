/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:15:05 by mott              #+#    #+#             */
/*   Updated: 2024/02/01 20:29:13 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				movestotop;
	struct s_stack	*matching;
	struct s_stack	*next;
}	t_stack;

// push_swap.c
int		main(int argc, char **argv);
void	ps_error(char *error, char **strs, t_stack *stack);
void	ps_free_strs(char **strs);
void	ps_free_stack(t_stack *stack);
void	ps_print_stack(t_stack *stack_a, t_stack *stack_b);

// init.c
void	ps_init_stack(int argc, char **argv, t_stack **stack);
char	**ps_parse_input(int argc, char **argv);
bool	ps_valid_num(char *str);
long	ps_atol(char *str);
bool	ps_isduplicate(int num, t_stack *stack);

// list.c
size_t	ps_lstsize(t_stack *stack);
t_stack	*ps_lstnew(int num);
t_stack	*ps_lstlast(t_stack *stack);
void	ps_lstadd_front(t_stack **stack, t_stack *new_node);
void	ps_lstadd_back(t_stack **stack, t_stack *new_node);

// op_one.c
void	ps_swap_a(t_stack **stack_a, bool print);
void	ps_swap_b(t_stack **stack_b, bool print);
void	ps_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ps_push_a(t_stack **stack_a, t_stack **stack_b);
void	ps_push_b(t_stack **stack_a, t_stack **stack_b);

// op_two.c
void	ps_rotate_a(t_stack **stack_a, bool print);
void	ps_rotate_b(t_stack **stack_b, bool print);
void	ps_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// op_three.c
void	ps_reverse_rotate_a(t_stack **stack_a, bool print);
void	ps_reverse_rotate_b(t_stack **stack_b, bool print);
void	ps_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// sort.c
bool	ps_issorted(t_stack *stack);
void	ps_sort_three(t_stack **stack_a);
void	ps_sort_more(t_stack **stack_a, t_stack **stack_b, size_t lst_size);
void	ps_set_movestotop(t_stack **stack);
int		ps_calculate_moves(t_stack *stack_a, t_stack *matching_b);

// find.c
t_stack	*ps_find_smallest(t_stack *stack);
t_stack	*ps_find_biggest(t_stack *stack);
t_stack	*ps_find_smaller(int num, t_stack *stack);
t_stack	*ps_find_bigger(int num, t_stack *stack);
t_stack	*ps_find_cheapest(t_stack **stack_a, t_stack *stack_b);
t_stack	*ps_find_cheapest2(t_stack **stack_a, t_stack *stack_b);
void	ps_move_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *nodetomove);
void	ps_move_stacks2(t_stack **stack_a, t_stack **stack_b, t_stack *nodetomove);

#endif

// sort   3 <=    3
// sort   5 <=   12
// sort 100 <=  700
// sort 500 <= 5500
