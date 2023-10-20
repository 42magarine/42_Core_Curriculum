/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:59:38 by mott              #+#    #+#             */
/*   Updated: 2023/10/20 18:18:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// printf(" NULL %s NULL ", NULL);
	// return printf("\001\002\007\v\010\f\r\n");
	// return ft_printf("%%c");

	// printf("Character: %c\n", c);
	// printf("String: %s\n", s);
	// printf("Pointer: %p\n", p);
	// printf("Decimal: %d\n", d);
	// printf("Integer: %i\n", i);
	// printf("Unsigned Integer: %u\n", u);
	// printf("Lowercase Hex: %x\n", x);
	// printf("Uppercase Hex: %X\n", X);
	// printf("%%%%\n");

	// printf("\n");
	// printf("Decimal with flag '-': %-8d\n", d);
	// printf("Decimal with flag '+': %+d\n", d);
	// printf("Decimal with flag '0': %05d\n", d);
	// printf("Lowercase Hex with flag '#': %#x\n", x);
	// printf("Decimal with flag ' ': % d\n", d);

	// printf("%d\n", ft_printf("test%test"));

	// int i = 123;
	// printf("integer: %i end\n", i);
	// printf("integer: %-50.1i end\n", i);
	// printf("integer: %-50.1f end\n", 4.123);
	// char *s = "hello_world_123456789";
	// printf("integer: %s end\n", s);
	// printf("string: %50.2-----s end\n", s);

	unsigned int c = UINT_MAX;
	printf("start %u end\n", c);
	ft_printf("start %u end\n", c);

	ft_printf("start %X end\n", 0xabc);

	// char *str;
	// printf("start %p end\n", str);
	// printf("start %p end\n", &str);

	// printf("start %lu end\n", sizeof(&str));
	// printf("start %p end\n", (void *)1024);

	// char	*str = "test %c and test %s ";
	// char	d = 'a';
	// char	*s = "str";
	// ft_printf(str, d, s);
	// return (0);

	// return ft_printf("\001\002\007\v\010\f\r\n");
	// return ft_printf("%%c");

	// char *str = "World!";

	// printf("Hello %s %d %cest %i\n", str, 42, 't', -8);
	// ft_printf("Hello %s %d %cest %i\n", str, 42, 't', -8);

	// int min = INT_MIN;
	// int	max = INT_MAX;

	// printf("d = 0: %d\n", 0);
	// printf("d = INT_MIN: %d\n", min);
	// printf("d = INT_MAX: %d\n", max);

	// ft_printf("fd = 0: %d\n", 0);
	// ft_printf("fd = INT_MIN: %d\n", min);
	// ft_printf("fd = INT_MAX: %d\n", max);

	// unsigned int u_max = UINT_MAX;

	// printf("u = 0: %u\n", 0);
	// printf("u = -1: %u\n", -1);
	// printf("u = UINT_MAX: %u\n", u_max);

	// ft_printf("fu = 0: %u\n", 0);
	// ft_printf("fu = -1: %u\n", -1);
	// ft_printf("fu = UINT_MAX: %u\n", u_max);

	// char	*str = "lalala";
	// int		i = 42;
	// int		*ptr = &i;

	// long a = 0;
	// long long int b = 0;

	// printf("1: %llu\n", sizeof(str));
	// printf("a: %lu\n", sizeof(a));
	// printf("3: %lu\n", sizeof(b));

	// printf("p: %p\n", str);
	// printf("p: %p\n", i);
	// printf("p: %p\n", ptr);

	// printf("x: %x\n", str);
	// printf("x: %x\n", i);
	// printf("x: %x\n", ptr);

	// printf("X: %X\n", str);
	// printf("X: %X\n", i);
	// printf("X: %X\n", ptr);

	// ft_printf("fp: %p\n", str);
	// ft_printf("fp: %p\n", i);
	// ft_printf("fp: %p\n", ptr);

	// ft_printf("fx: %x\n", str);
	// ft_printf("fx: %x\n", i);
	// ft_printf("fx: %x\n", ptr);

	// ft_printf("fX: %X\n", str);
	// ft_printf("fX: %X\n", i);
	// ft_printf("fX: %X\n", ptr);

	return (0);
}

// The overall syntax of a conversion specification is:
// %[$][flags][width][.precision][length modifier]conversion

// void	va_start(va_list ap, last);
// The parameter last is the name of the last parameter before the variable argument list.

// type	va_arg(va_list ap, type);
// The va_arg() macro expands to an expression that has the type and value of the next argument in the call.
// Each call to va_arg() modifies ap so that the next call returns the next argument.
// The first use of the va_arg() macro after that of the va_start() macro returns the argument after last.
// Successive invocations return the values of the remaining arguments.

// void	va_end(va_list ap);
// Calling va_end() signals that there are no further arguments, and causes ap to be invalidated.

// ap = argument pointer
