/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:27:21 by mott              #+#    #+#             */
/*   Updated: 2023/10/20 13:58:30 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SPECIFIERS "cdipsuxX"
#include <stdio.h>
#include <string.h>

void process_flags(t_printf *data, const char **format)
{
	while (42)
	{
		char c = **format;
		if (c == '-')
			data->flags |= FLAG_MINUS;
		else if (c == '+')
			data->flags |= FLAG_PLUS;
		else if (c == )
			data->flags |= FLAG_ZERO;
		else if (c == )
			data->flags |= FLAG_ZERO;
		else if (c == )
		else if (c == )
		{
			data->width = process_width(format);
			continue;
		}
		else
			break;
		(*format)++;
	}
	if (FLAG_MINUS != 0)
		data->flags &= ~FLAG_ZERO;
		data->flags = data->flags & ~FLAG_ZERO;
}

static int	ft_print_conversion(va_list ap, char *format)
{
	t_printf	data;
	char		specifier;
	char	c;
	char	*s;
	int		n;

	data = (t_printf){};
	specifier = *++format;
	process_flags(&data, format);
	if (strchr(SPECIFIERS, specifier) == NULL)
		return -1;
	if (specifier == 'c')
	{
		c = va_arg(ap, int);
		n = printf("char %c", c);
		return (n);
	}
	else if (specifier == 's')
	{
		s = va_arg(ap, char *);
		n = printf("string %s", s);
		return (n);
	}
	print_number();
	if (specifier == 'd' || == 'i' )
	else if (specifier == 'u')
	if (specifier == 'p')
	if (specifier == 'x')
	if (specifier == 'X')
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	size_t	nbytes;
	size_t	n;
	va_list	ap;
	char	*input_string;

	nbytes = 0;
	input_string = strdup(format);
	va_start(ap, format);
	while (*input_string != '\0')
	{
		if (*input_string == '%')
		{
			n = ft_print_conversion(ap, input_string);
			if (n == -1)
				return (-1);
			nbytes = nbytes + n;
			input_string++;
		}
		else
		{
			nbytes = nbytes + write(STDOUT_FILENO, input_string, 1);
		}
		input_string++;
	}
	va_end(ap);
	return (nbytes);
}
