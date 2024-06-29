/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:17:30 by mott              #+#    #+#             */
/*   Updated: 2024/06/29 14:36:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	teleport_order_x(t_game *game, t_coords dest, double x)
{
	if (x < 0)
	{
		if (teleport_west(game, dest))
			return ;
		if (teleport_east(game, dest))
			return ;
		if (teleport_north(game, dest))
			return ;
		if (teleport_south(game, dest))
			return ;
	}
	else if (x >= 0)
	{
		if (teleport_east(game, dest))
			return ;
		if (teleport_west(game, dest))
			return ;
		if (teleport_north(game, dest))
			return ;
		if (teleport_south(game, dest))
			return ;
	}
}

static void	teleport_order_y(t_game *game, t_coords dest, double y)
{
	if (y < 0)
	{
		if (teleport_north(game, dest))
			return ;
		if (teleport_south(game, dest))
			return ;
		if (teleport_west(game, dest))
			return ;
		if (teleport_east(game, dest))
			return ;
	}
	else if (y >= 0)
	{
		if (teleport_south(game, dest))
			return ;
		if (teleport_north(game, dest))
			return ;
		if (teleport_west(game, dest))
			return ;
		if (teleport_east(game, dest))
			return ;
	}
}

void	teleport_check(t_game *game, double x, double y)
{
	if ((int)(game->player->pos.x + x) >> 6 == game->map->p_one.x
		&& (int)(game->player->pos.y) >> 6 == game->map->p_one.y)
		teleport_order_x(game, game->map->p_two, x);
	else if ((int)(game->player->pos.x + x) >> 6 == game->map->p_two.x
		&& (int)(game->player->pos.y) >> 6 == game->map->p_two.y)
		teleport_order_x(game, game->map->p_one, x);
	else if ((int)(game->player->pos.x) >> 6 == game->map->p_one.x
		&& (int)(game->player->pos.y + y) >> 6 == game->map->p_one.y)
		teleport_order_y(game, game->map->p_two, y);
	else if ((int)(game->player->pos.x) >> 6 == game->map->p_two.x
		&& (int)(game->player->pos.y + y) >> 6 == game->map->p_two.y)
		teleport_order_y(game, game->map->p_one, y);
}
