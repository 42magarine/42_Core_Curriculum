/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:31 by mott              #+#    #+#             */
/*   Updated: 2024/02/19 20:14:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// load png-files form disk.
void	so_load_png(t_game *game)
{
	game->png = malloc(sizeof(t_textures));
	if (game->png == NULL)
		so_exit(ERR_SYS, "malloc", game);
	game->png->board1 = mlx_load_png("./textures/wood_light.png");
	game->png->board2 = mlx_load_png("./textures/wood_dark.png");
	game->png->wall = mlx_load_png("./textures/wall.png");
	game->png->collect = mlx_load_png("./textures/collectible.png");
	game->png->exit = mlx_load_png("./textures/exit.png");
	game->png->player = mlx_load_png("./textures/player.png");
	game->png->enemy1 = mlx_load_png("./textures/enemy1.png");
	game->png->enemy2 = mlx_load_png("./textures/enemy2.png");
	if (game->png->board1 == NULL || game->png->board2 == NULL
		|| game->png->wall == NULL || game->png->collect == NULL
		|| game->png->exit == NULL || game->png->player == NULL
		|| game->png->enemy1 == NULL || game->png->enemy2 == NULL)
		so_exit(ERR_MLX, NULL, game);
}

// convert png-files to images.
void	so_create_images(t_game *game)
{
	game->img = malloc(sizeof(t_images));
	if (game->img == NULL)
		so_exit(ERR_SYS, "malloc", game);
	game->img->board1 = mlx_texture_to_image(game->window, game->png->board1);
	game->img->board2 = mlx_texture_to_image(game->window, game->png->board2);
	game->img->wall = mlx_texture_to_image(game->window, game->png->wall);
	game->img->collect = mlx_texture_to_image(game->window, game->png->collect);
	game->img->exit = mlx_texture_to_image(game->window, game->png->exit);
	game->img->player = mlx_texture_to_image(game->window, game->png->player);
	game->img->enemy1 = mlx_texture_to_image(game->window, game->png->enemy1);
	game->img->enemy2 = mlx_texture_to_image(game->window, game->png->enemy2);
	if (game->img->board1 == NULL || game->img->board2 == NULL
		|| game->img->wall == NULL || game->img->collect == NULL
		|| game->img->exit == NULL || game->img->player == NULL
		|| game->img->enemy1 == NULL || game->img->enemy2 == NULL)
		so_exit(ERR_MLX, NULL, game);
}

void	so_board_to_window(t_game *game, int x, int y)
{
	if ((y / PIXEL + x / PIXEL) % 2 == 0)
	{
		if (mlx_image_to_window(game->window, game->img->board1, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
	}
	else
	{
		if (mlx_image_to_window(game->window, game->img->board2, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
	}
}

void	so_objects_to_window(t_game *game, int x, int y)
{
	if (game->map[y / PIXEL][x / PIXEL] == '1')
	{
		if (mlx_image_to_window(game->window, game->img->wall, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
	}
	else if (game->map[y / PIXEL][x / PIXEL] == 'C')
	{
		if (mlx_image_to_window(game->window, game->img->collect, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
	}
	else if (game->map[y / PIXEL][x / PIXEL] == 'E')
	{
		if (mlx_image_to_window(game->window, game->img->exit, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
	}
	else if (game->map[y / PIXEL][x / PIXEL] == 'P')
	{
		if (mlx_image_to_window(game->window, game->img->player, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
	}
	else if (game->map[y / PIXEL][x / PIXEL] == 'X')
	{
		if (mlx_image_to_window(game->window, game->img->enemy1, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
		if (mlx_image_to_window(game->window, game->img->enemy2, x, y) == -1)
			so_exit(ERR_MLX, NULL, game);
	}
}

// Calculates the length of the string until '\n'.
int	so_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != '\n')
		i++;
	return (i);
}
