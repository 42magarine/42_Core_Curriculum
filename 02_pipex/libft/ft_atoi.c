/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:45:53 by mott              #+#    #+#             */
/*   Updated: 2023/10/27 15:08:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		n;
	size_t	i;

	sign = 1;
	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 1)
		n = n * 10 + str[i++] - '0';
	return (sign * n);
}
