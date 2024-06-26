/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_special.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:44:18 by mott              #+#    #+#             */
/*   Updated: 2024/06/26 17:31:46 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	door_open_close(t_game *game)
{
	int	x;
	int	y;

	x = (int)game->player->pos.x >> 5;
	y = (int)game->player->pos.y >> 5;
	if (game->ray->wall[WIDTH >> 1] == DOOR_EAST || game->ray->wall[WIDTH >> 1] == EAST)
		x++;
	else if (game->ray->wall[WIDTH >> 1] == DOOR_NORTH || game->ray->wall[WIDTH >> 1] == NORTH)
		y--;
	else if (game->ray->wall[WIDTH >> 1] == DOOR_WEST || game->ray->wall[WIDTH >> 1] == WEST)
		x--;
	else if (game->ray->wall[WIDTH >> 1] == DOOR_SOUTH || game->ray->wall[WIDTH >> 1] == SOUTH)
		y++;
	printf("x: %d y:%d map:%c\n", x, y, game->map->map[y][x]);
	if (game->map->map[y][x] == 'D')
		game->map->map[y][x] = 'd';
	else if (game->map->map[y][x] == 'd')
		game->map->map[y][x] = 'D';
	game->recalculate = true;
}

static void	minimap_on_off(t_game *game)
{
	game->minimap = !game->minimap;
	game->recalculate = true;
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
