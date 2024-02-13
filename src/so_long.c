/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:42:22 by mott              #+#    #+#             */
/*   Updated: 2024/02/13 18:51:35 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);

	(void)argv;
	run_game();

	return(EXIT_SUCCESS);
}

// - read map (get_next_line)
// 	check filename?
// 	check exit = 1, player = 1, collectibles >= 1
// 	check rectangular
// 	check walls
// 	check vaild path to, collectibles + exit (floodfill)

// - init window
// - load all png as texture
// - create images from texture
// - display map
// - close hook for (x)
// - key hook for ESC, WASD
// - loop
// what do i need to free?
// makefile doesnt re-compile if i change headerfile

void	run_game()
{
	mlx_t		*game;
	t_textures	*textures;
	t_images	*images;
	t_pos		*mapsize;

	mapsize = malloc(sizeof(t_pos));
	mapsize->x = 8;
	mapsize->y = 8;
	// mlx_set_setting(MLX_MAXIMIZED, true);
	// game = mlx_init(WIDTH, HEIGHT, "so_long", true);
	game = mlx_init(WIDTH, HEIGHT, "so_long", false);
	if (game == NULL)
		sl_error();
	textures = load_png();
	images = create_images(game, textures);
	display_board(game, mapsize, images);
	mlx_loop(game);
	// mlx_delete_image();
	// mlx_delete_texture();
	mlx_terminate(game);
}

t_textures	*load_png(void) //mlx_errors
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	textures->board1 = mlx_load_png("./textures/wood_light.png");
	if (textures->board1 == NULL)
		sl_error();
	textures->board2 = mlx_load_png("./textures/wood_dark.png");
	textures->wall = mlx_load_png("./textures/wall.png");
	textures->player = mlx_load_png("./textures/player.png");
	textures->collectible = mlx_load_png("./textures/collectible.png");
	textures->enemy = mlx_load_png("./textures/enemy.png");
	return (textures);
}

t_images	*create_images(mlx_t *game, t_textures *textures) //mlx_error
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	images->board1 = mlx_texture_to_image(game, textures->board1);
	if (images->board1 == NULL)
		sl_error();
	images->board2 = mlx_texture_to_image(game, textures->board2);
	images->wall = mlx_texture_to_image(game, textures->wall);
	images->player = mlx_texture_to_image(game, textures->player);
	images->collectibles = mlx_texture_to_image(game, textures->collectible);
	images->enemy = mlx_texture_to_image(game, textures->enemy);
	return (images);
}

void	display_board(mlx_t *game, t_pos *mapsize, t_images *images)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	pos->y = 0;
	while (pos->y < mapsize->y)
	{
		pos->x = 0;
		while (pos->x < mapsize->x)
		{
			if ((pos->y + pos->x) % 2 == 0)
				mlx_image_to_window(game, images->board1, pos->y * 64, pos->x * 64); //mlx_error
			else
				mlx_image_to_window(game, images->board2, pos->y * 64, pos->x * 64); //mlx_error
			pos->x++;
		}
		pos->y++;
	}
}

void	sl_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
