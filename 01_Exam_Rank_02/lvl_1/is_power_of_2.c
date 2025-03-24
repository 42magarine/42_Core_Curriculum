/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:34:56 by mott              #+#    #+#             */
/*   Updated: 2024/01/07 18:04:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : is_power_of_2
// Expected files   : is_power_of_2.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that determines if a given number is a power of 2.

// This function returns 1 if the given number is a power of 2, otherwise it returns 0.

// Your function must be declared as follows:

// int	    is_power_of_2(unsigned int n);

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	if (n == 1)
		return (1);
	else
		return (0);
}

int	is_power_of_2(unsigned int n)
{
	return ((n != 0) && ((n & -n) == n));
	// +n = +8 -> 0 1000
	// -n = -8 -> 1 1000
	// +n & -n -> 0 1000
}

int	is_power_of_2(unsigned int n)
{
	return ((n != 0) && ((n & n - 1) == 0));
	// n = 8 -> 1000
	// n = 7 -> 0111
	// n & n - 1 -> 0000
}
