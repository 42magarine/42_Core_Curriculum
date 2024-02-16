/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:42:22 by mott              #+#    #+#             */
/*   Updated: 2024/02/16 20:49:41 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	t_game	*game;

	if (argc != 2)
		return (EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		so_exit("malloc", NULL);

	so_load_map(game, argv[1]);
	run_game(game);

	return(EXIT_SUCCESS);
}

void	run_game(t_game *game)
{

	game->player_position = malloc(sizeof(t_xy));
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
		game->images->player->instances[0].y -= 64;
		// game->player_position->y--;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->images->player->instances[0].x -= 64;
		// game->player_position->x--;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->images->player->instances[0].y += 64;
		// game->player_position->y++;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->images->player->instances[0].x += 64;
		// game->player_position->x++;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	// display_board(game);
	// display_objects(game);
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

void	so_exit(char *exit_type, t_game *game)
{
	int	i;

	if (game != NULL)
	{
		if (game->map_size != NULL)
			free(game->map_size);
		if (game->map != NULL)
		{
			i = 0;
			while (game->map[i] != NULL)
			{
				free(game->map[i]);
				i++;
			}
			free(game->map);
		}
		free(game);
	}

	if (ft_strncmp(exit_type, "open", 5) == 0)
		ft_putstr_fd("Error\nCould not open file.\n", STDERR_FILENO);
	if (ft_strncmp(exit_type, "malloc", 7) == 0)
		ft_putstr_fd("Error\nmalloc().\n", STDERR_FILENO);
	if (ft_strncmp(exit_type, "rectangular", 12) == 0)
		ft_putstr_fd("Error\nMap is not rectangular.\n", STDERR_FILENO);
	if (ft_strncmp(exit_type, "wall", 5) == 0)
		ft_putstr_fd("Error\nMap is not surrounded by walls.\n", STDERR_FILENO);
	if (ft_strncmp(exit_type, "player", 7) == 0)
		ft_putstr_fd("Error\nWrong number of players.\n", STDERR_FILENO);
	if (ft_strncmp(exit_type, "collectibles", 13) == 0)
		ft_putstr_fd("Error\nWrong number of collectibles.\n", STDERR_FILENO);
	if (ft_strncmp(exit_type, "exit", 5) == 0)
		ft_putstr_fd("Error\nWrong number of exits.\n", STDERR_FILENO);

	// ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
