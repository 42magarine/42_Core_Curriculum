/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:36:03 by mott              #+#    #+#             */
/*   Updated: 2023/12/13 12:36:04 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it, followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>

#include <unistd.h>

void	ft_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	ft_putchar('\n');
	return (0);
}
