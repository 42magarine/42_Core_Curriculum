/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:36:12 by mott              #+#    #+#             */
/*   Updated: 2023/12/13 20:48:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rstr_capitalizer
// Expected files   : rstr_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or more strings and, for each argument, puts
// the last character that is a letter of each word in uppercase and the rest
// in lowercase, then displays the result followed by a \n.

// A word is a section of string delimited by spaces/tabs or the start/end of the
// string. If a word has a single letter, it must be capitalized.

// A letter is a character in the set [a-zA-Z]

// If there are no parameters, display \n.

// Examples:

// $> ./rstr_capitalizer | cat -e
// $
// $> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
// A firsT littlE tesT$
// $> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
// seconD tesT A littlE biT   moaR compleX$
//    but... thiS iS noT thaT compleX$
//      okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
// $>

#include <unistd.h>

void	ft_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_str_capitalizer(char *str)
{
	int	i;
	int	last_letter;

	i = 0;
	last_letter = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
			last_letter = 1;
		if (str[i] >= 'a' && str[i] <= 'z' && last_letter == 1)
		{
			ft_putchar(str[i] - 32);
			last_letter = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z' && last_letter == 0)
		{
			ft_putchar(str[i] + 32);
			last_letter = 0;
		}
		else
		{
			ft_putchar(str[i]);
			last_letter = 0;
		}
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
			ft_str_capitalizer(argv[i++]);
	}
	else
		ft_putchar('\n');
	return (0);
}
