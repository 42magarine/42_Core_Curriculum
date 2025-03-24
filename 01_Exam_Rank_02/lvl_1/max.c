/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:35:08 by mott              #+#    #+#             */
/*   Updated: 2024/01/07 19:26:41 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.

int	max(int *tab, unsigned int len)
{
	int	i;
	int	max;

	if (len == 0)
		return (0);
	i = 0;
	max = tab[i];
	while (++i < len)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return (max);
}
