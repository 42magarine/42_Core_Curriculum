/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:55:44 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/01 14:09:04 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static bool	flood_fill(t_map *map, int x, int y, char c)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (y < 0 || y >= map->max.y || x < 0 || x >= (int)ft_strlen(map->map[y]))
		return (false);
	if (map->map[y][x] && (map->map[y][x] == '1' || map->map[y][x] == c))
		return (true);
	if (map->map[y][x] && map->map[y][x] == ' ')
		return (false);
	map->map[y][x] = c;
	up = flood_fill(map, x, y - 1, c);
	down = flood_fill(map, x, y + 1, c);
	left = flood_fill(map, x - 1, y, c);
	right = flood_fill(map, x + 1, y, c);
	return (up && down && left && right);
}

static void	reset_map(t_game *game, char **temp)
{
	int	i;

	i = 0;
	while (i < game->map->max.y)
	{
		free(game->map->map[i]);
		game->map->map[i] = ft_strdup(temp[i]);
		i++;
	}
}

#ifdef BONUS

static void	validate_map(t_game *game)
{
	char	**temp;

	if (!all_parsed(game, game->parsed))
		ft_error(game, "values not parsed correctly");
	if (!is_start(game->map, game->player->pos.x, game->player->pos.y, '2'))
		ft_error(game, "invalid player start position");
	temp = ft_strarray_dup(game->map->map);
	if (!flood_fill(game->map, game->player->pos.x, game->player->pos.y, '2'))
		ft_error(game, "flood_fill - invalid map (player)");
	reset_map(game, temp);
	if (!flood_fill(game->map, game->map->portal[0].x, game->map->portal[0].y, '2'))
		ft_error(game, "flood_fill - invalid map (portal 1)");
	reset_map(game, temp);
	if (!flood_fill(game->map, game->map->portal[1].x, game->map->portal[1].y, '2'))
		ft_error(game, "flood_fill - invalid map (portal 2)");
	reset_map(game, temp);
	free(temp);
}

#else

static void	validate_map(t_game *game)
{
	char	**temp;

	if (!all_parsed(game, game->parsed))
		ft_error(game, "values not parsed correctly");
	if (!is_start(game->map, game->player->pos.x, game->player->pos.y, '2'))
		ft_error(game, "invalid player start position");
	temp = ft_strarray_dup(game->map->map);
	if (!flood_fill(game->map, game->player->pos.x, game->player->pos.y, '2'))
		ft_error(game, "flood_fill - invalid map (player)");
	reset_map(game, temp);
	free(temp);
}

#endif

void	init_map(t_game *game, char *filename)
{
	parse_mapfile(game, filename);
	// printf("Player Pos	x:%f	y:%f\n", game->player->pos.x, game->player->pos.y);
	validate_map(game);
	debug_parse(game);
}
