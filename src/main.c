/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:31:12 by mott              #+#    #+#             */
/*   Updated: 2024/06/10 21:24:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/game.h"
#include <math.h>

int	ft_exit(const char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static void	init_var(t_game *game, t_player *player, t_window *window, t_map *map)
{
	game->player = player;
	player->x = 1;
	player->y = 1;
	player->fov = 60;
	player->angle = 0;
	player->size = 8;
	player->direction = 'S';

	game->window = window;
	window->width = 1024;
	window->height = 512;

	game->map = map;
	map->x = 16;
	map->y = 8;
	map->field_size = 64;
}

static void	ft_math(t_game *game)
{
	double	g_kathete;
	double	a_kathete;
	double	fov;

	g_kathete = game->window->width / 2;
	fov = game->player->fov * M_PI / 180;

	a_kathete = g_kathete / tan(fov / 2);
	printf("Ankathete: %f\n", a_kathete);
}

static t_coordinates ft_first_horizontal_grid(t_game *game, double radian)
{
	int				player_x;
	int				player_y;
	int				field_size;
	t_coordinates	grid;

	player_x = game->player->x;
	player_y = game->player->y;
	field_size = game->map->field_size;

	grid.y = player_y / field_size * field_size - 1;
	grid.x = player_x + (player_y - grid.y) * tan(radian);

	return (grid);
}

static t_coordinates ft_next_horizontal_grid(t_game *game, t_coordinates grid, double radian)
{
	grid.y -= game->map->field_size;
	grid.x += game->map->field_size * tan(radian);

	return (grid);
}

static int	ft_check_wall(t_game *game, t_coordinates grid)
{
	if (g_map[grid.y / 64][grid.x / 64] == '1')
		return (true);
	return (false);
}

static void ft_ray_caster(t_game *game)
{
	int	i;
	int	radian;
	t_coordinates	grid;

	i = 0;
	radian = 0;
	while (i < game->window->width)
	{
		grid = ft_first_horizontal_grid(game, radian);
		while (ft_check_wall(game, grid) == false)
		{
			grid = ft_next_horizontal_grid(game, grid, radian);
		}

		// check vertical grid
		// save shortest distance
		// print column with mlx_put_pixel

		radian += game->player->fov / game->window->width * M_PI / 180;
		i++;
	}
}

int	main(void)
{
	t_game		game;
	t_player	player;
	t_window	window;
	t_map		map;

	init_var(&game, &player, &window, &map);
	init_mlx(&game);
	ft_math(&game);
	return (EXIT_SUCCESS);
}
