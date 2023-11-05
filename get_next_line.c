/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:39:39 by mott              #+#    #+#             */
/*   Updated: 2023/11/05 23:20:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*current_line;

	current_line = ft_create_current_line(next_line, fd);
	next_line = ft_create_next_line(current_line);
	return (current_line);
}

char	*ft_create_current_line(char *current_line, int fd)
{
	char		*buffer;
	ssize_t		nbytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr(current_line, '\n') == NULL)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
			return (free(buffer), NULL);
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		current_line = ft_strjoin(current_line, buffer);
	}
	return (free(buffer), current_line);
}

char	*ft_create_next_line(char *current_line)
{
	char	*start_next_line;
	char	*next_line;

	start_next_line = ft_strchr(current_line, '\n');
	if (start_next_line == NULL || *(++start_next_line) == '\0')
		return (NULL);
	next_line = ft_strdup(start_next_line);
	*start_next_line = '\0';
	return (next_line);
}
