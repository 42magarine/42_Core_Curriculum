/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:06:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/23 19:00:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (argc != 2)
		ft_error(game, "missing mapfile (argv[1])");
	init_map(game, argv[1]);
	init_game(game);
	mlx_loop_hook(game->window->mlx, &loop_hook, game);
	mlx_loop(game->window->mlx);
	// free_game(game);
	return (EXIT_SUCCESS);
}
