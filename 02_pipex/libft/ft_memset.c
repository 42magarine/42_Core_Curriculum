/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:33:09 by mott              #+#    #+#             */
/*   Updated: 2023/10/27 19:08:39 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *)ptr;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
		str[i++] = chr;
	return (ptr);
}
