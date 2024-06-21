/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:28:04 by mott              #+#    #+#             */
/*   Updated: 2024/06/21 17:56:10 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// y_step < 0 = texture_height < wall_height = scaling up
// y_step > 0 = texture_height > wall_height = scaling down
void	draw_wall(t_game *game, int x, int ray, double radian)
{
	int	line;
	int	line_offset;
	int	color;
	int	y;
	int	index;

	line = F_SIZE * HEIGHT / ray;
	if (line > HEIGHT)
		line = HEIGHT;
	line_offset = (HEIGHT - line) / 2;

	double y_step = (double)game->map->walls[NORTH]->height / line;
	// double x_ratio = (double)x / WIDTH;
	// double hit_x = game->map->wall[x].x % F_SIZE;
	double hit_x = game->map->wall[x].x - (int)game->map->wall[x].x;

	y = 0;
	while (y < line)
	{
		int tex_y = (int)(y * y_step) % game->map->walls[NORTH]->height;
		// int tex_y = (int)(y * y_step);
		// double tex_y = (double) y / line * game->map->walls[NORTH]->height;

		// int tex_x = (int)(x_ratio * game->map->walls[NORTH]->width) % game->map->walls[NORTH]->width;
		int tex_x = (int)hit_x * game->map->walls[NORTH]->width;

		index = (game->map->walls[NORTH]->width * tex_y + tex_x) * 4;
		// index = (game->map->walls[NORTH]->width * (int)tex_y + tex_x) * 4;

		if (game->map->wall_dir[x] == NORTH)
		{
			if (radian >=0 && radian <= ONE_PI)
				color = get_rgba(game->map->walls[NORTH]->pixels[index + 0],
								game->map->walls[NORTH]->pixels[index + 1],
								game->map->walls[NORTH]->pixels[index + 2],
								game->map->walls[NORTH]->pixels[index + 3]);
				// color = RED;
			else
				color = get_rgba(game->map->walls[SOUTH]->pixels[index + 0],
								game->map->walls[SOUTH]->pixels[index + 1],
								game->map->walls[SOUTH]->pixels[index + 2],
								game->map->walls[SOUTH]->pixels[index + 3]);
				// color = BLUE;
		}
		else
		{
			if (radian >= HALF_PI && radian <= THREE_HALF_PI)
				color = get_rgba(game->map->walls[WEST]->pixels[index + 0],
								game->map->walls[WEST]->pixels[index + 1],
								game->map->walls[WEST]->pixels[index + 2],
								game->map->walls[WEST]->pixels[index + 3]);
				// color = YELLOW;
			else
				color = get_rgba(game->map->walls[EAST]->pixels[index + 0],
								game->map->walls[EAST]->pixels[index + 1],
								game->map->walls[EAST]->pixels[index + 2],
								game->map->walls[EAST]->pixels[index + 3]);
				// color = GREEN;
		}
		mlx_put_pixel(game->window->image, x, y + line_offset, color);
		y++;
	}
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT >> 1)
				mlx_put_pixel(game->window->image, x, y, game->map->ceiling);
			else
				mlx_put_pixel(game->window->image, x, y, game->map->floor);
			x++;
		}
		y++;
	}
}
