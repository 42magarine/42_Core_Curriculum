/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:06:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/22 13:38:27 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (argc != 2)
		ft_error(game, "missing mapfile (argv[1])");
	parse_mapfile(game, argv[1]);
	validate_map(game);
	debug_map(game->map);
	debug_player(game->player);

	init_game(game);
	mlx_loop_hook(game->window->mlx, &loop_hook, game);
	mlx_loop(game->window->mlx);
	mlx_delete_image(game->window->mlx, game->window->image);
	mlx_terminate(game->window->mlx);
	return (EXIT_SUCCESS);
}
