/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:35:41 by mott              #+#    #+#             */
/*   Updated: 2024/01/08 14:33:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);

int	ft_is_valid(char c, int base)
{
	char	*lower;
	char	*upper;
	int		i;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == lower[i] || c == upper[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	n;
	int	sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	n = 0;
	while (ft_is_valid(*str, str_base))
	{
		if (*str >= '0' && *str <= '9')
			n = n * str_base + *str - '0';
		else if (*str >= 'A' && *str <= 'F')
			n = n * str_base + *str - 'A' + 10;
		else if (*str >= 'a' && *str <= 'f')
			n = n * str_base + *str - 'a' + 10;
		str++;
	}
	return (sign * n);
}
