/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:28:04 by mott              #+#    #+#             */
/*   Updated: 2024/06/19 15:20:03 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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

// static int	ft_math(t_game *game)
// {
// 	double	g_kathete;
// 	double	a_kathete;
// 	double	fov;

// 	g_kathete = game->WIDTH / 2;
// 	fov = game->player->fov * M_PI / 180;

// 	a_kathete = g_kathete / tan(fov / 2);
// 	return (a_kathete);
// 	// printf("Ankathete: %f\n", a_kathete);
// }

static void	draw_background(t_game *game)
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

void	draw_game(t_game *game)
{
	draw_background(game);
}
