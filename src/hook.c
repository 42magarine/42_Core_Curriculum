/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/12 21:30:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	ft_move_player(t_game *game, int x, int y)
{

	// game->player->image->instances[0].x += x;
	// game->player->image->instances[0].y += y;
	game->player->x += x;
	game->player->y += y;
}

static void	ft_rotate_player(t_game *game, char dir)
{
	if (dir == 'L')
		game->player->direction -= 0.1;
	if (dir == 'R')
		game->player->direction += 0.1;

	if (game->player->direction >= 2 * M_PI)
		game->player->direction -= 2 * M_PI;
	if (game->player->direction < 0)
		game->player->direction += 2 * M_PI;
}

void	ft_key_hook(void *param)
{
	t_game	*game;

	game = param;

	if (mlx_is_key_down(game->window->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->window->mlx);

	if (mlx_is_key_down(game->window->mlx, MLX_KEY_LEFT) == true)
		ft_rotate_player(game, 'L');
	if (mlx_is_key_down(game->window->mlx, MLX_KEY_RIGHT) == true)
		ft_rotate_player(game, 'R');

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
	t_game	*game;

	game = param;
	ft_draw_map_2D(game);
	ft_draw_player(game);
	ft_ray_caster(game);
	
	if (mlx_image_to_window(game->window->mlx, game->window->image, 0, 0) == -1)
		ft_exit(mlx_strerror(mlx_errno));
}
