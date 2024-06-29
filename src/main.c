/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:06:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/29 17:57:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// #ifdef BONUS
// printf("hello BONUS\n");
// #else
// printf("hello\n");
// #endif

static t_game	*init_game_struct(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->window = ft_calloc(1, sizeof(t_window));
	game->map = ft_calloc(1, sizeof(t_map));
	game->player = ft_calloc(1, sizeof(t_player));
	game->ray = ft_calloc(1, sizeof(t_ray));
	game->tex = ft_calloc(1, sizeof(t_texture));
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	game->parsed = ft_calloc(1, sizeof(t_parse));
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error(NULL, "Usage: ./cub3D ./<path_to_map>");
	game = init_game_struct();
	init_map(game, argv[1]);
	init_game(game);
	mlx_key_hook(game->window->mlx, &special_key_hook, game);
	mlx_loop_hook(game->window->mlx, &loop_hook, game);
	mlx_loop(game->window->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
