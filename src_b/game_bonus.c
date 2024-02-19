/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:46:51 by mott              #+#    #+#             */
/*   Updated: 2024/02/19 21:57:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	mlx_loop_hook(game->window, so_enemy_hook, game);
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

void	so_enemy_hook(void *param)
{
	t_game		*game;
	static int	loop;

	game = param;
	if (game->enemy.y == game->player.y && game->enemy.x == game->player.x)
	{
		ft_putstr_fd("You lose!\n", STDOUT_FILENO);
		mlx_close_window(game->window);
	}
	if (loop % 25 == 0)
	{
		if (game->enemy.y > game->player.y)
			so_move_enemy(game, game->enemy.y - 1, game->enemy.x);
		if (game->enemy.y < game->player.y)
			so_move_enemy(game, game->enemy.y + 1, game->enemy.x);
		if (game->enemy.x > game->player.x)
			so_move_enemy(game, game->enemy.y, game->enemy.x - 1);
		if (game->enemy.x < game->player.x)
			so_move_enemy(game, game->enemy.y, game->enemy.x + 1);
	}
	if (loop++ < 25)
	{
		game->img->enemy1->enabled = false;
		game->img->enemy2->enabled = true;
	}
	else if (loop++ < 50)
	{
		game->img->enemy1->enabled = true;
		game->img->enemy2->enabled = false;
	}
	else
		loop = 0;
}

void	so_move_enemy(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return ;
	game->img->enemy1->instances[0].x = x * PIXEL;
	game->img->enemy1->instances[0].y = y * PIXEL;
	game->img->enemy2->instances[0].x = x * PIXEL;
	game->img->enemy2->instances[0].y = y * PIXEL;
	game->enemy.x = x;
	game->enemy.y = y;
}

void	so_move_player(t_game *game, int x, int y)
{
	char	*moves;

	if (game->map[y][x] == '1')
		return ;
	game->img->exit->enabled = true;
	game->img->player->instances[0].x = x * PIXEL;
	game->img->player->instances[0].y = y * PIXEL;
	game->player.x = x;
	game->player.y = y;
	game->move_count++;
	moves = ft_itoa(game->move_count);
	mlx_image_to_window(game->window, game->img->wall, (game->map_size.x - 2) * PIXEL, 0);
	mlx_put_string(game->window, "Moves:", (game->map_size.x - 2) * PIXEL + 5, 22);
	mlx_image_to_window(game->window, game->img->wall, (game->map_size.x - 1) * PIXEL, 0);
	mlx_put_string(game->window, moves, (game->map_size.x - 1) * PIXEL + 5, 22);
	free(moves);
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
