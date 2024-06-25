/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/06/25 15:39:22 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	draw_square(t_game *game, t_coords pos, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_pixel(game->window->image, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	mini_x;
	int	mini_y;

	mini_x = WIDTH - game->map->max.x * F_SIZE - F_SIZE;
	if (mini_x < F_SIZE)
		mini_x = F_SIZE;
	mini_y = F_SIZE;
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (mini_x + (x << 5) < WIDTH && 2 * mini_y + (y << 5) < HEIGHT)
			// if (mini_x + (x << 5) >= 0 && mini_x + (x << 5) < WIDTH
			// 	&& mini_y + (y << 5) >= 0 && mini_y + (y << 5) < HEIGHT)
			{
				if (game->map->map[y][x] == '1')
					draw_square(game, (t_coords){mini_x + (x << 5), mini_y + (y << 5)}, F_SIZE, GRAY);
				else if (game->map->map[y][x] == 'D' || game->map->map[y][x] == 'd')
					draw_square(game, (t_coords){mini_x + (x << 5), mini_y + (y << 5)}, F_SIZE, GREEN);
				else if (game->map->map[y][x] == '0' || is_player_char(game->map->map[y][x]) == true)
					draw_square(game, (t_coords){mini_x + (x << 5), mini_y + (y << 5)}, F_SIZE, SILVER);
			}
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *game)
{
	t_coords	player;
	int	mini_x;
	int	mini_y;

	mini_x = WIDTH - game->map->max.x * F_SIZE - F_SIZE;
	if (mini_x < F_SIZE)
		mini_x = F_SIZE;
	mini_y = F_SIZE;

	// player.x = game->player->pos.x - (P_SIZE >> 1);
	// player.y = game->player->pos.y - (P_SIZE >> 1);
	player.x = mini_x + game->player->pos.x - (P_SIZE >> 1);
	player.y = mini_y + game->player->pos.y - (P_SIZE >> 1);
	// printf("px:%f py:%f\n", player.x, player.y);
	if (player.x < WIDTH && player.y < HEIGHT)
		draw_square(game, player, P_SIZE, YELLOW);
}

static void	draw_ray(t_game *game, t_coords player, t_coords wall)
{
	double	dx;
	double	dy;
	int		i;
	int	mini_x;
	int	mini_y;

	mini_x = WIDTH - game->map->max.x * F_SIZE - F_SIZE;
	if (mini_x < F_SIZE)
		mini_x = F_SIZE;
	mini_y = F_SIZE;
	player.x += mini_x;
	player.y += mini_y;

	dx = wall.x - game->player->pos.x;
	dy = wall.y - game->player->pos.y;
	if (fabs(dx) > fabs(dy))
		i = fabs(dx);
	else
		i = fabs(dy);
	dx /= i;
	dy /= i;
	while (i > 0)
	{
		if (player.x >= 0 && player.x < WIDTH && player.y >= 0 && player.y < HEIGHT)
		{
			mlx_put_pixel(game->window->image, (int)player.x, (int)player.y, BLACK);
		}
		player.x += dx;
		player.y += dy;
		i--;
	}
}

void	draw_minimap(t_game *game)
{
	int	i;

	draw_map(game);
	draw_player(game);
	i = 0;
	while (i < WIDTH)
	{
		draw_ray(game, game->player->pos, game->ray->hit[i]);
		i += 1;
	}
}
