/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/23 12:56:33 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	move_player(t_game *game, char key, double move_x, double move_y)
{
	if (key == 'W' || key == 'S')
	{
		move_x *= MOVE_SPEED * cos(game->player->dir);
		move_y *= MOVE_SPEED * sin(game->player->dir);
	}
	else if (key == 'A' || key == 'D')
	{
		move_x *= MOVE_SPEED * sin(game->player->dir);
		move_y *= MOVE_SPEED * cos(game->player->dir);
	}
	if (game->map->map[(int)(game->player->pos.y + move_y) >> 6]
			[(int)(game->player->pos.x + move_x) >> 6] == '1')
		return ;
	game->player->pos.x += move_x;
	game->player->pos.y += move_y;
	game->recalculate = true;
}

static void	rotate_player(t_game *game, char dir)
{
	if (dir == 'L')
		game->player->dir += ROTATION_SPEED;
	else if (dir == 'R')
		game->player->dir -= ROTATION_SPEED;
	if (game->player->dir < 0)
		game->player->dir += TWO_PI;
	else if (game->player->dir >= TWO_PI)
		game->player->dir -= TWO_PI;
	game->recalculate = true;
}

void	key_hook(t_game	*game)
{
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->window->mlx);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_LEFT) == true)
		rotate_player(game, 'L');
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_RIGHT) == true)
		rotate_player(game, 'R');
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_W) == true)
		move_player(game, 'W', 1.0, -1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_A) == true)
		move_player(game, 'A', -1.0, 1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_S) == true)
		move_player(game, 'S', -1.0, 1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_D) == true)
		move_player(game, 'D', 1.0, 1.0);
}
