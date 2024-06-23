/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:55:44 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/23 14:58:32 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static bool	is_valid_start(t_map *map, int x, int y, char filler)
{
	if (x < 0 || x >= (int)ft_strlen(map->map[y]) || y < 0 || y >= map->max.y)
		return (false);
	if (map->map[y][x] == '1' || map->map[y][x] == filler)
		return (false);
	if (ft_isspace(map->map[y][x]))
		return (false);
	return (true);
}

static bool	flood_fill(t_map *map, int x, int y, char filler)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (x < 0 || x >= (int)ft_strlen(map->map[y]) || y < 0 || y >= map->max.y)
		return (false);
	if (map->map[y][x] == '1' || map->map[y][x] == filler || map->map[y][x] == ' ')
		return (true);
	map->map[y][x] = filler;
	up = flood_fill(map, x, y - 1, filler);
	down = flood_fill(map, x, y + 1, filler);
	left = flood_fill(map, x - 1, y, filler);
	right = flood_fill(map, x + 1, y, filler);
	return (up && down && left && right);
}

void	validate_map(t_game *game)
{
	int		x;
	int		y;
	int		i;
	bool	valid;
	char	**temp;

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
