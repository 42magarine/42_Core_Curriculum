/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:17:32 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/29 15:06:23 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	portal_tex_east_north(t_game *game)
{
	game->map->portal[0] = set_texture(game, "./textures/e_portal1.png");
	game->map->portal[1] = set_texture(game, "./textures/e_portal2.png");
	game->map->portal[2] = set_texture(game, "./textures/e_portal3.png");
	game->map->portal[3] = set_texture(game, "./textures/e_portal4.png");
	game->map->portal[4] = set_texture(game, "./textures/e_portal5.png");
	game->map->portal[5] = set_texture(game, "./textures/e_portal6.png");
	game->map->portal[6] = set_texture(game, "./textures/e_portal7.png");
	game->map->portal[7] = set_texture(game, "./textures/e_portal9.png");
	game->map->portal[8] = set_texture(game, "./textures/e_portal9.png");
	game->map->portal[9] = set_texture(game, "./textures/e_portal10.png");
	game->map->portal[10] = set_texture(game, "./textures/n_portal1.png");
	game->map->portal[11] = set_texture(game, "./textures/n_portal2.png");
	game->map->portal[12] = set_texture(game, "./textures/n_portal3.png");
	game->map->portal[13] = set_texture(game, "./textures/n_portal4.png");
	game->map->portal[14] = set_texture(game, "./textures/n_portal5.png");
	game->map->portal[15] = set_texture(game, "./textures/n_portal6.png");
	game->map->portal[16] = set_texture(game, "./textures/n_portal7.png");
	game->map->portal[17] = set_texture(game, "./textures/n_portal9.png");
	game->map->portal[18] = set_texture(game, "./textures/n_portal9.png");
	game->map->portal[19] = set_texture(game, "./textures/n_portal10.png");
}

static void	portal_tex_west_south(t_game *game)
{
	game->map->portal[20] = set_texture(game, "./textures/w_portal1.png");
	game->map->portal[21] = set_texture(game, "./textures/w_portal2.png");
	game->map->portal[22] = set_texture(game, "./textures/w_portal3.png");
	game->map->portal[23] = set_texture(game, "./textures/w_portal4.png");
	game->map->portal[24] = set_texture(game, "./textures/w_portal5.png");
	game->map->portal[25] = set_texture(game, "./textures/w_portal6.png");
	game->map->portal[26] = set_texture(game, "./textures/w_portal7.png");
	game->map->portal[27] = set_texture(game, "./textures/w_portal9.png");
	game->map->portal[28] = set_texture(game, "./textures/w_portal9.png");
	game->map->portal[29] = set_texture(game, "./textures/w_portal10.png");
	game->map->portal[30] = set_texture(game, "./textures/s_portal1.png");
	game->map->portal[31] = set_texture(game, "./textures/s_portal2.png");
	game->map->portal[32] = set_texture(game, "./textures/s_portal3.png");
	game->map->portal[33] = set_texture(game, "./textures/s_portal4.png");
	game->map->portal[34] = set_texture(game, "./textures/s_portal5.png");
	game->map->portal[35] = set_texture(game, "./textures/s_portal6.png");
	game->map->portal[36] = set_texture(game, "./textures/s_portal7.png");
	game->map->portal[37] = set_texture(game, "./textures/s_portal9.png");
	game->map->portal[38] = set_texture(game, "./textures/s_portal9.png");
	game->map->portal[39] = set_texture(game, "./textures/s_portal10.png");
}

void	portal_tex(t_game *game)
{
	portal_tex_east_north(game);
	portal_tex_west_south(game);
	game->map->wall[8] = game->map->portal[0];
	game->map->wall[9] = game->map->portal[10];
	game->map->wall[10] = game->map->portal[20];
	game->map->wall[11] = game->map->portal[30];
}

void	portal_animation(t_game *game)
{
	static int	count;

	if (count % 4 == 0)
	{
		game->map->wall[8] = game->map->portal[count / 4];
		game->map->wall[9] = game->map->portal[count / 4 + 10];
		game->map->wall[10] = game->map->portal[count / 4 + 20];
		game->map->wall[11] = game->map->portal[count / 4 + 30];
		if (count == 36)
			count = 0;
	}
	count++;
}

void	init_portal(t_game *game, char *line)
{
	static int	p;
	int			i;

	if (p == 1)
		game->map->p_one.y = game->map->max.y;
	if (p == 2)
		game->map->p_two.y = game->map->max.y;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'P')
		{
			p++;
			if (p == 1)
				game->map->p_one.x = i;
			if (p == 2)
				game->map->p_two.x = i;
			if (p > 2)
				ft_error(game, "too many portals on the map\n");
		}
		i++;
	}
}
