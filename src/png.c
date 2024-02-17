/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:31 by mott              #+#    #+#             */
/*   Updated: 2024/02/17 20:43:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// load png-files form disk.
void	so_load_png(t_game *game)
{
	game->png = malloc(sizeof(t_textures));
	if (game->png == NULL)
		so_exit("malloc\n", game);
	game->png->board1 = mlx_load_png("./textures/wood_light.png");
	if (game->png->board1 == NULL)
		so_exit(NULL, game);
	game->png->board2 = mlx_load_png("./textures/wood_dark.png");
	if (game->png->board2 == NULL)
		so_exit(NULL, game);
	game->png->wall = mlx_load_png("./textures/wall.png");
	if (game->png->wall == NULL)
		so_exit(NULL, game);
	game->png->coll = mlx_load_png("./textures/collectible.png");
	if (game->png->coll == NULL)
		so_exit(NULL, game);
	game->png->exit = mlx_load_png("./textures/exit.png");
	if (game->png->exit == NULL)
		so_exit(NULL, game);
	game->png->player = mlx_load_png("./textures/player.png");
	if (game->png->player == NULL)
		so_exit(NULL, game);
	// game->png->enemy = mlx_load_png("./textures/enemy.png");
	// if (game->png->enemy == NULL)
	// 	so_exit(NULL, game);
}

// convert png-files to images.
void	so_create_images(t_game *game)
{
	game->img = malloc(sizeof(t_images));
	if (game->img == NULL)
		so_exit("malloc\n", game);
	// ft_printf("hello 1\n");
	game->img->board1 = mlx_texture_to_image(game->window, game->png->board1);
	if (game->img->board1 == NULL)
		so_exit(NULL, game);
	// ft_printf("hello 2\n");
	game->img->board2 = mlx_texture_to_image(game->window, game->png->board2);
	if (game->img->board2 == NULL)
		so_exit(NULL, game);
	game->img->wall = mlx_texture_to_image(game->window, game->png->wall);
	if (game->img->wall == NULL)
		so_exit(NULL, game);
	game->img->coll = mlx_texture_to_image(game->window, game->png->coll);
	if (game->img->coll == NULL)
		so_exit(NULL, game);
	game->img->exit = mlx_texture_to_image(game->window, game->png->exit);
	if (game->img->exit == NULL)
		so_exit(NULL, game);
	game->img->player = mlx_texture_to_image(game->window, game->png->player);
	if (game->img->player == NULL)
		so_exit(NULL, game);
	// game->img->enemy = mlx_texture_to_image(game->window, game->png->enemy);
	// if (game->img->enemy == NULL)
	// 	so_exit(NULL, game);
}

void	so_display_board(t_game *game)
{
	t_xy	xy;

	xy.y = 0;
	while (xy.y < game->map_size.y)
	{
		xy.x = 0;
		while (xy.x < game->map_size.x)
		{
			if ((xy.y + xy.x) % 2 == 0)
			{
				if (mlx_image_to_window(game->window, game->img->board1,
						xy.x * PIXEL, xy.y * PIXEL) == -1)
					so_exit(NULL, game);
			}
			else
			{
				if (mlx_image_to_window(game->window, game->img->board2,
						xy.x * PIXEL, xy.y * PIXEL) == -1)
					so_exit(NULL, game);
			}
			xy.x++;
		}
		xy.y++;
	}
}

void	so_display_objects(t_game *game)
{
	t_xy	xy;
	// int		collect_instance;

	// so_create_cmap(game);
	xy.y = 0;
	while (xy.y < game->map_size.y)
	{
		xy.x = 0;
		while (xy.x < game->map_size.x)
		{
			if (game->map[xy.y][xy.x] == '1')
			{
				if (mlx_image_to_window(game->window, game->img->wall,
						xy.x * PIXEL, xy.y * PIXEL) == -1)
					so_exit(NULL, game);
			}
			if (game->map[xy.y][xy.x] == 'C')
			{
				if (mlx_image_to_window(game->window, game->img->coll,
						xy.x * PIXEL, xy.y * PIXEL) == -1)
					so_exit(NULL, game);
				// collect_instance = mlx_image_to_window(game->window, game->img->coll,
				// 		xy.x * PIXEL, xy.y * PIXEL);
				// if (collect_instance == -1)
				// 	so_exit(NULL, game);
				// else
				// 	game->cmap[xy.y][xy.x] = collect_instance;
			}
			if (game->map[xy.y][xy.x] == 'E')
			{
				if (mlx_image_to_window(game->window, game->img->exit,
						xy.x * PIXEL, xy.y * PIXEL) == -1)
					so_exit(NULL, game);
			}
			if (game->map[xy.y][xy.x] == 'P')
			{
				if (mlx_image_to_window(game->window, game->img->player,
						xy.x * PIXEL, xy.y * PIXEL) == -1)
					so_exit(NULL, game);
			}
			// if (game->map[xy.y][xy.x] == '?')
			// {
			// 	if (mlx_image_to_window(game->window, game->img->enemy,
			// 			xy.x * PIXEL, xy.y * PIXEL) == -1);
			// 		so_exit(NULL, game);
			// }
			xy.x++;
		}
		xy.y++;
	}
}
