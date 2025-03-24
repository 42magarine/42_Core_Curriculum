/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:30:47 by mott              #+#    #+#             */
/*   Updated: 2024/02/27 16:49:10 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_printf
// Expected files   : ft_printf.c
// Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
// -----------------------------------------------------------------------------

// Write a function named `ft_printf` that will mimic the real printf but
// it will manage only the following conversions: s,d and x.

// Your function must be declared as follows:

// int ft_printf(const char *, ... );

// Before you start we advise you to read the `man 3 printf` and the
// `man va_arg`. To test your program compare your results with the true printf.

// Exemples of the function output:

// call: ft_printf("%s\n", "toto");
// out: toto$

// call: ft_printf("Magic %s is %d", "number", 42);
// out: Magic number is 42%

// call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// out: Hexadecimal for 42 is 2a$

// Obs: Your function must not have memory leaks. Moulinette will test that.

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_putstr(char *str)
{
	int	nbytes;

	nbytes = 0;
	if (str == NULL)
		str = "(null)";
	while (str[nbytes] != '\0')
		nbytes += ft_putchar(str[nbytes]);
	return (nbytes);
}

int	ft_putnbr(long n)
{
	int	nbytes;

	nbytes = 0;
	if (n < 0)
	{
		nbytes += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		nbytes += ft_putnbr(n / 10);
	}
	nbytes += ft_putchar(n % 10 + '0');
	return (nbytes);
}

int	ft_putnbr16(unsigned long n)
{
	char	*base;
	int		nbytes;

	base = "0123456789abcdef";
	nbytes = 0;
	if (n >= 16)
	{
		nbytes += ft_putnbr16(n / 16);
	}
	nbytes += ft_putchar(base[n % 16]);
	return (nbytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		nbytes;

	va_start(ap, str);
	nbytes = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
				nbytes += ft_putstr(va_arg(ap, char *));
			else if (*str == 'd')
				nbytes += ft_putnbr(va_arg(ap, int));
			else if (*str == 'x')
				nbytes += ft_putnbr16(va_arg(ap, unsigned int));
		}
		else
			nbytes += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (nbytes);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		nbytes1;
// 	int		nbytes2;
// 	int		n = -2147483648;
// 	char	*str = NULL;

// 	nbytes1 = ft_printf("test : %s : test \n", "Hello World!");
// 	nbytes2 = printf("test : %s : test \n", "Hello World!");

// 	nbytes1 = ft_printf("test: %d\n", n);
// 	nbytes2 = printf("test: %d\n", n);

// 	nbytes1 = ft_printf("test: %x\n", n);
// 	nbytes2 = printf("test: %x\n", n);

// 	nbytes1 = ft_printf("test: %s abc %d lalala %x\n", str, 42, n);
// 	nbytes2 = printf("test: %s abc %d lalala %x\n", str, 42, n);

// 	printf("nbytes1: %d\n", nbytes1);
// 	printf("nbytes2: %d\n", nbytes2);

// 	return (0);
// }
