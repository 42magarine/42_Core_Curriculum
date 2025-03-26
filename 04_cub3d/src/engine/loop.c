/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:03:44 by mott              #+#    #+#             */
/*   Updated: 2024/07/02 16:47:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	swap_portal_animation(t_texture *tex)
{
	static int	count;

	if (count % 4 == 0)
	{
		tex->wall[8] = tex->portal[count >> 2];
		tex->wall[9] = tex->portal[(count >> 2) + 10];
		tex->wall[10] = tex->portal[(count >> 2) + 20];
		tex->wall[11] = tex->portal[(count >> 2) + 30];
		if (count == 36)
			count = 0;
	}
	count++;
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
	int		i;

	game = param;
	draw_background(game);
	ray_caster(game);
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
	swap_portal_animation(game->tex);
	key_hook(game);
	mouse_hook(game);
}
