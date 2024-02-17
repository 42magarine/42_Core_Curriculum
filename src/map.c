/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:38:58 by mott              #+#    #+#             */
/*   Updated: 2024/02/17 18:56:44 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Loads and validates the map.
void	so_load_map(t_game *game, char *filename)
{
	char	**ff_map;

	so_map_size(game, filename);
	game->map = malloc(sizeof(char *) * (game->map_size.y + 1));
	if (game->map == NULL)
		so_exit("malloc\n", game);
	so_read_map(game, filename);
	so_map_rectangular(game);
	so_map_wall(game);
	if (so_object_counter(game->map, game->map_size, 'C') < 1)
		so_exit("Wrong number of collectibles.\n", game);
	if (so_object_counter(game->map, game->map_size, 'E') != 1)
		so_exit("Wrong number of exits.\n", game);
	if (so_object_counter(game->map, game->map_size, 'P') != 1)
		so_exit("Wrong number of players.\n", game);
	so_map_wrong_character(game);
	ff_map = so_copy_map(game->map, game->map_size);
	so_find_start(game);
	so_flood_fill(ff_map, game->map_size, game->player);
	if (so_object_counter(ff_map, game->map_size, 'C') != 0)
		so_exit("Invalid path to collectible.\n", game); // free?
	if (so_object_counter(ff_map, game->map_size, 'E') != 0)
		so_exit("Invalid path to exit.\n", game); // free ?
	so_free_strs(ff_map);
}

// Calculates width (x) and height (y) of the map.
void	so_map_size(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		so_exit("Could not open file.\n", game);
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
void	so_read_map(t_game *game, char *filename)
{
	int	fd;
	int	y;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		so_exit("Could not open file.\n", game);
	y = 0;
	while (y < game->map_size.y)
	{
		game->map[y] = get_next_line(fd);
		y++;
	}
	game->map[y] = NULL;
	close(fd);
}

// Creates a copy of the map for flood fill.
char	**so_copy_map(char **map, t_xy map_size)
{
	char	**ff_map;
	int		y;

	ff_map = malloc(sizeof(char *) * (map_size.y + 1));
	// if (map == NULL)
	// 	so_exit("malloc\n", NULL); // free?
	y = 0;
	while (y < map_size.y)
	{
		ff_map[y] = ft_strdup(map[y]);
		// if (ff_map[y] == NULL)
		// 	so_exit("malloc\n", NULL); // free?
		y++;
	}
	ff_map[y] = NULL;
	return (ff_map);
}

// Returns the starting position.
void	so_find_start(t_game *game)
{
	game->player.y = 0;
	while (game->player.y < game->map_size.y)
	{
		game->player.x = 0;
		while (game->player.x < game->map_size.x)
		{
			if (game->map[game->player.y][game->player.x] == 'P')
				return ;
			game->player.x++;
		}
		game->player.y++;
	}
}
