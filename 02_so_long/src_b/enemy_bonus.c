/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:27:16 by mott              #+#    #+#             */
/*   Updated: 2024/02/20 14:13:10 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Checks if the player touches the enemy patrol, moves and animates the enemy.
void	so_enemy_hook(void *param)
{
	t_game		*game;
	static int	loop;

	game = param;
	if (game->player.x == game->enemy.x && game->player.y == game->enemy.y)
	{
		ft_putstr_fd("You lose!\n", STDOUT_FILENO);
		mlx_close_window(game->window);
	}
	if (loop++ % 40 == 0)
	{
		if (game->player.x > game->enemy.x)
			so_move_enemy(game, game->enemy.x + 1, game->enemy.y);
		if (game->player.x < game->enemy.x)
			so_move_enemy(game, game->enemy.x - 1, game->enemy.y);
		if (game->player.y > game->enemy.y)
			so_move_enemy(game, game->enemy.x, game->enemy.y + 1);
		if (game->player.y < game->enemy.y)
			so_move_enemy(game, game->enemy.x, game->enemy.y - 1);
	}
	so_enemy_animation(game, loop / 10);
	if (loop == 80)
		loop = 0;
}

// Generates the animation by changing the visible image.
void	so_enemy_animation(t_game *game, int i)
{
	if (i < 7)
	{
		game->img->enemy[i]->enabled = false;
		game->img->enemy[i + 1]->enabled = true;
	}
	else if (i == 7)
	{
		game->img->enemy[i]->enabled = false;
		game->img->enemy[0]->enabled = true;
	}
}

// Moves enemy position and enemy images.
void	so_move_enemy(t_game *game, int x, int y)
{
	int	i;

	if (game->map[y][x] == '1')
		return ;
	i = 0;
	while (i < 8)
	{
		game->img->enemy[i]->instances[0].x = x * PIXEL;
		game->img->enemy[i]->instances[0].y = y * PIXEL;
		i++;
	}
	game->enemy.x = x;
	game->enemy.y = y;
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
