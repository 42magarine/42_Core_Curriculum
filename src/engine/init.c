/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:31:03 by mott              #+#    #+#             */
/*   Updated: 2024/07/01 12:01:14 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_window(t_game *game)
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

// window->width		= 1920
// window->fov			= 60
// angle between rays	= 60/1920
static void	init_ray(t_game *game)
{
	game->ray->fov_start = FOV / 2 * ONE_PI / 180;
	game->ray->fov_add = FOV / WIDTH * ONE_PI / 180;
}

#ifdef BONUS

static void	init_door(t_game *game)
{
	game->tex->wall[4] = set_texture(game, "./textures/door.png");
	game->tex->wall[5] = game->tex->wall[4];
	game->tex->wall[6] = game->tex->wall[4];
	game->tex->wall[7] = game->tex->wall[4];
}

static void	init_minimap(t_game *game)
{
	if (game->map->max.x > game->map->max.y)
		game->minimap->factor = MM_WIDTH / game->map->max.x;
	else
		game->minimap->factor = MM_HEIGHT / game->map->max.y;
	game->minimap->start.x = WIDTH - game->minimap->factor * (game->map->max.x + 1);
	game->minimap->start.y = game->minimap->factor;
}

void	init_game(t_game *game)
{
	init_window(game);
	init_ray(game);
	init_door(game);
	// portal_tex(game);
	init_portal_tex(game);
	init_minimap(game);
	game->player->pos.x = game->player->pos.x * SIZE + (SIZE >> 1);
	game->player->pos.y = game->player->pos.y * SIZE + (SIZE >> 1);
}

#else

void	init_game(t_game *game)
{
	init_window(game);
	init_ray(game);
	game->player->pos.x = game->player->pos.x * SIZE + (SIZE >> 1);
	game->player->pos.y = game->player->pos.y * SIZE + (SIZE >> 1);
}

#endif
