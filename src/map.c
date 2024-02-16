/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:38:58 by mott              #+#    #+#             */
/*   Updated: 2024/02/16 20:45:27 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_load_map(t_game *game, char *filename)
{
	so_map_size(game, filename);
	game->map = malloc(sizeof(char *) * game->map_size->y + 1);
	if (game->map == NULL)
		so_exit("malloc", game);
	so_read_map(game, filename);
	so_map_rectangular(game);
	so_map_wall(game);
	so_map_objects(game, 'P');
	so_map_objects(game, 'C');
	so_map_objects(game, 'E');
}

void	so_map_size(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		so_exit("open", game);
	game->map_size = malloc(sizeof(t_xy));
	if (game->map_size == NULL)
		so_exit("malloc", game);
	line = get_next_line(fd);
	game->map_size->x = so_strlen(line);
	game->map_size->y = 0;
	while (line != NULL)
	{
		game->map_size->y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	so_read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		so_exit("open", game);
	i = 0;
	while (i < game->map_size->y)
	{
		line = get_next_line(fd);
		game->map[i] = line;
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}

// Calculates the length of the string until '\n'.
int	so_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
