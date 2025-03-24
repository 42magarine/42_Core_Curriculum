/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:47:50 by mott              #+#    #+#             */
/*   Updated: 2023/10/27 19:11:55 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	chr;
	size_t			i;

	chr = (unsigned char)c;
	i = ft_strlen(str);
	while (i > 0 && str[i] != chr)
		i--;
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (NULL);
}
