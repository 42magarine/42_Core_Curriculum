/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:46:51 by mott              #+#    #+#             */
/*   Updated: 2024/02/19 17:44:19 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_init_game(t_game *game)
{
	game->window = mlx_init(game->map_size.x * PIXEL, game->map_size.y * PIXEL,
			"so_long", false);
	if (game->window == NULL)
		so_exit(ERR_MLX, NULL, game);
	so_load_png(game);
	so_create_images(game);
	so_free_png(game->png);
	so_loop_map(game, so_board_to_window);
	so_loop_map(game, so_objects_to_window);
	mlx_key_hook(game->window, so_key_hook, game);
	mlx_loop(game->window);
	mlx_terminate(game->window);
	so_free_strs(game->map);
	free(game->img);
}

void	so_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		so_move_player(game, game->player.x, game->player.y - 1);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		so_move_player(game, game->player.x - 1, game->player.y);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		so_move_player(game, game->player.x, game->player.y + 1);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		so_move_player(game, game->player.x + 1, game->player.y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->window);
}

// replace mlx_key_hook() with: mlx_loop_hook(game->window, so_hook, game);
// void	so_hook(void *param)
// {
// 	t_game	*game;

// 	game = param;
// 	if (mlx_is_key_down(game->window, MLX_KEY_W))
// 		so_move_player(game, game->player.x, game->player.y - 1);
// 	if (mlx_is_key_down(game->window, MLX_KEY_A))
// 		so_move_player(game, game->player.x - 1, game->player.y);
// 	if (mlx_is_key_down(game->window, MLX_KEY_S))
// 		so_move_player(game, game->player.x, game->player.y + 1);
// 	if (mlx_is_key_down(game->window, MLX_KEY_D))
// 		so_move_player(game, game->player.x + 1, game->player.y);
// 	if (mlx_is_key_down(game->window, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->window);
// }

void	so_move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	game->img->exit->enabled = true;
	game->img->player->instances[0].x = x * PIXEL;
	game->img->player->instances[0].y = y * PIXEL;
	game->player.x = x;
	game->player.y = y;
	game->move_count++;
	ft_printf("Move: %02d\n", game->move_count);
	if (game->map[y][x] == 'C')
		so_collect_collectible(game, x, y);
	else if (game->map[y][x] == 'E')
		so_did_you_win(game);
}

void	so_collect_collectible(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->collect_count)
	{
		if (game->img->collect->instances[i].x == x * PIXEL
			&& game->img->collect->instances[i].y == y * PIXEL)
		{
			game->img->collect->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

void	so_did_you_win(t_game *game)
{
	int		i;
	bool	finished;

	finished = true;
	i = 0;
	while (i < game->collect_count)
	{
		if (game->img->collect->instances[i].enabled == true)
			finished = false;
		i++;
	}
	if (finished == false)
		game->img->exit->enabled = false;
	else
	{
		ft_putstr_fd("You win!\n", STDOUT_FILENO);
		mlx_close_window(game->window);
	}
}
