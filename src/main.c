/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:31:12 by mott              #+#    #+#             */
/*   Updated: 2024/06/10 15:34:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/game.h"

int	ft_exit(const char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static void	init_var(t_game *game, t_player *player, t_window *window, t_map *map)
{
	game->player = player;
	player->x = 1;
	player->y = 1;
	player->fov = 60;
	player->angle = 0;
	player->size = 8;
	player->direction = 'S';

	game->window = window;
	window->width = 1024;
	window->height = 512;

	game->map = map;
	map->x = 16;
	map->y = 8;
	map->field_size = 64;
}

int	main(void)
{
	t_game		game;
	t_player	player;
	t_window	window;
	t_map		map;

	init_var(&game, &player, &window, &map);
	init_mlx(&game);
	return (EXIT_SUCCESS);
}
