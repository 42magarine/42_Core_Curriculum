/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:31:43 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/16 18:37:28 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#define ERROR -2

static long	get_nextline_len(char *buffer)
{
	long	i;

	i = 0;
	if (ft_isnextline(buffer[0]))
		return (1);
	while (i < BUFFER_SIZE && buffer[i] && !ft_isnextline(buffer[i]))
		i++;
	if (i < BUFFER_SIZE && ft_isnextline(buffer[i]))
		i++;
	return (i);
}

static int	read_to_buffer(char *buffer, int fd, int *error)
{
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	*error = read(fd, buffer, BUFFER_SIZE);
	if (*error > 0)
		return (1);
	return (0);
}

static long	alloc_or_realloc_line(char **line, long len)
{
	char	*old_line;
	long	old_len;

	old_len = 0;
	if (*line == NULL)
	{
		*line = ft_calloc((len + 1), sizeof(char));
		if (*line == NULL)
			return (ERROR);
	}
	else
	{
		old_line = *line;
		old_len = ft_strlen(old_line);
		*line = ft_calloc((old_len + len + 1), sizeof(char));
		if (*line == NULL)
		{
			*line = old_line;
			return (ERROR);
		}
		ft_memcpy(*line, old_line, old_len);
		free(old_line);
	}
	return (old_len);
}

static long	copy_buff_to_line(char **line, char *buffer, long len)
{
	long	i;
	long	offset;

	i = 0;
	offset = alloc_or_realloc_line(line, len);
	if (offset == ERROR)
		return (ERROR);
	while (i <= len && i < BUFFER_SIZE && buffer[i])
	{
		(*line)[offset + i] = buffer[i];
		if (i < BUFFER_SIZE && ft_isnextline(buffer[i]))
		{
			i++;
			break ;
		}
		i++;
	}
	shift_reset_buffer(len, buffer);
	if (ft_isnextline((*line)[i + offset - 1]))
		len = -1;
	return (len);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	long		len;
	int			error;

	line = NULL;
	error = 0;
	while (buffer[0] || read_to_buffer(buffer, fd, &error))
	{
		len = get_nextline_len(buffer);
		len = copy_buff_to_line(&line, buffer, len);
		if (len < 0)
		{
			if (len == ERROR && line)
			{
				free(line);
				line = NULL;
			}
			break ;
		}
	}
	read_error(error, buffer, &line);
	return (line);
}
