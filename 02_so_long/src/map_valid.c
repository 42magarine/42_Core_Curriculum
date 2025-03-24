/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:40:25 by mott              #+#    #+#             */
/*   Updated: 2024/02/18 21:48:04 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Checks if the map is rectangular.
void	so_map_rectangular(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_size.y)
	{
		if (so_strlen(game->map[y]) != game->map_size.x)
			so_exit(ERR_USE, "Map is not rectangular.\n", game);
		y++;
	}
}

// Checks if the map is surrounded by walls.
void	so_map_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = game->map_size.y - 1;
	while (x < game->map_size.x)
	{
		if (game->map[0][x] != '1' || game->map[y][x] != '1')
			so_exit(ERR_USE, "Map is not surrounded by walls.\n", game);
		x++;
	}
	x = game->map_size.x - 1;
	y = 0;
	while (y < game->map_size.y)
	{
		if (game->map[y][0] != '1' || game->map[y][x] != '1')
			so_exit(ERR_USE, "Map is not surrounded by walls.\n", game);
		y++;
	}
}

// Creates a copy of the map for flood fill.
char	**so_copy_map(t_game *game)
{
	char	**map_copy;
	int		y;

	map_copy = malloc(sizeof(char *) * (game->map_size.y + 1));
	if (map_copy == NULL)
		so_exit(ERR_SYS, "malloc", game);
	y = 0;
	while (y < game->map_size.y)
	{
		map_copy[y] = ft_strdup(game->map[y]);
		if (map_copy[y] == NULL)
		{
			so_free_strs(map_copy);
			so_exit(ERR_SYS, "malloc", game);
		}
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}

// Flood fill.
void	so_flood_fill(char **map, t_xy map_size, t_xy position)
{
	if (position.x < 0 || position.y < 0
		|| position.x >= map_size.x || position.y >= map_size.y
		|| map[position.y][position.x] == '1')
		return ;
	map[position.y][position.x] = '1';
	so_flood_fill(map, map_size, (t_xy){position.x - 1, position.y});
	so_flood_fill(map, map_size, (t_xy){position.x + 1, position.y});
	so_flood_fill(map, map_size, (t_xy){position.x, position.y - 1});
	so_flood_fill(map, map_size, (t_xy){position.x, position.y + 1});
}

// Checks if all objects are reachable.
void	so_valid_path(t_game *game, char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			if (map_copy[y][x] == 'C')
			{
				so_free_strs(map_copy);
				so_exit(ERR_USE, "Invalid path to collectible.\n", game);
			}
			else if (map_copy[y][x] == 'E')
			{
				so_free_strs(map_copy);
				so_exit(ERR_USE, "Invalid path to exit.\n", game);
			}
			x++;
		}
		y++;
	}
	so_free_strs(map_copy);
}
