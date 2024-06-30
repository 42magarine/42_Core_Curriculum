/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:56:38 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/30 17:07:22 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	all_parsed(t_game *game, t_parse *parse)
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

bool	is_start(t_map *map, int x, int y, char c)
{
	if (x < 0 || x >= (int)ft_strlen(map->map[y]) || y < 0 || y >= map->max.y)
		return (false);
	if (map->map[y][x] == '1' || map->map[y][x] == 'P' || map->map[y][x] == c)
		return (false);
	if (ft_isspace(map->map[y][x]))
		return (false);
	return (true);
}
