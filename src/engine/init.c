/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:31:03 by mott              #+#    #+#             */
/*   Updated: 2024/06/25 13:52:22 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	pi_overflow(double radian)
{
	if (radian < 0)
		radian += TWO_PI;
	else if (radian >= TWO_PI)
		radian -= TWO_PI;
	return (radian);
}

// window->width		= 1920
// window->fov			= 60
// angle between rays	= 60/1920
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
}

static void	ray_caster(t_game *game)
{
	double	radian;
	int		x;

	radian = pi_overflow(game->player->dir + game->ray->fov_start);
	x = 0;
	while (x < WIDTH)
	{
		ray_calculation(game, radian, x);
		draw_wall(game, radian, x);
		radian = pi_overflow(radian - game->ray->fov_add);
		x++;
	}
}

void	loop_hook(void *param)
{
	t_game	*game;

	game = param;
	if (game->recalculate == true)
	{
		draw_background(game);
		ray_caster(game);
		if (game->minimap == true)
			draw_minimap(game);
		game->recalculate = false;
	}
	// key_hook(game);
	// mouse_hook(game);
}
