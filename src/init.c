/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:27:53 by mott              #+#    #+#             */
/*   Updated: 2024/06/16 15:41:58 by mott             ###   ########.fr       */
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

void	init_var(t_game *game, t_player *player, t_window *window, t_point *map)
{
	game->player = player;
	game->window = window;
	game->point = map;

	player->pos->x = 5 * FIELD_SIZE + FIELD_SIZE / 2;
	player->pos->y = 4 * FIELD_SIZE + FIELD_SIZE / 2;
	player->fov = 60;
	player->dir = 0;				// 0°	east
	player->dir = M_PI / 2;			// 90°	north
	player->dir = M_PI;				// 180°	west
	player->dir = 3 * M_PI / 2;		// 270°	south

	window->width = 1024;
	window->height = 512;

	map->x = 16;
	map->y = 8;
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
