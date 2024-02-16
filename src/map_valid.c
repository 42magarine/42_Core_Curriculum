/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:40:25 by mott              #+#    #+#             */
/*   Updated: 2024/02/16 21:00:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_map_rectangular(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_size->y)
	{
		if (so_strlen(game->map[y]) != game->map_size->x)
			so_exit("rectangular", game);
		y++;
	}
}

void	so_map_wall(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < game->map_size->x)
	{
		if (game->map[y][x] != '1')
			so_exit("wall", game);
		x++;
	}
	x = game->map_size->x - 1;
	while (++y < game->map_size->y - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][x] != '1')
			so_exit("wall", game);
	}
	x = 0;
	while (x < game->map_size->x)
	{
		if (game->map[y][x] != '1')
			so_exit("wall", game);
		x++;
	}
}

void	so_map_objects(t_game *game, char object)
{
	int	y;
	int	x;
	int	counter;

	counter = 0;
	y = 0;
	while (y < game->map_size->y)
	{
		x = 0;
		while (x < game->map_size->x)
		{
			if (game->map[y][x] == object)
				counter++;
			x++;
		}
		y++;
	}
	if (object == 'P' && counter != 1)
		so_exit("player", game);
	if (object == 'C' && counter < 1)
		so_exit("collectibles", game);
	if (object == 'E' && counter != 1)
		so_exit("exit", game);
}

// void	fill_zone(char **tab, t_xy size, t_xy current, char target)
// {
// 	if (current.x < 0 || current.y < 0 || current.x >= size.x || current.y >= size.y || tab[current.y][current.x] != target)
// 		return ;
// 	tab[current.y][current.x] = 'F';
// 	fill_zone(tab, size, (t_xy){current.x + 1, current.y}, target);
// 	fill_zone(tab, size, (t_xy){current.x - 1, current.y}, target);
// 	fill_zone(tab, size, (t_xy){current.x, current.y + 1}, target);
// 	fill_zone(tab, size, (t_xy){current.x, current.y - 1}, target);
// }

// void	flood_fill(char **tab, t_xy size, t_xy begin)
// {
// 	if (tab == 0 || size.x <= 0 || size.y <= 0 || begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y)
// 		return ;
// 	fill_zone(tab, size, begin, tab[begin.y][begin.x]);
// }
