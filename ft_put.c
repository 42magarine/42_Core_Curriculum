/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:13:04 by mott              #+#    #+#             */
/*   Updated: 2023/10/25 16:55:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_putstr(char *s, int str_len)
{
	int	i;

	// if (s == NULL)
	// 	s = "(null)";
	i = 0;
	while (i < str_len)
		ft_putchar(s[i++]);
	return (str_len);
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
		nbytes += ft_putnbr(n / 10);
	nbytes += ft_putchar(n % 10 + '0');
	return (nbytes);
}

// int	ft_putunbr(unsigned int n)
// {
// 	return (ft_putnbr_base(n, 10, true));
// }

int	ft_putnbr_base(unsigned long n, unsigned long base, bool lower)
{
	static const char	*digits;
	int					nbytes;
	char				c;

	digits = "0123456789abcdef";
	nbytes = 0;
	if (n >= base)
		nbytes += ft_putnbr_base(n / base, base, lower);
	if (lower == true)
		c = digits[n % base];
	else
		c = ft_toupper(digits[n % base]);
	nbytes += ft_putchar(c);
	return (nbytes);
}

int	ft_putnbr_base16(unsigned long n, char xp)
{
	int	nbytes;

	nbytes = 0;
	if (xp == 'p')
		nbytes += ft_putstr("0x", 2);
	nbytes += ft_putnbr_base(n, 16, (xp == 'x' || xp == 'p'));
	return (nbytes);
}
