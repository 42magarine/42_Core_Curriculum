/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:36:46 by mott              #+#    #+#             */
/*   Updated: 2023/12/13 20:10:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the
// begin/end of the string.

// If the number of parameters is different from 1, the program will display
// '\n'.

// In the parameters that are going to be tested, there won't be any "additional"
// spaces (meaning that there won't be additionnal spaces at the beginning or at
// the end of the string, and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

#include <unistd.h>

void	ft_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_rev_wstr(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ' ')
		{
			j = i + 1;
			while (str[j] != ' ' && str[j] != '\0')
				ft_putchar(str[j++]);
			ft_putchar(' ');
		}
		else if (i == 0)
		{
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
				ft_putchar(str[j++]);
			return ;
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rev_wstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
