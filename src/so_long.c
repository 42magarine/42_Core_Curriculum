/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:42:22 by mott              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:10 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
// mlx close hook for (x) necessary?
// ft_printf -> toupper duplicate

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);

	(void)argv;
	run_game();

	return(EXIT_SUCCESS);
}

void	run_game(void)
{
	t_game		*game;

	game = malloc(sizeof(t_game));
	game->map_size = malloc(sizeof(t_position));
	game->map_size->x = 9;
	game->map_size->y = 9;
	game->player_position = malloc(sizeof(t_position));
	game->player_position->x = 3;
	game->player_position->y = 3;
	game->window = mlx_init(game->map_size->x * 64, game->map_size->y * 64, "so_long", false);
	// if (game == NULL)
	// 	sl_error();
	load_png(game);
	create_images(game);
	display_board(game);
	display_objects(game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->window);
	// mlx_delete_image();
	// mlx_delete_texture();
	mlx_terminate(game->window);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->player_position->y--;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->player_position->x--;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->player_position->y++;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->player_position->x++;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	display_board(game);
	display_objects(game);
	// mlx_image_to_window(game->window, game->images->player, game->player_position->x * 64, game->player_position->y * 64);
}

// void	hook(void *param)
// {
// 	t_game	*game;

// 	game = param;
// 	game->player_position->x = 0;
// 	game->player_position->y = 0;
// 	if (mlx_is_key_down(game->window, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->window);
// }

void	sl_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
