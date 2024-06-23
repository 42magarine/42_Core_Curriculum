/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:06:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/23 14:54:13 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	parse_mapfile(t_game *game, char *filename)
{
	int		fd2;
	char	*line;

	init_map(game, filename);
	game->parsed = ft_calloc(1, sizeof(t_parse));
	fd2 = open(filename, O_RDONLY);
	if (fd2 == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd2);
	while (line != NULL)
	{
		cut_next_line(line);
		if (!game->parsed->walls)
			parse_walls(game, line);
		if (!game->parsed->floor_ceiling)
			parse_floor_ceiling(game, line);
		if (!game->parsed->map)
			parse_map(game, line);
		free(line);
		line = get_next_line(fd2);
	}
	close(fd2);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (argc != 2)
		ft_error(game, "missing mapfile (argv[1])");
	parse_mapfile(game, argv[1]);
	debug_map(game->map);
	debug_player(game->player);
	validate_map(game);
	init_game(game);
	mlx_loop_hook(game->window->mlx, &loop_hook, game);
	mlx_loop(game->window->mlx);
	mlx_delete_image(game->window->mlx, game->window->image);
	mlx_terminate(game->window->mlx);
	return (EXIT_SUCCESS);
}
