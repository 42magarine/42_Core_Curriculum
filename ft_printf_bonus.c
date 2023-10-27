/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:10:56 by mott              #+#    #+#             */
/*   Updated: 2023/10/25 17:19:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// +---+---+---+---+---+-----+---+---+
// |   | # | 0 | - | + | ' ' | * | N |
// +---+---+---+---+---+-----+---+---+
// | c |   |   | Y |   |     | N | Y |
// | s |   |   | Y |   |  Y  | N | Y |
// | d |   | Y | Y | Y |  Y  | N | Y |
// | i |   | Y | Y | Y |  Y  | N | Y |
// | u |   | Y | Y | Y |  Y  | N | Y |
// | x | Y | Y | Y |   |  Y  | N | Y |
// | X | Y | Y | Y |   |  Y  | N | Y |
// | p |   | Y | Y |   |  Y  | N | Y |
// +---+---+---+---+---+-----+---+---+

const char	*ft_flags(va_list *ap, const char *format, t_flags *flags)
{
	while (ft_isflag(*++format) == 1)
	{
		if (*format == '#')
			flags->alternate_form = true;
		if (*format == '0' && flags->field_width_value == 0)
			flags->zero_padded = true;
		if (*format == '-')
			flags->left_adjusted = true;
		if (*format == ' ')
			flags->space_sign = true;
		if (*format == '+')
			flags->plus_sign = true;
		if (*format == '*')
		{
			flags->field_width_argument = true;
			flags->field_width_value = va_arg(*ap, int);
			if (flags->field_width_value < 0)
			{
				flags->left_adjusted = true;
				flags->field_width_value = -flags->field_width_value;
			}
		}
		if (*format == '.')
		{
			flags->precision = true;
			if (*++format == '*')
			{
				flags->precision_value = va_arg(*ap, int);
				// printf("%d\n", flags->precision_value);
			}
			else
			{
				while (ft_isdigit(*format) == 1)
				{
					flags->precision_value = flags->precision_value * 10 + *format++ - '0';
					// printf("%d\n", flags->precision_value);
				}
				break ;
			}
		}
		if (ft_isdigit(*format) == 1)
			flags->field_width_value = flags->field_width_value * 10 + *format - '0';
	}
	return (format);
}

int	ft_isflag(int c)
{
	if (c == '#' || c == '-' || c == ' ' || c == '+' || c == '*' || c == '.'
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	prepare_c(int c, t_flags *flags)
{
	int	nbytes;

	nbytes = 0;
	if (flags->left_adjusted == true)
		nbytes += ft_putchar(c);
	if (flags->field_width_value != false)
		nbytes += field_width(flags, sizeof(char));
	if (flags->left_adjusted == false)
		nbytes += ft_putchar(c);
	return (nbytes);
}

int	prepare_s(char *s, t_flags *flags)
{
	int	nbytes;
	int	str_len;

	nbytes = 0;
	str_len = ft_strlen(s);
	if (flags->precision == true && flags->precision_value < str_len)
		str_len = flags->precision_value;
	if (flags->left_adjusted == true)
		nbytes += ft_putstr(s, str_len);
	if (flags->field_width_value != false)
		nbytes += field_width(flags, str_len);
	if (flags->left_adjusted == false)
		nbytes += ft_putstr(s, str_len);
	return (nbytes);
}

int	field_width(t_flags *flags, int length)
{
	int	nbytes;

	nbytes = 0;
	while (flags->field_width_value-- > length)
		nbytes += ft_putchar(' ');
	return (nbytes);
}
