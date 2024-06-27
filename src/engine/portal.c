/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:17:32 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/27 19:12:18 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	portal_tex(t_game *game)
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

void	portal_animation(t_game *game)
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

void	init_portal(t_game *game, char *line)
{
	static int	p = 0;
	int			i = 0;

	p++;
	if (p > 2)
		ft_error(game, "too many portals on the map");
	if (p == 1)
		game->map->p_one.y = game->map->max.y;
	if (p == 2)
		game->map->p_two.y = game->map->max.y;
	while (line[i] != '\0')
	{
		if (line[i] == 'P')
		{
			if (p == 1)
				game->map->p_one.x = i;
			if (p == 2)
				game->map->p_two.x = i;
		}
		i++;
	}
}
