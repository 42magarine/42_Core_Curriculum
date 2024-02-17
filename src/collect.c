/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:38:33 by mott              #+#    #+#             */
/*   Updated: 2024/02/17 20:04:27 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_create_cmap(t_game *game)
{
	int	y;
	int	x;

	game->cmap = malloc(sizeof(int *) * (game->map_size.y + 1));
	// if (map == NULL)
	// 	so_exit("malloc\n", NULL); // free?
	y = 0;
	while (y < game->map_size.y)
	{
		game->cmap[y] = malloc(sizeof(int) * game->map_size.x);
		// if (ff_map[y] == NULL)
		// 	so_exit("malloc\n", NULL); // free?
		x = 0;
		while (x < game->map_size.x)
		{
			game->cmap[y][x] = -1;
			x++;
		}
		y++;
	}
	game->cmap[y] = NULL;
}
