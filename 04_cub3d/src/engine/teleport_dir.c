/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:56:49 by mott              #+#    #+#             */
/*   Updated: 2024/06/29 16:10:21 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	teleport_east(t_game *game, t_coords dest)
{
	if (game->map->map[(int)dest.y][(int)(dest.x + 1)] != '1'
		&& game->map->map[(int)dest.y][(int)(dest.x + 1)] != 'D'
		&& game->map->map[(int)dest.y][(int)(dest.x + 1)] != 'P')
	{
		game->player->pos.x = (int)(dest.x + 1) << 6;
		game->player->pos.y = ((int)dest.y << 6) + (SIZE >> 1);
		game->player->dir = 0;
		return (true);
	}
	return (false);
}

bool	teleport_west(t_game *game, t_coords dest)
{
	if (game->map->map[(int)dest.y][(int)(dest.x - 1)] != '1'
		&& game->map->map[(int)dest.y][(int)(dest.x - 1)] != 'D'
		&& game->map->map[(int)dest.y][(int)(dest.x - 1)] != 'P')
	{
		game->player->pos.x = ((int)dest.x << 6) - 1;
		game->player->pos.y = ((int)dest.y << 6) + (SIZE >> 1);
		game->player->dir = ONE_PI;
		return (true);
	}
	return (false);
}

bool	teleport_north(t_game *game, t_coords dest)
{
	if (game->map->map[(int)(dest.y - 1)][(int)dest.x] != '1'
		&& game->map->map[(int)(dest.y - 1)][(int)dest.x] != 'D'
		&& game->map->map[(int)(dest.y - 1)][(int)dest.x] != 'P')
	{
		game->player->pos.x = ((int)dest.x << 6) + (SIZE >> 1);
		game->player->pos.y = ((int)dest.y << 6) - 1;
		game->player->dir = HALF_PI;
		return (true);
	}
	return (false);
}

bool	teleport_south(t_game *game, t_coords dest)
{
	if (game->map->map[(int)(dest.y + 1)][(int)dest.x] != '1'
		&& game->map->map[(int)(dest.y + 1)][(int)dest.x] != 'D'
		&& game->map->map[(int)(dest.y + 1)][(int)dest.x] != 'P')
	{
		game->player->pos.x = ((int)dest.x << 6) + (SIZE >> 1);
		game->player->pos.y = (int)(dest.y + 1) << 6;
		game->player->dir = THREE_HALF_PI;
		return (true);
	}
	return (false);
}
