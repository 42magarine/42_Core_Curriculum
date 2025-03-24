/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:31 by mott              #+#    #+#             */
/*   Updated: 2024/02/20 14:28:40 by mott             ###   ########.fr       */
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
	game->png->enemy[0] = mlx_load_png("./textures/queen-01.png");
	game->png->enemy[1] = mlx_load_png("./textures/queen-02.png");
	game->png->enemy[2] = mlx_load_png("./textures/queen-03.png");
	game->png->enemy[3] = mlx_load_png("./textures/queen-04.png");
	game->png->enemy[4] = mlx_load_png("./textures/queen-05.png");
	game->png->enemy[5] = mlx_load_png("./textures/queen-06.png");
	game->png->enemy[6] = mlx_load_png("./textures/queen-07.png");
	game->png->enemy[7] = mlx_load_png("./textures/queen-08.png");
	if (game->png->board1 == NULL || game->png->board2 == NULL
		|| game->png->wall == NULL || game->png->collect == NULL
		|| game->png->exit == NULL || game->png->player == NULL
		|| game->png->enemy[0] == NULL || game->png->enemy[1] == NULL
		|| game->png->enemy[2] == NULL || game->png->enemy[3] == NULL
		|| game->png->enemy[4] == NULL || game->png->enemy[5] == NULL
		|| game->png->enemy[6] == NULL || game->png->enemy[7] == NULL)
		so_exit(ERR_MLX, NULL, game);
}

// convert png-files to images.
void	so_create_images(t_game *g)
{
	g->img = malloc(sizeof(t_images));
	if (g->img == NULL)
		so_exit(ERR_SYS, "malloc", g);
	g->img->board1 = mlx_texture_to_image(g->window, g->png->board1);
	g->img->board2 = mlx_texture_to_image(g->window, g->png->board2);
	g->img->wall = mlx_texture_to_image(g->window, g->png->wall);
	g->img->collect = mlx_texture_to_image(g->window, g->png->collect);
	g->img->exit = mlx_texture_to_image(g->window, g->png->exit);
	g->img->player = mlx_texture_to_image(g->window, g->png->player);
	g->img->enemy[0] = mlx_texture_to_image(g->window, g->png->enemy[0]);
	g->img->enemy[1] = mlx_texture_to_image(g->window, g->png->enemy[1]);
	g->img->enemy[2] = mlx_texture_to_image(g->window, g->png->enemy[2]);
	g->img->enemy[3] = mlx_texture_to_image(g->window, g->png->enemy[3]);
	g->img->enemy[4] = mlx_texture_to_image(g->window, g->png->enemy[4]);
	g->img->enemy[5] = mlx_texture_to_image(g->window, g->png->enemy[5]);
	g->img->enemy[6] = mlx_texture_to_image(g->window, g->png->enemy[6]);
	g->img->enemy[7] = mlx_texture_to_image(g->window, g->png->enemy[7]);
	if (g->img->board1 == NULL || g->img->board2 == NULL
		|| g->img->wall == NULL || g->img->collect == NULL
		|| g->img->exit == NULL || g->img->player == NULL
		|| g->img->enemy[0] == NULL || g->img->enemy[1] == NULL
		|| g->img->enemy[2] == NULL || g->img->enemy[3] == NULL
		|| g->img->enemy[4] == NULL || g->img->enemy[5] == NULL
		|| g->img->enemy[6] == NULL || g->img->enemy[7] == NULL)
		so_exit(ERR_MLX, NULL, g);
}

// Decides which board color should be displayed.
void	so_board_to_window(t_game *game, int x, int y)
{
	if ((y + x) % 2 == 0)
		so_image_to_window(game, game->img->board1, x, y);
	else
		so_image_to_window(game, game->img->board2, x, y);
}

// Decides which object should be displayed.
void	so_objects_to_window(t_game *game, int x, int y)
{
	int	i;

	if (game->map[y][x] == '1')
		so_image_to_window(game, game->img->wall, x, y);
	else if (game->map[y][x] == 'C')
		so_image_to_window(game, game->img->collect, x, y);
	else if (game->map[y][x] == 'E')
		so_image_to_window(game, game->img->exit, x, y);
	else if (game->map[y][x] == 'P')
		so_image_to_window(game, game->img->player, x, y);
	else if (game->map[y][x] == 'X')
	{
		i = 0;
		while (i < 8)
		{
			so_image_to_window(game, game->img->enemy[i], x, y);
			i++;
		}
	}
}

// Displays the image in the window.
void	so_image_to_window(t_game *game, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(game->window, img, x * PIXEL, y * PIXEL) == -1)
		so_exit(ERR_MLX, NULL, game);
}
