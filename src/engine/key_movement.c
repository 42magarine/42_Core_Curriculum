/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/07/01 16:02:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// sin (0°)		=  0	cos (0°)	=  1
// sin (90°)	=  1	cos (90°)	=  0
// sin (180°)	=  0	cos (180°)	= -1
// sin (270°)	= -1	cos (270°)	=  0
static void	move_player(t_game *game, char key, float x, float y)
{
	if (key == 'W' || key == 'S')
	{
		x *= MOVE_SPEED * cos(game->player->dir);
		y *= MOVE_SPEED * sin(game->player->dir);
	}
	else if (key == 'A' || key == 'D')
	{
		x *= MOVE_SPEED * sin(game->player->dir);
		y *= MOVE_SPEED * cos(game->player->dir);
	}
	teleport_check(game, x, y);
	if (game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x + x) >> 6] != '1'
		&& game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x + x) >> 6] != 'D'
		&& game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x + x) >> 6] != 'P')
		game->player->pos.x += x;
	if (game->map->map[(int)(game->player->pos.y + y) >> 6]
		[(int)game->player->pos.x >> 6] != '1'
		&& game->map->map[(int)(game->player->pos.y + y) >> 6]
		[(int)game->player->pos.x >> 6] != 'D'
		&& game->map->map[(int)(game->player->pos.y + y) >> 6]
		[(int)game->player->pos.x >> 6] != 'P')
		game->player->pos.y += y;
}

void	rotate_player(t_game *game, char dir)
{
	if (dir == 'L')
		game->player->dir = pi_overflow(game->player->dir + ROTATION_SPEED);
	else if (dir == 'R')
		game->player->dir = pi_overflow(game->player->dir - ROTATION_SPEED);
}

void	key_hook(t_game *game)
{
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_W) == true)
		move_player(game, 'W', 1.0, -1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_A) == true)
		move_player(game, 'A', -1.0, -1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_S) == true)
		move_player(game, 'S', -1.0, 1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_D) == true)
		move_player(game, 'D', 1.0, 1.0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_LEFT) == true)
		rotate_player(game, 'L');
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_RIGHT) == true)
		rotate_player(game, 'R');
}
