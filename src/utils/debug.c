/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:59:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/11 20:31:45 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	debug_map(t_map *map)
{
	printf("Floor - R: %d G: %d B: %d\n", map->floor_color[0], map->floor_color[1], map->floor_color[2]);
	printf("Ceiling - R: %d G: %d B: %d\n", map->ceiling_color[0], map->ceiling_color[1], map->ceiling_color[2]);
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
	int y = 0;
	while (map->map[y] != NULL)
	{
		if (y < 10)
			printf("map_line[0%d]: %s\n", y, map->map[y]);
		else
			printf("map_line[%d]: %s\n", y, map->map[y]);
		y++;
	}
}
