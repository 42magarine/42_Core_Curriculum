/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:57:08 by mott              #+#    #+#             */
/*   Updated: 2023/10/13 21:24:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_count(const char *s, char c)
{
	size_t	i;
	size_t	num_of_strs;

	i = 0;
	num_of_strs = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			num_of_strs++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (num_of_strs);
}

static size_t	ft_substr_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **array_of_strs)
{
	size_t	i;

	i = 0;
	while (array_of_strs[i] != NULL)
	{
		free(array_of_strs[i]);
		i++;
	}
	free(array_of_strs);
}

char	**ft_split(const char *s, char c)
{
	char	**array_of_strs;
	size_t	i;
	size_t	j;

	array_of_strs = (char **)malloc((ft_str_count(s, c) + 1) * sizeof(char *));
	if (array_of_strs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_str_count(s, c))
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		array_of_strs[i] = ft_substr(s, j, ft_substr_len(&s[j], c));
		if (array_of_strs[i] == NULL)
		{
			ft_free(array_of_strs);
			return (NULL);
		}
		j = j + ft_substr_len(&s[j], c);
		i++;
	}
	array_of_strs[i] = NULL;
	return (array_of_strs);
}
