/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:31 by mott              #+#    #+#             */
/*   Updated: 2024/02/16 16:23:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// load png-files form disk.
void	load_png(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	game->textures->board1 = mlx_load_png("./textures/wood_light.png");
	// if (textures->board1 == NULL)
	// 	sl_error();
	game->textures->board2 = mlx_load_png("./textures/wood_dark.png");
	// if (textures->board2 == NULL)
	// 	sl_error();
	game->textures->wall = mlx_load_png("./textures/wall.png");
	// if (textures->wall == NULL)
	// 	sl_error();
	game->textures->player = mlx_load_png("./textures/player.png");
	// if (textures->player == NULL)
	// 	sl_error();
	game->textures->collectible = mlx_load_png("./textures/collectible.png");
	// if (textures->collectible == NULL)
	// 	sl_error();
	game->textures->exit = mlx_load_png("./textures/exit.png");
	// if (textures->exit == NULL)
	// 	sl_error();
	game->textures->enemy = mlx_load_png("./textures/enemy.png");
	// if (textures->enemy == NULL)
	// 	sl_error();
}

// convert png-files to images.
void	create_images(t_game *game)
{
	game->images = malloc(sizeof(t_images));
	game->images->board1 = mlx_texture_to_image(game->window, game->textures->board1);
		ft_printf("hello\n");
	// if (game->images->board1 == NULL)
	// 	sl_error();
	game->images->board2 = mlx_texture_to_image(game->window, game->textures->board2);
	// if (game->images->board2 == NULL)
	// 	sl_error();
	game->images->wall = mlx_texture_to_image(game->window, game->textures->wall);
	// if (game->images->wall == NULL)
	// 	sl_error();
	game->images->player = mlx_texture_to_image(game->window, game->textures->player);
	// if (game->images->player == NULL)
	// 	sl_error();
	game->images->collectible = mlx_texture_to_image(game->window, game->textures->collectible);
	// if (game->images->collectible == NULL)
	// 	sl_error();
	game->images->exit = mlx_texture_to_image(game->window, game->textures->exit);
	// if (game->images->exit == NULL)
	// 	sl_error();
	game->images->enemy = mlx_texture_to_image(game->window, game->textures->enemy);
	// if (game->images->enemy == NULL)
	// 	sl_error();
}

void	display_board(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size->y)
	{
		x = 0;
		while (x < game->map_size->x)
		{
			if ((y + x) % 2 == 0)
				mlx_image_to_window(game->window, game->images->board1, x * 64, y * 64); //mlx_error
			else
				mlx_image_to_window(game->window, game->images->board2, x * 64, y * 64); //mlx_error
			x++;
		}
		y++;
	}
}

void	display_objects(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size->y)
	{
		x = 0;
		while (x < game->map_size->x)
		{
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->window, game->images->player, game->player_position->x * 64, game->player_position->y * 64);
	mlx_image_to_window(game->window, game->images->collectible, 5 * 64, 4 * 64);
	mlx_image_to_window(game->window, game->images->enemy, 4 * 64, 4 * 64);
	mlx_image_to_window(game->window, game->images->exit, 1 * 64, 1 * 64);
	mlx_image_to_window(game->window, game->images->wall, 0 * 64, 0 * 64);
}
