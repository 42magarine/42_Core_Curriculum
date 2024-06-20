/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:28:04 by mott              #+#    #+#             */
/*   Updated: 2024/06/20 18:10:09 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_wall(t_game *game, int x, int ray, double radian)
{
	int	line;
	int	line_offset;
	int	color;
	int	y;

	line = F_SIZE * HEIGHT / ray;
	if (line > HEIGHT)
		line = HEIGHT;
	line_offset = (HEIGHT - line) / 2;
	if (game->map->wall_dir[x] == NORTH)
	{
		if (radian >=0 && radian <= ONE_PI)
			color = RED;
		else
			color = BLUE;
	}
	else
	{
		if (radian >= HALF_PI && radian <= THREE_HALF_PI)
			color = YELLOW;
		else
			color = GREEN;
	}
	y = line_offset;
	while (y < line_offset + line)
	{
		mlx_put_pixel(game->window->image, x, y, color);
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
