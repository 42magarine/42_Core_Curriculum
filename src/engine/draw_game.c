/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:28:04 by mott              #+#    #+#             */
/*   Updated: 2024/06/21 20:21:19 by mott             ###   ########.fr       */
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
	double	hit_x;

	line = F_SIZE * HEIGHT / ray;
	if (line > HEIGHT)
		line = HEIGHT;
	line_offset = (HEIGHT - line) / 2;

	int tex_width = game->map->walls[NORTH]->width;
	int tex_height = game->map->walls[NORTH]->height;
	// printf("Texture Width: %d, Texture Height: %d\n", tex_width, tex_height);

	// double hit_x = (game->map->wall[x].x - (int)game->map->wall[x].x) / 64;
	// printf("h1:%f x1:%f x2:%d\n", hit_x, game->map->wall[x].x, (int)game->map->wall[x].x);
	if (game->map->wall_dir[x] == NORTH)
	{
		if (radian >=0 && radian <= ONE_PI)
			hit_x = game->map->wall[x].x / 64 - (int)game->map->wall[x].x / 64;
		else
			hit_x = 1.0 - (game->map->wall[x].x / 64 - (int)game->map->wall[x].x / 64);
	}
	else
	{
		if (radian >= HALF_PI && radian <= THREE_HALF_PI)
			hit_x = 1.0 - game->map->wall[x].y / 64 - (int)game->map->wall[x].y / 64;
		else
			hit_x = game->map->wall[x].y / 64 - (int)game->map->wall[x].y / 64;
	}
	// printf("h2:%f x1:%f x2:%d\n", hit_x, game->map->wall[x].x, (int)game->map->wall[x].x);

	// double hit_x = (int)(game->map->wall[x].x / 2.0) % tex_width;
	int tex_x = (int)(hit_x * tex_width);
	// int tex_x = (int)x;

	// printf("x: %d, ray: %d, hit_x: %f, tex_x: %d\n", x, ray, hit_x, tex_x);

	double y_step = (double)tex_height / line;
	double tex_pos = 0;

	y = 0;
	while (y < line)
	{
		// int tex_y = (int)(y * y_step) % game->map->walls[NORTH]->height;
		// int tex_y = (int)(y * y_step);
		// double tex_y = (double) y / line * game->map->walls[NORTH]->height;

		int tex_y = (int)tex_pos % tex_height;
		index = (tex_y * tex_width + tex_x) * 4;
		tex_pos += y_step;

		// printf("y: %d, tex_y: %d, index: %d\n", y, tex_y, index);

		if (game->map->wall_dir[x] == NORTH)
		{
			if (radian >=0 && radian <= ONE_PI)
				color = get_rgba(game->map->walls[NORTH]->pixels[index + 0],
								 game->map->walls[NORTH]->pixels[index + 1],
								 game->map->walls[NORTH]->pixels[index + 2],
								 game->map->walls[NORTH]->pixels[index + 3]);
			else
				color = get_rgba(game->map->walls[SOUTH]->pixels[index + 0],
								 game->map->walls[SOUTH]->pixels[index + 1],
								 game->map->walls[SOUTH]->pixels[index + 2],
								 game->map->walls[SOUTH]->pixels[index + 3]);
		}
		else
		{
			if (radian >= HALF_PI && radian <= THREE_HALF_PI)
				color = get_rgba(game->map->walls[WEST]->pixels[index + 0],
								 game->map->walls[WEST]->pixels[index + 1],
								 game->map->walls[WEST]->pixels[index + 2],
								 game->map->walls[WEST]->pixels[index + 3]);
			else
				color = get_rgba(game->map->walls[EAST]->pixels[index + 0],
								 game->map->walls[EAST]->pixels[index + 1],
								 game->map->walls[EAST]->pixels[index + 2],
								 game->map->walls[EAST]->pixels[index + 3]);
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
