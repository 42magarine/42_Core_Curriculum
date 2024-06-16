/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/16 15:49:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	ft_move_player(t_player *player, int x, int y)
{
	player->pos->x += x;
	player->pos->y += y;
}

static void	ft_rotate_player(t_player *player, char dir)
{
	if (dir == 'L')
		player->dir += 0.02;
	else if (dir == 'R')
		player->dir -= 0.02;

	if (player->dir < 0)
		player->dir += PI_TWO;
	else if (player->dir >= PI_TWO)
		player->dir -= PI_TWO;
}

void	ft_key_hook(t_game *game)
{
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->window->mlx);

	if (mlx_is_key_down(game->window->mlx, MLX_KEY_LEFT) == true)
		ft_rotate_player(game->player, 'L');
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_RIGHT) == true)
		ft_rotate_player(game->player, 'R');

	if (mlx_is_key_down(game->window->mlx, MLX_KEY_W) == true)
		ft_move_player(game->player, 0, -PLAYER_SIZE);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_A) == true)
		ft_move_player(game->player, -PLAYER_SIZE, 0);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_S) == true)
		ft_move_player(game->player, 0, PLAYER_SIZE);
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_D) == true)
		ft_move_player(game->player, PLAYER_SIZE, 0);
}

void	ft_loop_hook(void *param)
{
	t_game	*game;

	game = param;

	ft_key_hook(game);
	ft_draw_background(game);

	// ft_draw_map_2D(game);
	// ft_draw_player(game);
	// ft_ray_caster(game);

	if (mlx_image_to_window(game->window->mlx, game->window->image, 0, 0) == -1)
		ft_exit(mlx_strerror(mlx_errno));
}
