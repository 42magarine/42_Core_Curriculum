/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:33:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/16 18:34:51 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long	shift_reset_buffer(long len, char *buffer)
{
	if (len >= BUFFER_SIZE)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		return (BUFFER_SIZE);
	}
	ft_memcpy(buffer, buffer + len, BUFFER_SIZE - len);
	ft_memset(buffer + BUFFER_SIZE - len, 0, len);
	return (BUFFER_SIZE - len);
}

void	read_error(int error, char *buffer, char **line)
{
	if (error < 0)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
	}
}
