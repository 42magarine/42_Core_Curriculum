/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:31:12 by mott              #+#    #+#             */
/*   Updated: 2024/06/16 15:35:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_exit(const char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	main(void)
{
	t_game		game;
	t_player	player;
	t_window	window;
	t_point		map;

	init_var(&game, &player, &window, &map);
	init_mlx(&game.window);
	// mlx_loop_hook(game.window->mlx, &ft_key_hook, &game);
	mlx_loop_hook(game.window->mlx, &ft_loop_hook, &game);
	mlx_loop(game.window->mlx);
	mlx_delete_image(game.window->mlx, game.window->image);
	mlx_terminate(game.window->mlx);
	return (EXIT_SUCCESS);
}
