/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:39:39 by mott              #+#    #+#             */
/*   Updated: 2023/11/04 20:27:59 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*current_line;
	char		*buffer;
	ssize_t		nbytes;
	size_t		i;

// fd < 0 || BUFFER_SIZE <= 0

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);

	current_line = ft_strdup("");

	if (next_line != NULL)
	{
		current_line = ft_strjoin(current_line, next_line);
		if (current_line == NULL)
			return (NULL);
	}

	nbytes = -1;
	while (strchr(current_line, '\n') == NULL)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1 || nbytes == 0)
			return (NULL);
		buffer[nbytes] = '\0';
		current_line = ft_strjoin(current_line, buffer);
		if (current_line == NULL)
			return (NULL);
	}
	free(buffer);

	i = 0;
	while (current_line[i] != '\n' && current_line[i] != '\0')
		i++;
	if (current_line[i] == '\n')
		i++;

	char *temp;
	temp = ft_substr(current_line, 0, i);
	if (temp == NULL)
		return (NULL);

	next_line = ft_substr(current_line, i, strlen(current_line) - i);

	free(current_line);

	return (temp);
}
