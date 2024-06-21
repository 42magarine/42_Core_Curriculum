/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:59:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/21 19:43:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	debug_player(t_player *player)
{
	// printf("Player Pos	X: %d	Y: %d\n", player->pos.x, player->pos.y);
	printf("Player Pos	X: %f	Y: %f\n", player->pos.x, player->pos.y);
	printf("Player Dir	%f\n", player->dir);
}

void	debug_map(t_map *map)
{
	// printf("bot_rgb - R: %d G: %d B: %d\n", map->bot_rgb[0], map->bot_rgb[1], map->bot_rgb[2]);
	// printf("top - R: %d G: %d B: %d\n", map->top_rgb[0], map->top_rgb[1], map->top_rgb[2]);
	printf("\n");
	if (map->walls[0] != NULL)
		printf("North wall texture loaded\n");
	if (map->walls[1] != NULL)
		printf("East  wall texture loaded\n");
	if (map->walls[2] != NULL)
		printf("South wall texture loaded\n");
	if (map->walls[3] != NULL)
		printf("West  wall texture loaded\n");
	printf("\n");
	// printf("Mapsize		X: %d	Y: %d\n", map->max.x, map->max.y);
	printf("Mapsize		X: %f	Y: %f\n", map->max.x, map->max.y);
	printf("\n");
	int y = 0;
	while (y <= map->max.y)
	{
		if (y < 10)
			printf("map_line[0%d]: %s\n", y, map->map[y]);
		else
			printf("map_line[%d]: %s\n", y, map->map[y]);
		y++;
	}
	printf("Valid map: %d\n", map->valid);
}
