/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:54:42 by mott              #+#    #+#             */
/*   Updated: 2024/01/09 15:48:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j + 1 < size - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// bubble sort algorithm

// #include <stdio.h>

// int	main(void)
// {
// 	int	i = 0;
// 	int	size = 8;
// 	int	tab[8] = {42, 0, 8, -8, 42, 64, 1024, -512};

// 	while (i < size)
// 		printf(" %d", tab[i++]);
// 	printf("\n");
// 	sort_int_tab(tab, size);
// 	i = 0;
// 	while (i < size)
// 		printf(" %d", tab[i++]);
// 	printf("\n");
// 	return (0);
// }
