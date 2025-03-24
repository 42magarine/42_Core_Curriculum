/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:33:49 by mott              #+#    #+#             */
/*   Updated: 2024/01/07 12:48:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_swap
// Expected files   : ft_swap.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that swaps the contents of two integers the adresses of which
// are passed as parameters.

// Your function must be declared as follows:

// void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	// *a = 3
	// *b = 5
	// *a = 3 ⊕ 5 (XOR)
	// Binäre Darstellung: 0011 ⊕ 0101 = 0110
	// *a = 6
	// *b = 5
	*b = *b ^ *a;
	// *a = 6
	// *b = 5
	// *b = 5 ⊕ 6 (XOR)
	// Binäre Darstellung: 0101 ⊕ 0110 = 0011
	// *a = 6
	// *b = 3
	*a = *a ^ *b;
	// *a = 6
	// *b = 3
	// *a = 6 ⊕ 3 (XOR)
	// Binäre Darstellung: 0110 ⊕ 0011 = 0101
	// *a = 5
	// *b = 3
}

void	ft_swap(int *a, int *b)
{
	(*a ^= *b), (*b ^= *a), (*a ^= *b);
}
