/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/11 20:23:42 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static bool	is_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	else
		return (false);
}

static bool	is_map_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (is_map_char(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	parse_map(t_game *game, char *line)
{
	static int	i = 0;

	if (line[0] != '\0' && is_map_line(line) == true)
	{
		game->map->map[i] = ft_strdup(line);
		i++;
	}
}
