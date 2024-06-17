/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:08:58 by mott              #+#    #+#             */
/*   Updated: 2024/06/17 19:36:36 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	move_player(t_map *map, t_player *player, int x, int y)
{
	(void)map;
	if (map->map[(player->pos.y + y) / FIELD_SIZE]
		[(player->pos.x + x) / FIELD_SIZE] == '1')
		return ;
	player->pos.x += x;
	player->pos.y += y;
}

static void	rotate_player(t_player *player, char dir)
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

static void	key_hook(t_window *window, t_map *map, t_player *player)
{
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(window->mlx);
	if (mlx_is_key_down(window->mlx, MLX_KEY_LEFT) == true)
		rotate_player(player, 'L');
	if (mlx_is_key_down(window->mlx, MLX_KEY_RIGHT) == true)
		rotate_player(player, 'R');
	if (mlx_is_key_down(window->mlx, MLX_KEY_W) == true)
		move_player(map, player, 0, -PLAYER_SIZE);
	if (mlx_is_key_down(window->mlx, MLX_KEY_A) == true)
		move_player(map, player, -PLAYER_SIZE, 0);
	if (mlx_is_key_down(window->mlx, MLX_KEY_S) == true)
		move_player(map, player, 0, PLAYER_SIZE);
	if (mlx_is_key_down(window->mlx, MLX_KEY_D) == true)
		move_player(map, player, PLAYER_SIZE, 0);
}

void	loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	key_hook(game->window, game->map, game->player);
	draw_background(game->window, game->map);
	draw_minimap(game->window, game->map, game->player->pos);
	ray_caster(game->window, game->map, game->player);
	draw_game(game->window);
}
