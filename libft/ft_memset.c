/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:33:09 by mott              #+#    #+#             */
/*   Updated: 2023/10/16 18:26:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	chr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)b;
	chr = (unsigned char)c;
	while (i < len)
	{
		ptr[i] = chr;
		i++;
	}
	return (ptr);
}
