/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/06/23 20:07:31 by mott             ###   ########.fr       */
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

static void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == '1')
				draw_square(game, (t_coords){x << 6, y << 6}, F_SIZE, GRAY);
			else
				draw_square(game, (t_coords){x << 6, y << 6}, F_SIZE, SILVER);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *game)
{
	t_coords	player;

	player.x = game->player->pos.x - (P_SIZE >> 1);
	player.y = game->player->pos.y - (P_SIZE >> 1);
	draw_square(game, player, P_SIZE, YELLOW);
}

static void	draw_ray(t_game *game, t_coords player, t_coords wall)
{
	double	dx;
	double	dy;
	int		i;

	dx = wall.x - game->player->pos.x;
	dy = wall.y - game->player->pos.y;
	if (fabs(dx) > fabs(dy))
		i = fabs(dx);
	else
		i = fabs(dy);
	dx /= i;
	dy /= i;
	while (i > 0)
	{
		mlx_put_pixel(game->window->image, (int)player.x, (int)player.y, BLACK);
		player.x += dx;
		player.y += dy;
		i--;
	}
}

void	draw_minimap(t_game *game)
{
	int	i;

	draw_map(game);
	draw_player(game);
	i = 0;
	while (i < WIDTH)
	{
		draw_ray(game, game->player->pos, game->ray->hit[i]);
		i += 1;
	}
}
