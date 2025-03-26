/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:31:03 by mott              #+#    #+#             */
/*   Updated: 2024/07/01 13:34:14 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_window(t_game *game)
{
	game->window->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (game->window->mlx == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	game->window->image = mlx_new_image(game->window->mlx, WIDTH, HEIGHT);
	if (game->window->image == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(game->window->mlx, game->window->image, 0, 0) == -1)
		ft_error(game, mlx_strerror(mlx_errno));
}

void	init_player(t_map *map, t_player *player)
{
	if (map->map[(int)player->pos.y][(int)player->pos.x] == 'E')
		player->dir = 0;
	else if (map->map[(int)player->pos.y][(int)player->pos.x] == 'N')
		player->dir = HALF_PI;
	else if (map->map[(int)player->pos.y][(int)player->pos.x] == 'W')
		player->dir = ONE_PI;
	else if (map->map[(int)player->pos.y][(int)player->pos.x] == 'S')
		player->dir = THREE_HALF_PI;
	player->pos.x = player->pos.x * SIZE + (SIZE >> 1);
	player->pos.y = player->pos.y * SIZE + (SIZE >> 1);
}

void	init_door_tex(t_game *game)
{
	game->tex->wall[4] = mlx_load_png("./textures/door.png");
	if (game->tex->wall[4] == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	game->tex->wall[5] = game->tex->wall[4];
	game->tex->wall[6] = game->tex->wall[4];
	game->tex->wall[7] = game->tex->wall[4];
}

void	init_ray(t_ray *ray)
{
	ray->fov_start = FOV / 2 * ONE_PI / 180;
	ray->fov_add = FOV / WIDTH * ONE_PI / 180;
}

void	init_minimap(t_map *map, t_minimap *minimap)
{
	if (map->max.x > map->max.y)
		minimap->factor = MM_SIZE / map->max.x;
	else
		minimap->factor = MM_SIZE / map->max.y;
	minimap->start.x = WIDTH - minimap->factor * (map->max.x + 1);
	minimap->start.y = minimap->factor;
}
