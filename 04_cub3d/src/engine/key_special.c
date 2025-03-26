/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_special.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:44:18 by mott              #+#    #+#             */
/*   Updated: 2024/06/28 13:39:07 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	door_open_close(t_game *game)
{
	int	x;
	int	y;

	x = (int)game->player->pos.x >> 6;
	y = (int)game->player->pos.y >> 6;
	if (game->ray->wall[WIDTH >> 1] == E_WALL
		|| game->ray->wall[WIDTH >> 1] == E_DOOR
		|| game->ray->wall[WIDTH >> 1] == E_PORTAL)
		x++;
	else if (game->ray->wall[WIDTH >> 1] == N_WALL
		|| game->ray->wall[WIDTH >> 1] == N_DOOR
		|| game->ray->wall[WIDTH >> 1] == N_PORTAL)
		y--;
	else if (game->ray->wall[WIDTH >> 1] == W_WALL
		|| game->ray->wall[WIDTH >> 1] == W_DOOR
		|| game->ray->wall[WIDTH >> 1] == W_PORTAL)
		x--;
	else if (game->ray->wall[WIDTH >> 1] == S_WALL
		|| game->ray->wall[WIDTH >> 1] == S_DOOR
		|| game->ray->wall[WIDTH >> 1] == S_PORTAL)
		y++;
	if (game->map->map[y][x] == 'D')
		game->map->map[y][x] = 'd';
	else if (game->map->map[y][x] == 'd')
		game->map->map[y][x] = 'D';
}

static void	minimap_on_off(t_game *game)
{
	game->minimap->show = !game->minimap->show;
}

void	special_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->window->mlx);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		minimap_on_off(game);
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		door_open_close(game);
}
