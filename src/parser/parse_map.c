/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/16 18:40:37 by fwahl            ###   ########.fr       */
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

void	set_map_size(t_game *game, char *filename)
{
	int		fd;
	int		y_max;
	int		x_max;
	char	*line;

	x_max = 0;
	y_max = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		if (line[0] != '\0' && is_map_line(line) == true)
		{
			if (ft_strlen(line) > x_max)
				x_max = ft_strlen(line);
			y_max++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->x_max = x_max;
	game->map->y_max = y_max;
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
