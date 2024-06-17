/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:27:53 by mott              #+#    #+#             */
/*   Updated: 2024/06/17 15:17:10 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*g_map[] =
{ // 0123456789012345
	"1111111111111111", //0
	"1010000000100001", //1
	"1010000000100001", //2
	"1010000000100001", //3
	"10100N0000000001", //4
	"1000010000000101", //5
	"1000000000000001", //6
	"1111111111111111", //7
};

//   0° = east  = 0
//  90° = north = PI_HALF
// 180°	= west  = PI_ONE
// 270° = south = PI_THREE_HALF
void	init_var(t_game *game, t_window *window, t_map *map, t_player *player)
{
	game->player = player;
	game->window = window;
	game->map = map;
	window->width = 1024;
	window->height = 512;
	map->pos.x = 16;
	map->pos.y = 8;
	map->floor[0] = 34;
	map->floor[1] = 139;
	map->floor[2] = 34;
	map->ceiling[0] = 255;
	map->ceiling[1] = 215;
	map->ceiling[1] = 0;
	player->pos.x = 5 * FIELD_SIZE + FIELD_SIZE / 2;
	player->pos.y = 4 * FIELD_SIZE + FIELD_SIZE / 2;
	// player->dir = 0;
	player->dir = PI_HALF;
	// player->dir = PI_ONE;
	// player->dir = PI_THREE_HALF;
}

void	init_mlx(t_window *window)
{
	window->mlx = mlx_init(window->width, window->height, "cub3D", false);
	if (window->mlx == NULL)
		ft_exit(mlx_strerror(mlx_errno));
	window->image = mlx_new_image(window->mlx, window->width, window->height);
	if (window->image == NULL)
		ft_exit(mlx_strerror(mlx_errno));
}
