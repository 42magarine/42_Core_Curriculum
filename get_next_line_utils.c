/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:32 by mott              #+#    #+#             */
/*   Updated: 2023/11/04 20:21:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char	chr;

	chr = (char)c;
	while (*str != '\0')
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (*str == chr)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *str1, const char *str2)
{
	char	*newstr;
	size_t	n;

	// if (str1 == NULL)
	// 	return (strdup(str2));

	n = ft_strlen(str1) + ft_strlen(str2) + 1;
	newstr = (char *)malloc(n);
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, str1, n);
	ft_strlcat(newstr, str2, n);
	// free(str1);
	return (newstr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstlen >= dstsize)
		return (dstsize + srclen);
	i = 0;
	while (src[i] != '\0' && i < dstsize - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str1)
{
	char	*str2;
	size_t	i;

	i = ft_strlen(str1);
	str2 = (char *)malloc(i + 1);
	if (str2 == NULL)
		return (NULL);
	ft_strlcpy(str2, str1, i + 1);
	return (str2);
}

char	*ft_substr(const char *str, unsigned int start, size_t n)
{
	char	*substr;
	size_t	strlen;

	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	if (start + n > strlen)
		n = strlen - start;
	substr = (char *)malloc(n + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &str[start], n + 1);
	return (substr);
}
