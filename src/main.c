/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:31:12 by mott              #+#    #+#             */
/*   Updated: 2024/06/11 19:57:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_exit(const char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

// static int	ft_math(t_game *game)
// {
// 	double	g_kathete;
// 	double	a_kathete;
// 	double	fov;

// 	g_kathete = game->window->width / 2;
// 	fov = game->player->fov * M_PI / 180;

// 	a_kathete = g_kathete / tan(fov / 2);
// 	return (a_kathete);
// 	// printf("Ankathete: %f\n", a_kathete);
// }

// static t_coordinates ft_first_horizontal_grid(t_game *game, double radian)
// {
// 	int				player_x;
// 	int				player_y;
// 	int				field_size;
// 	t_coordinates	grid;

// 	player_x = game->player->x;
// 	player_y = game->player->y;
// 	field_size = game->map->field_size;

// 	if (sin(radian) > 0)
// 		grid.y = (player_y / field_size) * field_size - 1;
// 	else
// 		grid.y = (player_y / field_size) * field_size + field_size;

// 	grid.x = player_x + (player_y - grid.y) / tan(radian);
// 	if (grid.x < 0)
// 		grid.x = 1;

// 	return (grid);
// }

// static t_coordinates ft_next_horizontal_grid(t_game *game, t_coordinates grid, double radian)
// {
// 	int	field_size = game->map->field_size;

// 	if (sin(radian) > 0)
// 		grid.y -= field_size;
// 	else
// 		grid.y += field_size;

// 	grid.x += field_size / tan(radian);
// 	if (grid.x < 0)
// 		grid.x = 1;

// 	return (grid);
// }

// static t_coordinates ft_first_vertical_grid(t_game *game, double radian)
// {
// 	int				player_x;
// 	int				player_y;
// 	int				field_size;
// 	t_coordinates	grid;

// 	player_x = game->player->x;
// 	player_y = game->player->y;
// 	field_size = game->map->field_size;

// 	if (sin(radian) > 0)
// 		grid.x = (player_x / field_size) * field_size + field_size;
// 	else
// 		grid.x = (player_x / field_size) * field_size - 1;

// 	grid.y = player_y - abs(player_x - grid.x) * tan(radian);
// 	if (grid.y < 0)
// 		grid.y = 1;

// 	return (grid);
// }

// static t_coordinates ft_next_vertical_grid(t_game *game, t_coordinates grid, double radian)
// {
// 	int	field_size = game->map->field_size;

// 	if (sin(radian) > 0)
// 		grid.x += field_size;
// 	else
// 		grid.x -= field_size;

// 	grid.y -= field_size * tan(radian);
// 	if (grid.y < 0)
// 		grid.y = 1;

// 	return (grid);
// }

// static int	ft_check_wall(t_game *game, t_coordinates grid)
// {
// 	printf("check field: x: %d y: %d\n", grid.x / 64, grid.y / 64);
// 	if (g_map[grid.y / 64][grid.x / 64] == '1')
// 		return (true);
// 	return (false);
// }

// static int	ft_wall_distance(t_game *game, t_coordinates grid_h, t_coordinates grid_v, double radian)
// {
// 	double	distance_h;
// 	double	distance_v;

// 	distance_h = abs(grid_h.x - game->player->x) / cos(radian);
// 	printf("distance_h: %f\n", distance_h);
// 	distance_v = abs(grid_v.x - game->player->x) / cos(radian);
// 	printf("distance_v: %f\n", distance_v);

// 	if (distance_h < distance_v)
// 	{
// 		game->x = grid_h.x;
// 		game->y = grid_h.y;
// 		return (distance_h);
// 	}
// 	else
// 	{
// 		game->x = grid_v.x;
// 		game->y = grid_v.y;
// 		return (distance_v);
// 	}
// }

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

// void ft_ray_caster(t_game *game)
// {
// 	int				i;
// 	double			radian;
// 	t_coordinates	grid_h;
// 	t_coordinates	grid_v;
// 	double			shortest_distance;
// 	double			start_angle;
// 	double			radian_step;

// 	i = 0;
// 	start_angle = M_PI - (game->player->fov / 2) * M_PI / 180;
// 	radian_step = game->player->fov * M_PI / 180 / game->window->width;

// 	while (i < game->window->width)
// 	{
// 		radian = start_angle + i * radian_step;
// 		printf("[%d]radian: %f\n", i, radian);

// 		grid_h = ft_first_horizontal_grid(game, radian);
// 		while (ft_check_wall(game, grid_h) == false)
// 			grid_h = ft_next_horizontal_grid(game, grid_h, radian);
// 		printf("grid_h.x: %d - grid_h.y: %d\n", grid_h.x, grid_h.y);

// 		grid_v = ft_first_vertical_grid(game, radian);
// 		while (ft_check_wall(game, grid_v) == false)
// 			grid_v = ft_next_vertical_grid(game, grid_v, radian);
// 		printf("grid_v.x: %d - grid_v.y: %d\n", grid_v.x, grid_v.y);

// 		shortest_distance = abs(ft_wall_distance(game, grid_h, grid_v, radian)); //abs
// 		ft_draw_line(game);
// 		printf("[%d]shortest_distance: %f\n", i, shortest_distance);

// 		ft_draw_wall(game, i, shortest_distance);

// 		radian += game->player->fov * M_PI / 180 / game->window->width ;
// 		i++;
// 	}
// 	if (mlx_image_to_window(game->window->mlx, game->window->image, 0, 0) == -1)
// 		ft_exit(mlx_strerror(mlx_errno));
// }

int	main(void)
{
	t_game		game;
	t_player	player;
	t_window	window;
	t_map		map;

	init_var(&game, &player, &window, &map);
	init_mlx(&game);
	return (EXIT_SUCCESS);
}
