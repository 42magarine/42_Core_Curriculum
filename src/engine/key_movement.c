/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/27 17:54:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// static void teleport_destination(t_game *game, t_coords destination)
// {

// }

static void	teleport_player(t_game *game)
{
	if ((int)game->player->pos.x >> 6 == game->map->p_one.x
		&& (int)game->player->pos.y >> 6 == game->map->p_one.y)
	{
		game->player->pos.x = ((int)(game->map->p_two.x - 1) << 6) + SIZE;
		game->player->pos.y = ((int)game->map->p_two.y << 6) + (SIZE >> 1);
		game->player->dir = ONE_PI;
	}
	else if ((int)game->player->pos.x >> 6 == game->map->p_two.x
		&& (int)game->player->pos.y >> 6 == game->map->p_two.y)
	{
		game->player->pos.x = (int)(game->map->p_one.x + 1) << 6;
		game->player->pos.y = ((int)game->map->p_one.y << 6) + (SIZE >> 1);
		game->player->dir = 0;
	}
	printf("hello portal\n");
}

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
	if (game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x + move_x) >> 6] != '1'
		&& game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x + move_x) >> 6] != 'D')
		game->player->pos.x += move_x;
	if (game->map->map[(int)(game->player->pos.y + move_y) >> 6]
		[(int)game->player->pos.x >> 6] != '1'
		&& game->map->map[(int)(game->player->pos.y + move_y) >> 6]
		[(int)game->player->pos.x >> 6] != 'D')
		game->player->pos.y += move_y;
	if (game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x) >> 6] == 'P')
	teleport_player(game);
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
