/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/10 15:44:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/game.h"

static void	ft_move_player(t_game *game, int x, int y)
{
	game->player->image->instances[0].x += x;
	game->player->image->instances[0].y += y;
	game->player->x += x;
	game->player->y += y;
}

// void	ft_key_hook(mlx_key_data_t keydata, void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = param;

// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(mlx);

// 	if (keydata.key == MLX_KEY_LEFT
// 		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 		printf("left\n");
// 	if (keydata.key == MLX_KEY_RIGHT
// 		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 		printf("right\n");

// 	if (keydata.key == MLX_KEY_W
// 		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 		ft_move_player(mlx, 0, -player_size);
// 	if (keydata.key == MLX_KEY_A
// 		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 		ft_move_player(mlx, -player_size, 0);
// 	if (keydata.key == MLX_KEY_S
// 		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 		ft_move_player(mlx, 0, player_size);
// 	if (keydata.key == MLX_KEY_D
// 		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
// 		ft_move_player(mlx, player_size, 0);
// }

void	ft_key_hook(void *param)
{
	t_game	*game;

	game = param;

	if (mlx_is_key_down(game->window->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->window->mlx);

	if (mlx_is_key_down(game->window->mlx, MLX_KEY_LEFT) == true)
		printf("left\n");
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_RIGHT) == true)
		printf("right\n");

	if (mlx_is_key_down(game->window->mlx, MLX_KEY_W) == true)
		ft_move_player(game, 0, -game->player->size);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_A) == true)
		ft_move_player(game, -game->player->size, 0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_S) == true)
		ft_move_player(game, 0, game->player->size);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_D) == true)
		ft_move_player(game, game->player->size, 0);
}

void	ft_loop_hook(void *param)
{
	(void)param;
}
