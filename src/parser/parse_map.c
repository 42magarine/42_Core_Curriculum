/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:13:07 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/01 16:16:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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

	parse_mapsize(game, filename);
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
