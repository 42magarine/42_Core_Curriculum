/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/21 17:52:46 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	move_player(t_game *game, int x, int y)
{
	int	px;
	int	py;
	int	i;

	i = 0;
	while (i++ < (P_SIZE >> 1))
	{
		px = (int)(game->player->pos.x + x) >> 6;
		py = (int)(game->player->pos.y + y) >> 6;
		if (game->map->map[py][px] == '1')
			return ;
		game->player->pos.x += x;
		game->player->pos.y += y;
	}
	game->recalculate = true;
}

static void	rotate_player(t_game *game, char dir)
{
	if (dir == 'L')
		game->player->dir += 0.1;
	else if (dir == 'R')
		game->player->dir -= 0.1;
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
		move_player(game, 0, -(P_SIZE >> 1));
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_A) == true)
		move_player(game, -(P_SIZE >> 1), 0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_S) == true)
		move_player(game, 0, (P_SIZE >> 1));
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_D) == true)
		move_player(game, (P_SIZE >> 1), 0);
}
