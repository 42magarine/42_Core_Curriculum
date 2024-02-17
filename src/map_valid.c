/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:40:25 by mott              #+#    #+#             */
/*   Updated: 2024/02/17 16:28:23 by mott             ###   ########.fr       */
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
			so_exit("Map is not rectangular.\n", game);
		y++;
	}
}

// Checks if the map is surrounded by walls.
void	so_map_wall(t_game *game)
{
	t_xy	xy;

	xy.y = 0;
	xy.x = 0;
	while (xy.x < game->map_size.x)
	{
		if (game->map[xy.y][xy.x] != '1')
			so_exit("Map is not surrounded by walls.\n", game);
		xy.x++;
	}
	xy.y++;
	xy.x = game->map_size.x - 1;
	while (xy.y < game->map_size.y - 1)
	{
		if (game->map[xy.y][0] != '1' || game->map[xy.y][xy.x] != '1')
			so_exit("Map is not surrounded by walls.\n", game);
		xy.y++;
	}
	xy.x = 0;
	while (xy.x < game->map_size.x)
	{
		if (game->map[xy.y][xy.x] != '1')
			so_exit("Map is not surrounded by walls.\n", game);
		xy.x++;
	}
}

// Counts the number of the given object.
int	so_object_counter(char **map, t_xy map_size, char c)
{
	t_xy	xy;
	int		counter;

	counter = 0;
	xy.y = 0;
	while (xy.y < map_size.y)
	{
		xy.x = 0;
		while (xy.x < map_size.x)
		{
			if (map[xy.y][xy.x] == c)
				counter++;
			xy.x++;
		}
		xy.y++;
	}
	return (counter);
}

// Checks if the map contains wrong characters.
void	so_map_wrong_character(t_game *game)
{
	t_xy	xy;

	xy.y = 0;
	while (xy.y < game->map_size.y)
	{
		xy.x = 0;
		while (xy.x < game->map_size.x)
		{
			if (game->map[xy.y][xy.x] != '1'
					&& game->map[xy.y][xy.x] != '0'
					&& game->map[xy.y][xy.x] != 'C'
					&& game->map[xy.y][xy.x] != 'E'
					&& game->map[xy.y][xy.x] != 'P')
				so_exit("Wrong character in map.\n", game);
			xy.x++;
		}
		xy.y++;
	}
}
