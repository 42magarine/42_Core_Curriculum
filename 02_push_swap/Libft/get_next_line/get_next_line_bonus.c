/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:04:08 by mott              #+#    #+#             */
/*   Updated: 2023/11/17 13:40:44 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*next_line[OPEN_MAX];
	char		*current_line;
	char		*temp;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	temp = ft_read_line(fd, next_line[fd]);
	current_line = ft_create_current_line(temp);
	next_line[fd] = ft_create_next_line(temp);
	return (free(temp), current_line);
}

char	*ft_read_line(int fd, char *temp)
{
	char		*buffer;
	char		*swap;
	ssize_t		nbytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr(temp, '\n') == NULL)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			if (temp != NULL)
				free(temp);
			return (free(buffer), NULL);
		}
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		swap = temp;
		temp = ft_strjoin(swap, buffer);
		free(swap);
	}
	return (free(buffer), temp);
}

char	*ft_create_current_line(char *temp)
{
	char	*current_line;
	size_t	start;
	size_t	n;

	start = 0;
	if (ft_strchr(temp, '\n') != NULL)
		n = ft_strchr(temp, '\n') - temp + 1;
	else
		n = ft_strlen(temp);
	current_line = ft_substr(temp, start, n);
	return (current_line);
}

char	*ft_create_next_line(char *temp)
{
	char	*next_line;
	size_t	start;
	size_t	n;

	if (ft_strchr(temp, '\n') != NULL)
		start = ft_strchr(temp, '\n') - temp + 1;
	else
		return (NULL);
	n = ft_strlen(temp) - start;
	if (n == 0)
		return (NULL);
	next_line = ft_substr(temp, start, n);
	return (next_line);
}
