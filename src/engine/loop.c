/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:03:44 by mott              #+#    #+#             */
/*   Updated: 2024/06/27 19:16:13 by fwahl            ###   ########.fr       */
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
		draN_WALL(game, radian, x);
		radian = pi_overflow(radian - game->ray->fov_add);
		x++;
	}
}

void	loop_hook(void *param)
{
	t_game	*game;

	game = param;
	draw_background(game);
	ray_caster(game);
	portal_animation(game);
	if (game->minimap->show == true)
		draw_minimap(game);
	key_hook(game);
	mouse_hook(game);
}
