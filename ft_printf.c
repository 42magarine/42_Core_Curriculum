/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:10:53 by mott              #+#    #+#             */
/*   Updated: 2023/10/20 16:08:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_specifiers(const char *format, va_list *ap)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (*format == 's')
		return (ft_putstr(va_arg(*ap, char *)));
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

// int	ft_printf(const char *format, ...)
// {
// 	int		nbytes;
// 	va_list	ap;

	// nbytes = 0;
	// va_start(ap, format);
	// while (*format != '\0')
	// {
	// 	if (*format == '%')
	// 	{
	// 		format++;
	// 		nbytes += ft_conversion_specifiers(format, &ap);
	// 	}
	// 	else
	// 		nbytes += write(STDOUT_FILENO, format, 1);
	// 	format++;
	// }
	// free(format);
	// va_end(ap);
	// return (nbytes);
// }

int	ft_printf(const char *format, ...)
{
	int		nbytes;
	va_list	ap;

	va_start(ap, format);
	nbytes = (vprintf(format, ap));
	va_end(ap);
	return (nbytes);
}
