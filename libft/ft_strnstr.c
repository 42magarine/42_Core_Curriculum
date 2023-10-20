/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:47:46 by mott              #+#    #+#             */
/*   Updated: 2023/10/16 17:56:26 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = i;
		k = 0;
		while (haystack[j] == needle[k] && needle[k] != '\0' && j < len)
		{
			j++;
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		else
			i++;
	}
	return (0);
}
