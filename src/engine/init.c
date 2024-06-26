/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:31:03 by mott              #+#    #+#             */
/*   Updated: 2024/06/26 20:56:50 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// window->width		= 1920
// window->fov			= 60
// angle between rays	= 60/1920

static void	init_door(t_game *game)
{
	game->map->wall[4] = set_texture(game, "./textures/door_closed.png");
	game->map->wall[5] = game->map->wall[4];
	game->map->wall[6] = game->map->wall[4];
	game->map->wall[7] = game->map->wall[4];
}

void	init_game(t_game *game)
{
	t_window	*window;
	t_ray		*ray;

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
	game->recalculate = true;
	game->player->pos.x = game->player->pos.x * F_SIZE + F_SIZE / 2;
	game->player->pos.y = game->player->pos.y * F_SIZE + F_SIZE / 2;
	ray = ft_calloc(1, sizeof(t_ray));
	game->ray = ray;
	ray->fov_start = FOV / 2 * ONE_PI / 180;
	ray->fov_add = FOV / WIDTH * ONE_PI / 180;
	init_door(game);
	init_orb(game);
}

static void	ray_caster(t_game *game)
{
	double		radian;
	int			x;

	radian = pi_overflow(game->player->dir + game->ray->fov_start);
	x = 0;
	while (x < WIDTH)
	{
		ray_calculation(game, radian, x);
		draw_wall(game, radian, x);
		radian = pi_overflow(radian - game->ray->fov_add);
		x++;
	}
	swap_orb_tex(game);

}

void	loop_hook(void *param)
{
	t_game	*game;

	game = param;
	// if (game->recalculate == true)
	// {
		draw_background(game);
		ray_caster(game);
		if (game->minimap == true)
			draw_minimap(game);
		game->recalculate = false;
	// }
	key_hook(game);
	mouse_hook(game);
}
