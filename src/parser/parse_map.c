/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/17 19:39:30 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

//   0° = east  = 0
//  90° = north = PI_HALF
// 180°	= west  = PI_ONE
// 270° = south = PI_THREE_HALF
static void	init_player(t_game	*game, char *line)
{
	int	i;

	i = 0;
	if (game->player)
		ft_error(game, "multiple players in map");
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->pos.y = game->map->max.y * FIELD_SIZE;
	while (line[i] != '\0')
	{
		if (is_player_char(line[i]))
		{
			game->player->pos.x = i * FIELD_SIZE;
			if (line[i] == 'E')
				game->player->dir = 0;
			if (line[i] == 'N')
				game->player->dir = PI_HALF;
			if (line[i] == 'W')
				game->player->dir = PI_ONE;
			if (line[i] == 'S')
				game->player->dir = PI_THREE_HALF;
		}
		i++;
	}
}

void	init_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	game->map = ft_calloc(1, sizeof(t_map));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		if (line[0] != '\0' && is_map_line(line))
		{
			if ((int)ft_strlen(line) > game->map->max.x)
				game->map->max.x = ft_strlen(line);
			if (is_player_start(line))
				init_player(game, line);
			game->map->max.y++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->map = ft_calloc(game->map->max.y + 1, sizeof(char *));
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
