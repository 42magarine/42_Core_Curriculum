/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:59:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/10 19:52:52 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	debug_map(t_map *map)
{
	// printf("North Texture: %s\n", map->n_tex);
	// printf("East  Texture: %s\n", map->e_tex);
	// printf("South Texture: %s\n", map->s_tex);
	// printf("West  Texture: %s\n", map->w_tex);
	printf("Floor - R: %d G: %d B: %d\n", map->floor_color[0], map->floor_color[1], map->floor_color[2]);
	printf("Ceiling - R: %d G: %d B: %d\n", map->ceiling_color[0], map->ceiling_color[1], map->ceiling_color[2]);
	printf("\n");
	int y = 0;
	while (map->map[y] != NULL)
	{
		printf("%s\n", map->map[y]);
		y++;
	}
}
