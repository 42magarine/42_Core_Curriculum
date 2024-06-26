/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:31:03 by mott              #+#    #+#             */
/*   Updated: 2024/06/26 18:10:21 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_door(t_game *game)
{
	game->map->wall[4] = set_texture(game, "./textures/door.png");
	game->map->wall[5] = game->map->wall[4];
	game->map->wall[6] = game->map->wall[4];
	game->map->wall[7] = game->map->wall[4];
}

// window->width		= 1920
// window->fov			= 60
// angle between rays	= 60/1920
static void	init_ray(t_game *game)
{
	t_ray		*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	game->ray = ray;
	ray->fov_start = FOV / 2 * ONE_PI / 180;
	ray->fov_add = FOV / WIDTH * ONE_PI / 180;
}

static void	init_window(t_game *game)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	game->window = window;
	window->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (window->mlx == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	window->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (window->image == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		ft_error(game, mlx_strerror(mlx_errno));
}

void	init_game(t_game *game)
{
	init_window(game);
	init_ray(game);
	init_door(game);
	game->recalculate = true;
	game->player->pos.x = game->player->pos.x * F_SIZE + F_SIZE / 2;
	game->player->pos.y = game->player->pos.y * F_SIZE + F_SIZE / 2;
}
