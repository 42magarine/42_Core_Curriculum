/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:58:47 by mott              #+#    #+#             */
/*   Updated: 2023/12/09 12:28:22 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	digits;

	digits = 1;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	digits = ft_count_digits(n);
	str = (char *)malloc(digits + 1);
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n != 0)
	{
		digits--;
		str[digits] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
