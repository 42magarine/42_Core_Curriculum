/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:04:58 by mott              #+#    #+#             */
/*   Updated: 2023/11/05 22:16:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
		while (str[i] != '\0')
			i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *str1, const char *str2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	newstr = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	if (str1 != NULL)
	{
		while (str1[i] != '\0')
		{
			newstr[i] = str1[i];
			i++;
		}
	}
	j = 0;
	while (str2[j] != '\0')
	{
		newstr[i + j] = str2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (free(str1), newstr);
}

char	*ft_strdup(const char *str)
{
	char	*newstr;
	size_t	n;

	n = ft_strlen(str);
	newstr = (char *)malloc(n + 1);
	if (newstr == NULL)
		return (NULL);
	n = 0;
	while (str[n] != '\0')
	{
		newstr[n] = str[n];
		n++;
	}
	newstr[n] = '\0';
	return (newstr);
}
