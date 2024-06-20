/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:59:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/19 18:44:22 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	debug_player(t_player *player)
{
	printf("Player Pos	X: %d	Y: %d\n", player->pos.x, player->pos.y);
	printf("Player Dir	%f\n", player->dir);
}

void	debug_map(t_map *map)
{
	printf("Floor   color: %d\n", map->floor);
	printf("Ceiling color: %d\n", map->ceiling);
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
	printf("Mapsize		X: %d	Y: %d\n", map->max.x, map->max.y);
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
}
