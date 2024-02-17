/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:42:22 by mott              #+#    #+#             */
/*   Updated: 2024/02/17 21:25:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// - close hook for (x)
// what do i need to free?
// mlx close hook for (x) necessary?
// ft_printf -> toupper duplicate
// floodfile with only way through exit or enemy
// void mlx_get_monitor_size(int32_t index, int32_t* width, int32_t* height);

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		so_exit("malloc\n", NULL);
	so_load_map(game, argv[1]);
	so_run_game(game);
	return (EXIT_SUCCESS);
}

void	so_run_game(t_game *game)
{
	game->window = mlx_init(game->map_size.x * PIXEL, game->map_size.y * PIXEL,
			"so_long", false);
	if (game->window == NULL)
		so_exit(NULL, game);
	so_load_png(game);
	so_create_images(game);
	so_display_board(game);
	so_display_objects(game);
	mlx_key_hook(game->window, so_key_hook, game);
	mlx_loop(game->window);
	ft_printf("test\n");
	// mlx_delete_image();
	// mlx_delete_texture();
	mlx_terminate(game->window);
}

void	so_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		so_move_player(game, game->player.x, game->player.y - 1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		so_move_player(game, game->player.x - 1, game->player.y);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		so_move_player(game, game->player.x, game->player.y + 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		so_move_player(game, game->player.x + 1, game->player.y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// so_free(game);
		// exit(EXIT_SUCCESS);
		mlx_close_window(game->window);
	}
}

void	so_move_player(t_game *game, int x, int y)
{
	int	i;

	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E')
	{
		if (so_object_counter(game->map, game->map_size, 'C') == 0)
			ft_printf("YOU WON!\n");
		else
			return ;
	}
	// if (game->map[y][x] == '') // enemy
	// 	return ;
	game->player.x = x;
	game->player.y = y;
	game->img->player->instances[0].x = x * PIXEL;
	game->img->player->instances[0].y = y * PIXEL;

	if (game->map[y][x] == 'C')
	{
		i = 0;
		while (i < 5) // count collectibles -> struct
		{
			if (game->img->coll->instances[i].x == x * PIXEL
					&& game->img->coll->instances[i].y == y * PIXEL)
			{
				game->img->coll->instances[i].enabled = false;
				game->map[y][x] = '0';
				break ;
			}
			i++;
		}
		// i = game->cmap[y][x];
		// game->img->coll->enabled = false;
		// game->img->coll->instances[i].enabled = false;
		// game->map[y][x] = '0';
	}
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
	so_free_strs(game->map);
	free(game);
	if (exit_type != NULL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(exit_type, STDERR_FILENO);
	}
	else
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
