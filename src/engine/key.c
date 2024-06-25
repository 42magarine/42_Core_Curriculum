/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/25 17:40:07 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// sin (0°)		=  0	cos (0°)	=  1
// sin (90°)	=  1	cos (90°)	=  0
// sin (180°)	=  0	cos (180°)	= -1
// sin (270°)	= -1	cos (270°)	=  0
static void	move_player(t_game *game, char key, double move_x, double move_y)
{
	if (key == 'W' || key == 'S')
	{
		move_x *= round(MOVE_SPEED * cos(game->player->dir));
		move_y *= round(MOVE_SPEED * sin(game->player->dir));
	}
	else if (key == 'A' || key == 'D')
	{
		move_x *= round(MOVE_SPEED * sin(game->player->dir));
		move_y *= round(MOVE_SPEED * cos(game->player->dir));
	}
	if (game->map->map[(int)game->player->pos.y >> 5]
			[(int)(game->player->pos.x + move_x) >> 5] != '1')
		game->player->pos.x += move_x;
	if (game->map->map[(int)(game->player->pos.y + move_y) >> 5]
			[(int)game->player->pos.x >> 5] != '1')
		game->player->pos.y += move_y;
	game->recalculate = true;
}

void	rotate_player(t_game *game, char dir)
{
	if (dir == 'L')
		game->player->dir = pi_overflow(game->player->dir + ROTATION_SPEED);
	else if (dir == 'R')
		game->player->dir = pi_overflow(game->player->dir - ROTATION_SPEED);
	game->recalculate = true;
}

void	minimap(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		game->minimap = !game->minimap;
	game->recalculate = true;
}

// void	key_hook(mlx_key_data_t keydata, void *param)
void	key_hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->window->mlx);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_LEFT) == true)
		rotate_player(game, 'L');
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_RIGHT) == true)
		rotate_player(game, 'R');
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_W) == true)
		move_player(game, 'W', 1.0, -1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_A) == true)
		move_player(game, 'A', -1.0, -1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_S) == true)
		move_player(game, 'S', -1.0, 1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_D) == true)
		move_player(game, 'D', 1.0, 1.0);
	// minimap(keydata, game);
}
