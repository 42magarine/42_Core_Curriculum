/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:30:50 by mott              #+#    #+#             */
/*   Updated: 2024/02/27 16:54:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name : get_next_line
// Expected files : get_next_line.c (42_EXAM can't take .h for now)
// Allowed functions: read, free, malloc
// -----------------------------------------------------------------------------

// Write a function named get_next_line which prototype should be:
// char *get_next_line(int fd);

// Your function must return a line that has been read from the file descriptor
// passed as parameter. What we call a "line that has been read" is a
// succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with
// End Of File (EOF).

// The line should be returned including the '\n' in case there is one at the
// end of the line that has been read. When you've reached the EOF, you must
// store the current buffer in a char * and return it. If the buffer is empty
// you must return NULL.

// In case of error return NULL. In case of not returning NULL, the pointer
// should be free-able. Your program will be compiled with the flag
// -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read
// calls in your functions.

// Your function must be memory leak free. When you've reached the EOF, your
// function should keep 0 memory allocated with malloc, except the line that
// has been returned.

// Calling your function get_next_line() in a loop will therefore allow you to
// read the text available on a file descriptor one line at a time until the
// end of the text, no matter the size of either the text or one of its lines.

// Make sure that your function behaves well when it reads from a file, from
// the standard output, from a redirection, etc...

// No call to another function will be done on the file descriptor between
// 2 calls of get_next_line(). Finally we consider that get_next_line() has
// an undefined behaviour when reading from a binary file.

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (str != NULL && *str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	temp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
	{
		temp[i + j] = s2[j];
		j++;
	}
	temp[i + j] = '\0';
	return (temp);
}

char	*ft_substr(char *str, int start, int n)
{
	char	*temp;
	int		i;

	if (str == NULL)
		return (NULL);
	temp = malloc(n + 1);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		temp[i] = str[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_read_line(int fd, char *temp)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*to_free;
	int		nbytes;

	while (ft_strchr(temp, '\n') == NULL)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			if (temp != NULL)
				free(temp);
			return (NULL);
		}
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		to_free = temp;
		temp = ft_strjoin(temp, buffer);
		free(to_free);
	}
	return (temp);
}

char	*ft_current_line(char *temp)
{
	char	*current_line;
	int		start;
	int		n;

	start = 0;
	if (ft_strchr(temp, '\n') != NULL)
		n = ft_strchr(temp, '\n') - temp + 1;
	else
		n = ft_strlen(temp);
	current_line = ft_substr(temp, start, n);
	return (current_line);
}

char	*ft_next_line(char *temp)
{
	char	*next_line;
	int		start;
	int		n;

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

char	*get_next_line(int fd)
{
	char		*temp;
	char		*current_line;
	static char	*next_line;

	if (fd < 0)
		return (NULL);
	temp = ft_read_line(fd, next_line);
	current_line = ft_current_line(temp);
	next_line = ft_next_line(temp);
	free(temp);
	return (current_line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text", O_RDONLY);
// 	do
// 	{
// 		line = get_next_line(fd);
// 		// printf("%s", line);
// 		free(line);
// 	} while (line != NULL);
// 	close(fd);
// 	return (0);
// }
