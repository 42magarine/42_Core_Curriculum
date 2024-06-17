/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:41:35 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/17 15:56:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player_char(c));
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!is_map_char(line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_player_char(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

bool	is_player_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && is_map_line(line))
	{
		if (is_player_char(line[i]))
		{
			return (true);
		}
		i++;
	}
	return (false);
}
