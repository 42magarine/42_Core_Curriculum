/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:55:44 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/29 16:21:33 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static bool	all_parsed(t_game *game, t_parse *parse)
{
	bool	all_parsed;

	all_parsed = false;
	if (!parse->floor_ceiling)
		ft_error(game, "floor_ceiling not parsed correctly");
	if (!parse->map)
		ft_error(game, "map not parsed correctly");
	if (!parse->player)
		ft_error(game, "player not parsed correctly");
	if (!parse->walls)
		ft_error(game, "walls not parsed correctly");
	if (parse->floor_ceiling && parse->map && parse->player && parse->walls)
		all_parsed = true;
	return (all_parsed);
}

static bool	is_valid_start(t_map *map, int x, int y, char c)
{
	if (x < 0 || x >= (int)ft_strlen(map->map[y]) || y < 0 || y >= map->max.y)
		return (false);
	if (map->map[y][x] == '1' || map->map[y][x] == 'P' || map->map[y][x] == c)
		return (false);
	if (ft_isspace(map->map[y][x]))
		return (false);
	return (true);
}

static bool	flood_fill(t_map *map, int x, int y, char c)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (x < 0 || x >= (int)ft_strlen(map->map[y]) || y < 0 || y >= map->max.y)
		return (false);
	if (map->map[y][x] == '1' || map->map[y][x] == c)
		return (true);
	if (map->map[y][x] == ' ')
		return (false);
	map->map[y][x] = c;
	up = flood_fill(map, x, y - 1, c);
	down = flood_fill(map, x, y + 1, c);
	left = flood_fill(map, x - 1, y, c);
	right = flood_fill(map, x + 1, y, c);
	return (up && down && left && right);
}

static void	validate_map(t_game *game)
{
	int		x;
	int		y;
	int		i;
	bool	valid;
	char	**temp;

	if (!all_parsed(game, game->parsed))
		ft_error(game, "values not parsed correctly");
	x = game->player->pos.x;
	y = game->player->pos.y;
	if (!is_valid_start(game->map, x, y, '2'))
		ft_error(game, "invalid player start position");
	temp = ft_strarray_dup(game->map->map);
	valid = flood_fill(game->map, x, y, '2');
	i = 0;
	while (i < game->map->max.y)
	{
		free(game->map->map[i]);
		game->map->map[i] = ft_strdup(temp[i]);
		i++;
	}
	free(temp);
	if (!valid)
		ft_error(game, "flood_fill - invalid map");
}

void	init_map(t_game *game, char *filename)
{
	parse_mapfile(game, filename);
	validate_map(game);
	debug_parse(game);
}
