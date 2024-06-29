/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/29 17:50:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static bool	set_map_size(t_game *game, char *line)
{
	static bool	start = false;

	if (start == true && (!is_map_line(line) || line[0] == '\0'))
		return (true);
	if (line[0] != '\0' && is_map_line(line))
	{
		start = true;
		if ((int)ft_strlen(line) > game->map->max.x)
			game->map->max.x = ft_strlen(line);
		if (is_player(line))
			init_player(game, line);
		if (is_portal(line))
			init_portal(game, line);
		game->map->max.y++;
	}
	return (false);
}

static void	parse_map(t_game *game, char *line)
{
	static int	i;
	static bool	start = false;

	if (is_map_line(line) && i <= game->map->max.y)
	{
		start = true;
		game->map->map[i] = ft_strdup(line);
		i++;
	}
	if (start == true && i == game->map->max.y)
		game->parsed->map = true;
}

static void	alloc_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	bool	stop;

	stop = false;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		if (stop == false)
			stop = set_map_size(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->map = ft_calloc(game->map->max.y + 1, sizeof(char *));
}

static void	parse_loop(t_game *game, char *line)
{
	if (game->parsed->map && line != NULL)
	{
		free(line);
		ft_error(game, "invalid map file");
	}
	if (!game->parsed->walls)
		parse_tex(game, line);
	if (!game->parsed->floor_ceiling)
		parse_floor_ceiling(game, line);
	if (!game->parsed->map)
		parse_map(game, line);
}

void	parse_mapfile(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	alloc_map(game, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		parse_loop(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
