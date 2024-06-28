/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:56:49 by mott              #+#    #+#             */
/*   Updated: 2024/06/28 12:54:38 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	teleport_x(t_game *game, t_coords dest, double x, double y)
{
	if (x >= 0
		&& game->map->map[(int)dest.y][(int)(dest.x + 1)] != '1'
		&& game->map->map[(int)dest.y][(int)(dest.x + 1)] != 'D')
	{
		game->player->pos.x = (int)(dest.x + 1) << 6;
		game->player->pos.y = ((int)dest.y << 6) + (SIZE >> 1);
	}
	else if (x < 0
		&& game->map->map[(int)dest.y][(int)(dest.x - 1)] != '1'
		&& game->map->map[(int)dest.y][(int)(dest.x - 1)] != 'D')
	{
		game->player->pos.x = (int)(dest.x) << 6;
		game->player->pos.y = ((int)dest.y << 6) + (SIZE >> 1);
	}
	else
		teleport_y(game, dest, x, y);
}

void	teleport_y(t_game *game, t_coords dest, double x, double y)
{
	if (y >= 0
		&& game->map->map[(int)(dest.y + 1)][(int)dest.x] != '1'
		&& game->map->map[(int)(dest.y + 1)][(int)dest.x] != 'D')
	{
		game->player->pos.x = ((int)dest.x << 6) + (SIZE >> 1);
		game->player->pos.y = (int)(dest.y + 1) << 6;
	}
	else if (y < 0
		&& game->map->map[(int)(dest.y - 1)][(int)dest.x] != '1'
		&& game->map->map[(int)(dest.y - 1)][(int)dest.x] != 'D')
	{
		game->player->pos.x = ((int)dest.x << 6) + (SIZE >> 1);
		game->player->pos.y = (int)(dest.y) << 6;
	}
	else
		teleport_x(game, dest, x, y);
}

void	teleport_player(t_game *game, double x, double y)
{
	if ((int)(game->player->pos.x + x) >> 6 == game->map->p_one.x
		&& (int)(game->player->pos.y) >> 6 == game->map->p_one.y)
		teleport_x(game, game->map->p_two, x, y);
	else if ((int)(game->player->pos.x + x) >> 6 == game->map->p_two.x
		&& (int)(game->player->pos.y) >> 6 == game->map->p_two.y)
		teleport_x(game, game->map->p_one, x, y);
	else if ((int)(game->player->pos.x) >> 6 == game->map->p_one.x
		&& (int)(game->player->pos.y + y) >> 6 == game->map->p_one.y)
		teleport_y(game, game->map->p_two, x, y);
	else if ((int)(game->player->pos.x) >> 6 == game->map->p_two.x
		&& (int)(game->player->pos.y + y) >> 6 == game->map->p_two.y)
		teleport_y(game, game->map->p_one, x, y);
}
