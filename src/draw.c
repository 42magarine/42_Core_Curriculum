/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/06/16 15:13:16 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/draw.h"

// static void	ft_draw_wall(t_game *game, int x, int shortest_distance)
// {
// 	int	y;
// 	int	height = game->window->height;
// 	int	wall_height = game->map->field_size;
// 	int	new_height;
// 	int	distance = ft_math(game);

// 	new_height = (int)(wall_height / shortest_distance * distance);

// 	y = (height - wall_height) / 2;
// 	while (y < (height - wall_height) / 2 + wall_height)
// 	{
// 		mlx_put_pixel(game->window->image, x, y, 10);
// 		y++;
// 	}
// }

static int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_draw_background(t_game *game)
{
	ft_draw_square(game, 0, 0, game->window->width, game->window->height / 2, GOLD);
	ft_draw_square(game, 0, 256, game->window->width, game->window->height / 2, SILVER);
}

void	ft_draw_square(t_game *game, int map_x, int map_y, int size_x, int size_y, int color)
{
	int	x;
	int	y;
	int white = ft_get_rgba(255, 255, 255, 255);

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			if (x == 0 || y == 0 || x == size_x - 1 || y == size_y - 1)
				mlx_put_pixel(game->window->image, map_x + x, map_y + y, white);
			else
				mlx_put_pixel(game->window->image, map_x + x, map_y + y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_map_2D(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (g_map[y][x] == '1')
				// ft_draw_square(game, x * 64, y * 64, 64, ft_get_rgba(255, 0, 0, 255));
				ft_draw_square(game, x * 64, y * 64, 64, 64, SILVER);
			else
				ft_draw_square(game, x * 64, y * 64, 64, 64, GOLD);
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_game *game)
{
	ft_draw_square(game, game->player->x - 4, game->player->y - 4, 8, 8, ft_get_rgba(0, 0, 255, 255));
}

void	draw_line(t_game *game, t_point start, t_point stop)
{
	t_line	line;

	line.dx = abs(stop.x - start.x);
	line.dy = -abs(stop.y - start.y);
	line.sx = 1;
	line.sy = 1;
	if (start.x > stop.x)
		line.sx = -1;
	if (start.y > stop.y)
		line.sy = -1;
	line.err = line.dx + line.dy;
	while (start.x != stop.x && start.y != stop.y)
	{
		mlx_put_pixel(game->window->image, start.x, start.y, WHITE);
		line.e2 = 2 * line.err;
		if (line.e2 > line.dy)
		{
			line.err += line.dy;
			start.x += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			start.y += line.sy;
		}
	}
}
