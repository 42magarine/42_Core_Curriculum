/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:36:43 by mott              #+#    #+#             */
/*   Updated: 2023/12/13 20:01:19 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);

#include <stdlib.h>

int	ft_count_words(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str != '\0')
			i++;
		while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0')
			str++;
	}
	return (i);
}

int	ft_count_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	char	**array_of_str;
	int		words;
	int		characters;
	int		i;
	int		j;

	words = ft_count_words(str);
	array_of_str = malloc(sizeof(char *) * (words + 1));
	if (array_of_str == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		characters = ft_count_characters(str);
		array_of_str[i] = malloc(characters + 1);
		if (array_of_str[i] == NULL)
			return (NULL);
		j = 0;
		while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0')
			array_of_str[i][j++] = *str++;
		i++;
	}
	return (array_of_str);
}
