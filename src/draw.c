/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/06/16 19:14:52 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	draw_square(t_window *window, t_point pos, t_point size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (x == 0 || y == 0 || x == size.x - 1 || y == size.y - 1)
				mlx_put_pixel(window->image, pos.x + x, pos.y + y, WHITE);
			else
				mlx_put_pixel(window->image, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}

// static void	draw_line(t_game *game, t_point start, t_point stop)
// {
// 	t_line	line;

// 	line.dx = abs(stop.x - start.x);
// 	line.dy = -abs(stop.y - start.y);
// 	line.sx = 1;
// 	line.sy = 1;
// 	if (start.x > stop.x)
// 		line.sx = -1;
// 	if (start.y > stop.y)
// 		line.sy = -1;
// 	line.err = line.dx + line.dy;
// 	while (start.x != stop.x && start.y != stop.y)
// 	{
// 		mlx_put_pixel(game->window->image, start.x, start.y, WHITE);
// 		line.e2 = 2 * line.err;
// 		if (line.e2 > line.dy)
// 		{
// 			line.err += line.dy;
// 			start.x += line.sx;
// 		}
// 		if (line.e2 < line.dx)
// 		{
// 			line.err += line.dx;
// 			start.y += line.sy;
// 		}
// 	}
// }

void	draw_background(t_window *window, t_map *map)
{
	int	floor;
	int	ceiling;

	floor = get_rgba(map->floor[0], map->floor[1], map->floor[2], 255);
	ceiling = get_rgba(map->ceiling[0], map->ceiling[1], map->ceiling[2], 255);

	draw_square(window, (t_point){0, 0},
		(t_point){window->width, window->height / 2}, floor);
	draw_square(window, (t_point){0, window->height / 2},
		(t_point){window->width, window->height / 2}, ceiling);
}

void	draw_minimap(t_window *window, t_map *map, t_point player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->pos.y)
	{
		x = 0;
		while (x < map->pos.x)
		{
			if (g_map[y][x] == '1')
				draw_square(window, (t_point){x * FIELD_SIZE, y * FIELD_SIZE},
					(t_point){FIELD_SIZE, FIELD_SIZE}, TEAL);
			else
				draw_square(window, (t_point){x * FIELD_SIZE, y * FIELD_SIZE},
					(t_point){FIELD_SIZE, FIELD_SIZE}, MAROON);
			x++;
		}
		y++;
	}
	draw_square(window, player, (t_point){PLAYER_SIZE, PLAYER_SIZE}, NAVY);
}

void	draw_game(t_window *window)
{
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		ft_exit(mlx_strerror(mlx_errno));
}
