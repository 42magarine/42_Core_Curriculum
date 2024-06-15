/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:06 by mott              #+#    #+#             */
/*   Updated: 2024/06/15 15:05:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static t_coordinates	ft_check_wall(t_game *game, t_coordinates grid, t_coordinates next_grid, char *debug)
{
	// while (true)
	while (grid.x >= 0 && grid.x / 64 < game->map->x && grid.y >= 0 && grid.y / 64 < game->map->y)
	{
		printf("check wall [%s]: x: %d y: %d\n", debug, grid.x / 64, grid.y / 64);
		if (g_map[grid.y / 64][grid.x / 64] == '1')
			break ;
		else
		{
			grid.x += next_grid.x;
			grid.y += next_grid.y;
		}
	}
	printf("----->> find wall [%s]: x: %d y: %d\n\n", debug, grid.x / 64, grid.y / 64);
	return (grid);
}

static t_coordinates	ft_horizontal_grid(t_game *game, double radian)
{
	t_coordinates	grid;
	t_coordinates	next_grid;

	// if (sin(radian) > 0)
	// printf("radian: %f\n", radian);
	if (radian > 0 && radian < M_PI) // up
	{
		// printf("here1\n");
		grid.y = (game->player->y / 64) * 64 - 1;
		grid.x = (game->player->y - grid.y) / tan(radian) + game->player->x;
		next_grid.y = -64;
		next_grid.x = 64 / tan(radian);
		// printf("horizontal %f\n", radian);
		grid = ft_check_wall(game, grid, next_grid, "H-up");
	}
	// else if (sin(radian) < 0)
	else if (radian > M_PI && radian < 2 * M_PI) // down
	{
		// printf("here2\n");
		grid.y = (game->player->y / 64) * 64 + 64;
		grid.x = (game->player->y - grid.y) / tan(radian) + game->player->x;
		next_grid.y = 64;
		next_grid.x = -64 / tan(radian);
		// printf("horizontal  %f\n", radian);
		grid = ft_check_wall(game, grid, next_grid, "H-down");
	}
	// else if (radian == 0 || radian == M_PI) // right and left
	else
	{
		// printf("here3\n");
		grid.x = game->player->x;
		grid.y = game->player->y;
	}
	return (grid);
}

static t_coordinates	ft_vertical_grid(t_game *game, double radian)
{
	t_coordinates	grid;
	t_coordinates	next_grid;

	// if (cos(radian) > 0)
	if (radian < M_PI / 2 || radian > 3 * M_PI / 2) // right
	{
		grid.x = (game->player->x / 64) * 64 + 64;
		grid.y = (game->player->x - grid.x) * tan(radian) + game->player->y;
		next_grid.x = 64;
		next_grid.y = -64 * tan(radian);
		// printf("vertical %f\n", radian);
		grid = ft_check_wall(game, grid, next_grid, "V-right");
	}
	// else if (cos(radian) < 0)
	else if (radian > M_PI / 2 && radian < 3 * M_PI / 2) // left
	{
		grid.x = (game->player->x / 64) * 64 - 1;
		grid.y = (game->player->x - grid.x) * tan(radian) + game->player->y;
		next_grid.x = -64;
		next_grid.y = 64 * tan(radian);
		// printf("vertical %f\n", radian);
		grid = ft_check_wall(game, grid, next_grid, "V-left");
	}
	// else if (radian == M_PI / 2 || radian == 3 * M_PI / 2) // up and down
	else // up and down
	{
		grid.x = game->player->x;
		grid.y = game->player->y;
	}
	return (grid);
}

static int	ft_wall_distance(t_game *game, t_coordinates grid_h, t_coordinates grid_v)
{
	double	distance_h;
	double	distance_v;
	double	px;
	double	py;

	px = game->player->x;
	py = game->player->y;

	// distance_h = abs(grid_h.x - game->player->x) / cos(radian);
	distance_h = sqrt((px - grid_h.x) * (px - grid_h.x) + (py - grid_h.y) * (py - grid_h.y));
	// printf("distance_h: %f\n", distance_h);
	if (distance_h == 0)
		distance_h = 999;

	// distance_v = abs(grid_v.x - game->player->x) / cos(radian);
	distance_v = sqrt((px - grid_v.x) * (px - grid_v.x) + (py - grid_v.y) * (py - grid_v.y));
	// printf("distance_v: %f\n", distance_v);
	if (distance_v == 0)
		distance_v = 999;

	if (distance_h < distance_v)
	{
		ft_draw_line(game, grid_h.x, grid_h.y);
		return (distance_h);
	}
	else
	{
		ft_draw_line(game, grid_v.x, grid_v.y);
		return (distance_v);
	}
}

void	ft_ray_caster(t_game *game)
{
	double			radian;
	t_coordinates	grid_h;
	t_coordinates	grid_v;
	double			shortest;

	// radian = game->player->direction * M_PI / 180;
	radian = game->player->direction;
	// radian =   0 * M_PI / 180;
	// radian =  90 * M_PI / 180;
	// radian = 180 * M_PI / 180;
	// radian = 270 * M_PI / 180;

	grid_h = ft_horizontal_grid(game, radian);
	// printf("grid_h.x: %d - grid_h.y: %d\n", grid_h.x, grid_h.y);
	grid_v = ft_vertical_grid(game, radian);
	// printf("grid_v.x: %d - grid_v.y: %d\n", grid_v.x, grid_v.y);

	shortest = ft_wall_distance(game, grid_h, grid_v);
	// printf("\n");
}
