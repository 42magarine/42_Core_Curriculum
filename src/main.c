/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:06:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/12 18:27:59 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	parse_mapfile(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	game->map = ft_calloc(1, sizeof(t_map));
	set_map_size(game, filename);
	game->map->map = ft_calloc(game->map->y_max + 1, sizeof(char *));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		parse_textures(game, line);
		parse_floor_ceiling(game, line);
		parse_map(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}


int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (argc != 2)
		ft_error(game, "missing mapfile (argv[1])");
	parse_mapfile(game, argv[1]);
	debug_map(game->map);
	return (EXIT_SUCCESS);
}
