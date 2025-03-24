/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:38:58 by mott              #+#    #+#             */
/*   Updated: 2024/02/20 12:25:21 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Opens, reads and validates the map.
void	so_init_map(t_game *game, char *file)
{
	char	**map_copy;

	so_map_size(game, file);
	game->map = malloc(sizeof(char *) * (game->map_size.y + 1));
	if (game->map == NULL)
		so_exit(ERR_SYS, "malloc", game);
	so_read_map(game, file);
	so_loop_map(game, so_count_objects);
	if (game->collect_count < 1)
		so_exit(ERR_USE, "Wrong number of collectibles.\n", game);
	if (game->exit_count != 1)
		so_exit(ERR_USE, "Wrong number of exits.\n", game);
	if (game->player_count != 1)
		so_exit(ERR_USE, "Wrong number of players.\n", game);
	if (game->enemy_count > 1)
		so_exit(ERR_USE, "Wrong number of enemies.\n", game);
	so_map_rectangular(game);
	so_map_wall(game);
	map_copy = so_copy_map(game);
	so_flood_fill(map_copy, game->map_size, game->player);
	so_valid_path(game, map_copy);
}

// Calculates width (x) and height (y) of the map.
void	so_map_size(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		so_exit(ERR_SYS, "open", game);
	line = get_next_line(fd);
	game->map_size.x = so_strlen(line);
	game->map_size.y = 0;
	while (line != NULL)
	{
		game->map_size.y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

// Reads the map using malloc.
void	so_read_map(t_game *game, char *file)
{
	int	fd;
	int	y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		so_exit(ERR_SYS, "open", game);
	y = 0;
	while (y < game->map_size.y)
	{
		game->map[y] = get_next_line(fd);
		y++;
	}
	game->map[y] = NULL;
	close(fd);
}

// Loops through the map and calls the given function for each (x,y).
void	so_loop_map(t_game *game, void (*f)(t_game *game, int x, int y))
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			f(game, x, y);
			x++;
		}
		y++;
	}
}

// Counts the number of all objects.
void	so_count_objects(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->collect_count++;
	else if (game->map[y][x] == 'E')
		game->exit_count++;
	else if (game->map[y][x] == 'P')
	{
		game->player_count++;
		game->player.y = y;
		game->player.x = x;
	}
	else if (game->map[y][x] == 'X')
	{
		game->enemy_count++;
		game->enemy.y = y;
		game->enemy.x = x;
	}
	else if (game->map[y][x] != '0' && game->map[y][x] != '1')
		so_exit(ERR_USE, "Forbidden character in map.\n", game);
}
