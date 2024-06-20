/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/06/19 18:32:01 by fwahl            ###   ########.fr       */
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

static void	draw_square(t_window *window, t_coords pos, t_coords size, int color)
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

void	draw_line(t_window *window, t_coords start, t_coords stop)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		i;

	dx = stop.x - start.x;
	dy = stop.y - start.y;
	if (fabs(dx) > fabs(dy))
		i = fabs(dx);
	else
		i = fabs(dy);
	dx /= i;
	dy /= i;
	x = (double)start.x;
	y = (double)start.y;
	while (i >= 0)
	{
		mlx_put_pixel(window->image, round(x), round(y), BLACK);
		x += dx;
		y += dy;
		i--;
	}
}

void	draw_background(t_window *window, t_map *map)
{
	draw_square(window, (t_coords){0, 0},
		(t_coords){window->width, window->height / 2}, map->ceiling);
	draw_square(window, (t_coords){0, window->height / 2},
		(t_coords){window->width, window->height / 2}, map->floor);
}

void	draw_minimap(t_window *window, t_map *map, t_coords player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max.y && map->map[y] != NULL)
	{
		x = 0;
		while (x < map->max.x && map->map[y][x] != '\0')
		{
			if (map->map[y][x] == '1')
			{
				draw_square(window, (t_coords){x * FIELD_SIZE, y * FIELD_SIZE},
					(t_coords){FIELD_SIZE, FIELD_SIZE}, GRAY);
			}
			else
			{
				draw_square(window, (t_coords){x * FIELD_SIZE, y * FIELD_SIZE},
					(t_coords){FIELD_SIZE, FIELD_SIZE}, WHITE_SMOKE);
			}
			x++;
		}
		y++;
	}
	draw_square(window, player, (t_coords){PLAYER_SIZE, PLAYER_SIZE}, NAVY);
}

void	draw_game(t_window *window)
{
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		ft_exit(mlx_strerror(mlx_errno));
}
