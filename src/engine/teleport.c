/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:56:49 by mott              #+#    #+#             */
/*   Updated: 2024/06/27 20:53:22 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void destination(t_game *game, t_coords dest, double move_x, double move_y)
{
	if (move_x > 0 && game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x + move_x) >> 6] != '1'
		&& game->map->map[(int)game->player->pos.y >> 6]
		[(int)(game->player->pos.x + move_x) >> 6] != 'D')
	{
		game->player->pos.x = (int)(dest.x + 1) << 6;
		game->player->pos.y = ((int)dest.y << 6) + (SIZE >> 1);
	}
	else if (move_x < 0)
	{
		game->player->pos.x = (int)(dest.x) << 6;
		game->player->pos.y = ((int)dest.y << 6) + (SIZE >> 1);
		// game->player->dir = ONE_PI;
	}
	else if (move_y < 0)
	{
		game->player->pos.x = ((int)dest.x << 6) + (SIZE >> 1);
		game->player->pos.y = (int)(dest.y) << 6;
		// game->player->dir = HALF_PI;
	}
	else if (move_y > 0)
	{
		game->player->pos.x = ((int)dest.x << 6) + (SIZE >> 1);
		game->player->pos.y = (int)(dest.y + 1) << 6;
		// game->player->dir = THREE_HALF_PI;
	}
}

void	teleport_player(t_game *game, double move_x, double move_y)
{
	if ((int)(game->player->pos.x + move_x) >> 6 == game->map->p_one.x
		&& (int)(game->player->pos.y) >> 6 == game->map->p_one.y)

		destination(game, game->map->p_two, move_x, 0);

	else if ((int)(game->player->pos.x) >> 6 == game->map->p_one.x
		&& (int)(game->player->pos.y + move_y) >> 6 == game->map->p_one.y)

		destination(game, game->map->p_two, 0, move_y);

	else if ((int)(game->player->pos.x + move_x) >> 6 == game->map->p_two.x
		&& (int)(game->player->pos.y) >> 6 == game->map->p_two.y)

		destination(game, game->map->p_one, move_x, 0);

	else if ((int)(game->player->pos.x) >> 6 == game->map->p_two.x
		&& (int)(game->player->pos.y + move_y) >> 6 == game->map->p_two.y)

		destination(game, game->map->p_one, 0, move_y);

}
