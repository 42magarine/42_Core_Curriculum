/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:47:32 by mott              #+#    #+#             */
/*   Updated: 2023/10/16 17:04:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	size_t	i;

	chr = (char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != chr)
		i++;
	if (s[i] == chr)
		return ((char *)&s[i]);
	else
		return (NULL);
}
