/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/22 13:41:38 by fwahl            ###   ########.fr       */
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
	game->player->pos.y = game->map->max.y;
	while (line[i] != '\0')
	{
		if (is_player_char(line[i]))
		{
			game->player->pos.x = i;
			if (line[i] == 'E')
				game->player->dir = 0;
			if (line[i] == 'N')
				game->player->dir = HALF_PI;
			if (line[i] == 'W')
				game->player->dir = ONE_PI;
			if (line[i] == 'S')
				game->player->dir = THREE_HALF_PI;
		}
		i++;
	}
	if (game->player->pos.x > 0 && game->player->pos.y > 0)
		game->parsed->player = true;
}

static bool	get_map_data(t_game *game, char *line)
{
	static bool	start = false;

	if (start == true && (!is_map_line(line) || line[0] == '\0'))
		return (true);
	if (line[0] != '\0' && is_map_line(line))
	{
		start = true;
		if ((int)ft_strlen(line) > game->map->max.x)
			game->map->max.x = ft_strlen(line);
		if (is_player_start(line))
			init_player(game, line);
		game->map->max.y++;
	}
	return (false);
}

static void	parse_map(t_game *game, char *line)
{
	static int		i = 0;
	static bool		start = false;

	if (is_map_line(line))
	{
		start = true;
		game->map->map[i] = ft_strdup(line);
		i++;
	}
	if (start == true && (line[0] == '\0' || !is_map_line(line)))
		game->parsed->map = true;
}

static void	init_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	bool	stop;

	stop = false;
	game->map = ft_calloc(1, sizeof(t_map));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		if (stop == false)
			stop = get_map_data(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->map = ft_calloc(game->map->max.y + 1, sizeof(char *));
}

void	parse_mapfile(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	game->parsed = ft_calloc(1, sizeof(t_parse));
	init_map(game, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		if (!game->parsed->walls)
			parse_walls(game, line);
		if (!game->parsed->floor_ceiling)
			parse_floor_ceiling(game, line);
		if (!game->parsed->map)
			parse_map(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
