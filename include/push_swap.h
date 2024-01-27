/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:15:05 by mott              #+#    #+#             */
/*   Updated: 2024/01/26 16:26:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

#endif

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
