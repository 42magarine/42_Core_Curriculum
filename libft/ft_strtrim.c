/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:46:42 by mott              #+#    #+#             */
/*   Updated: 2023/10/13 21:42:04 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strstart(const char *s1, const char *set)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	while (s1[start] != '\0' && set[i] != '\0')
	{
		if (s1[start] == set[i])
		{
			start++;
			i = 0;
		}
		else if (i < ft_strlen(set))
			i++;
	}
	return (start);
}

static size_t	ft_strend(const char *s1, const char *set, size_t start)
{
	size_t	end;
	size_t	i;

	end = ft_strlen(s1);
	i = 0;
	while (end > start && set[i] != '\0')
	{
		if (s1[end - 1] == set[i])
		{
			end--;
			i = 0;
		}
		else if (i < ft_strlen(set))
			i++;
	}
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*strtrim;

	start = ft_strstart(s1, set);
	end = ft_strend(s1, set, start);
	strtrim = (char *)malloc(end - start + 1);
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, s1 + start, end - start + 1);
	return (strtrim);
}
