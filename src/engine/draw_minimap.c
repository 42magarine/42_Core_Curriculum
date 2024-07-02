/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/07/02 15:21:46 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	draw_square(t_game *game, t_coords pos, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_pixel(game->window->image, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_element(t_game *game, int x, int y)
{
	t_coords	pos;

	pos.x = game->minimap->start.x + (int)game->minimap->factor * x;
	pos.y = game->minimap->start.y + (int)game->minimap->factor * y;
	if (game->map->map[y][x] == '0' || is_player_char(game->map->map[y][x]))
		draw_square(game, pos, (int)game->minimap->factor, MM_WHITE);
	else if (game->map->map[y][x] == '1')
		draw_square(game, pos, (int)game->minimap->factor, MM_BLUE);
	else if (game->map->map[y][x] == 'D')
		draw_square(game, pos, (int)game->minimap->factor, MM_RED);
	else if (game->map->map[y][x] == 'd')
		draw_square(game, pos, (int)game->minimap->factor, MM_ROSE);
	else if (game->map->map[y][x] == 'P')
		draw_square(game, pos, (int)game->minimap->factor, MM_ORANGE);
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			draw_element(game, x, y);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	game->minimap->player.x = game->minimap->start.x
		+ game->player->pos.x / SIZE * game->minimap->factor;
	game->minimap->player.y = game->minimap->start.y
		+ game->player->pos.y / SIZE * game->minimap->factor;
	draw_square(game, (t_coords){game->minimap->player.x - 1,
		game->minimap->player.y - 1}, 3, MM_GOLD);
}

void	draw_ray(t_game *game, t_coords player, t_coords wall)
{
	double	dx;
	double	dy;
	int		i;

	dx = (wall.x - game->player->pos.x) / SIZE * game->minimap->factor;
	dy = (wall.y - game->player->pos.y) / SIZE * game->minimap->factor;
	if (fabs(dx) > fabs(dy))
		i = fabs(dx);
	else
		i = fabs(dy);
	dx /= i;
	dy /= i;
	while (i > 0)
	{
		mlx_put_pixel(game->window->image, player.x, player.y, MM_GRAY);
		player.x += dx;
		player.y += dy;
		i--;
	}
}
