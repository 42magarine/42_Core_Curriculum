/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:43:28 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/26 20:56:59 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_orb(t_game *game)
{
	game->map->orb[0] = set_texture(game, "./textures/orb1.png");
	game->map->orb[1] = set_texture(game, "./textures/orb2.png");
	game->map->orb[2] = set_texture(game, "./textures/orb3.png");
	game->map->orb[3] = set_texture(game, "./textures/orb4.png");
	game->map->orb[4] = set_texture(game, "./textures/orb5.png");
	game->map->orb[5] = set_texture(game, "./textures/orb6.png");
	game->map->orb[6] = set_texture(game, "./textures/orb7.png");
	game->map->orb[7] = set_texture(game, "./textures/orb8.png");
	game->map->orb[8] = set_texture(game, "./textures/orb9.png");
	game->map->orb[9] = set_texture(game, "./textures/orb10.png");
	game->map->wall[8] = game->map->orb[0];
	game->map->wall[9] = game->map->orb[0];
	game->map->wall[10] = game->map->orb[0];
	game->map->wall[11] = game->map->orb[0];
}

void swap_orb_tex(t_game *game)
{
	static int	count = 0;

	if (count % 5 == 0)
	{
		game->map->wall[8] = game->map->orb[count / 5];
		game->map->wall[9] = game->map->orb[count / 5];
		game->map->wall[10] = game->map->orb[count / 5];
		game->map->wall[11] = game->map->orb[count / 5];
		if (count == 45)
			count = 0;
	}
	count++;
}
