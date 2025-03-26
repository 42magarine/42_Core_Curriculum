/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:59:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/02 18:17:54 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/cub3D.h"

// static void	debug_player(t_map *map, t_player *player)
// {
// 	if (player->pos.x > 0 && player->pos.y > 0)
// 		printf("Player Pos	x:%f	y:%f\n", player->pos.x, player->pos.y);
// 	else
// 		printf("Player Pos missing\n");
// 	printf("Player Dir:%c\n", map->map[(int)player->pos.y][(int)player->pos.x]);
// }

// static void	debug_map(t_game *game, t_map *map)
// {
// 	int	y;

// 	printf("Floor   color: %d\n", map->floor);
// 	printf("Ceiling color: %d\n", map->ceiling);
// 	printf("\n");
// 	if (game->tex->wall[0] != NULL)
// 		printf("North wall texture loaded\n");
// 	if (game->tex->wall[1] != NULL)
// 		printf("East  wall texture loaded\n");
// 	if (game->tex->wall[2] != NULL)
// 		printf("South wall texture loaded\n");
// 	if (game->tex->wall[3] != NULL)
// 		printf("West  wall texture loaded\n");
// 	printf("\n");
// 	printf("Mapsize		X: %f	Y: %f\n", map->max.x, map->max.y);
// 	printf("\n");
// 	y = 0;
// 	while (y <= map->max.y)
// 	{
// 		if (y < 10)
// 			printf("map_line[0%d]: %s\n", y, map->map[y]);
// 		else
// 			printf("map_line[%d]: %s\n", y, map->map[y]);
// 		y++;
// 	}
// 	printf("Portal1		X:%f	Y:%f\n", map->portal[0].x, map->portal[0].y);
// 	printf("Portal2		X:%f	Y:%f\n", map->portal[1].x, map->portal[1].y);
// }

// void	debug_parse(t_game *game)
// {
// 	debug_map(game, game->map);
// 	debug_player(game->map, game->player);
// }
