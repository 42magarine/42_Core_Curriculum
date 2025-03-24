/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:31 by mott              #+#    #+#             */
/*   Updated: 2024/02/20 14:39:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	if (game->png->board1 == NULL || game->png->board2 == NULL
		|| game->png->wall == NULL || game->png->collect == NULL
		|| game->png->exit == NULL || game->png->player == NULL)
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
	if (game->img->board1 == NULL || game->img->board2 == NULL
		|| game->img->wall == NULL || game->img->collect == NULL
		|| game->img->exit == NULL || game->img->player == NULL)
		so_exit(ERR_MLX, NULL, game);
}

// Decides which board color should be displayed.
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

// Decides which object should be displayed.
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
