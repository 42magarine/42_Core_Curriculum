/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:10:53 by mott              #+#    #+#             */
/*   Updated: 2023/10/25 16:04:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_specifiers(va_list *ap, const char *format, t_flags *flags)
{
	if (*format == 'c')
		return (prepare_c(va_arg(*ap, int), flags));
	if (*format == 's')
		return (prepare_s(va_arg(*ap, char *), flags));
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (*format == 'u')
		return (ft_putnbr(va_arg(*ap, unsigned int)));
	if (*format == 'x' || *format == 'X')
		return (ft_putnbr_base16(va_arg(*ap, unsigned int), *format));
	if (*format == 'p')
		return (ft_putnbr_base16(va_arg(*ap, unsigned long), *format));
	if (*format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		nbytes;
	int		n;
	va_list	ap;
	t_flags	flags;	// should i use malloc?

	flags = (t_flags){0};	// This initializes all the fields to their default values (0 or false).
	nbytes = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = ft_flags(&ap, format, &flags);
			n = ft_conversion_specifiers(&ap, format, &flags);
			if (n == -1)
				return (-1);
			nbytes += n;
		}
		else
			nbytes += write(STDOUT_FILENO, format, 1);
		format++;
	}
	va_end(ap);
	return (nbytes);
}

// int	ft_printf(const char *format, ...)
// {
// 	int		nbytes;
// 	va_list	ap;

// 	va_start(ap, format);
// 	nbytes = (vprintf(format, ap));
// 	va_end(ap);
// 	return (nbytes);
// }
