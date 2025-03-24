/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:34:31 by mott              #+#    #+#             */
/*   Updated: 2024/01/07 13:45:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : do_op
// Expected files   : do_op.c
// Allowed functions: atoi, printf, write
// --------------------------------------------------------------------------------

// Write a program that takes three strings:
// - The first and the third one are representations of base-10 signed integers
//   that fit in an int.
// - The second one is an arithmetic operator chosen from: + - * / %

// The program must display the result of the requested arithmetic operation,
// followed by a newline. If the number of parameters is not 3, the program
// just displays a newline.

// You can assume the string have no mistakes or extraneous characters. Negative
// numbers, in input or output, will have one and only one leading '-'. The
// result of the operation fits in an int.

// Examples:

// $> ./do_op "123" "*" 456 | cat -e
// 56088$
// $> ./do_op "9828" "/" 234 | cat -e
// 42$
// $> ./do_op "1" "+" "-43" | cat -e
// -42$
// $> ./do_op | cat -e
// $

#include <stdlib.h>
#include <stdio.h>

void	ft_do_op(int n1, char operator, int n2)
{
	if (operator == '+')
		printf("%d", n1 + n2);
	else if (operator == '-')
		printf("%d", n1 - n2);
	else if (operator == '*')
		printf("%d", n1 * n2);
	else if (operator == '/')
		printf("%d", n1 / n2);
	else if (operator == '%')
		printf("%d", n1 % n2);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		ft_do_op(atoi(argv[1]), argv[2][0], atoi(argv[3]));
	printf("\n");
	return (0);
}
