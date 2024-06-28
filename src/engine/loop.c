/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:03:44 by mott              #+#    #+#             */
/*   Updated: 2024/06/28 13:52:14 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	int		i;

	game = param;
	draw_background(game);
	ray_caster(game);
	portal_animation(game);
	if (game->minimap->show == true)
	{
		draw_minimap(game);
		draw_player(game);
		i = 0;
		while (i < WIDTH)
		{
			draw_ray(game, game->minimap->player, game->ray->hit[i]);
			i += 1;
		}
	}
	key_hook(game);
	mouse_hook(game);
}
