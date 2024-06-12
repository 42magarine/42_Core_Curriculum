/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:27:53 by mott              #+#    #+#             */
/*   Updated: 2024/06/12 22:34:02 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*g_map[] =
{ // 0123456789012345
	"1111111111111111", //0
	"1010000000100001", //1
	"1010000000100001", //2
	"1010000000100001", //3
	"10100N0000000001", //4
	"1000010000000101", //5
	"1000000000000001", //6
	"1111111111111111", //7
};

void	init_var(t_game *game, t_player *player, t_window *window, t_map *map)
{
	game->player = player;
	player->x = 5 * 64 + 64 / 2;
	player->y = 4 * 64 + 64 / 2;
	player->fov = 60;
	// player->direction = 0;				// 0°	east
	player->direction = M_PI / 2;		// 90°	north
	// player->direction = M_PI;			// 180°	west
	// player->direction = 3 * M_PI / 2;	// 270°	south
	player->size = 8;

	game->window = window;
	window->width = 1024;
	window->height = 512;

	game->map = map;
	map->x = 16;
	map->y = 8;
	map->field_size = 64;
}

int	init_mlx(t_game *game)
{
	// mlx_set_setting(MLX_MAXIMIZED, true);

	game->window->mlx = mlx_init(game->window->width, game->window->height, "cub3D", false);
	if (game->window->mlx == NULL)
		ft_exit(mlx_strerror(mlx_errno));

 	game->window->image = mlx_new_image(game->window->mlx, game->window->width, game->window->height);
	if (game->window->image == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	mlx_loop_hook(game->window->mlx, &ft_key_hook, game);
	mlx_loop_hook(game->window->mlx, &ft_loop_hook, game);
	mlx_loop(game->window->mlx);

	mlx_delete_image(game->window->mlx, game->window->image);
	mlx_terminate(game->window->mlx);
	return (EXIT_SUCCESS);
}
