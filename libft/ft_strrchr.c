/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:47:50 by mott              #+#    #+#             */
/*   Updated: 2023/10/16 18:16:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	size_t	i;

	chr = (char)c;
	i = ft_strlen(s);
	while (i > 0 && s[i] != chr)
		i--;
	if (s[i] == chr)
		return ((char *)&s[i]);
	else
		return (NULL);
}
