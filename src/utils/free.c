/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:55:16 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/23 15:55:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	free_map(t_map *map)
{
	if (map->map)
		ft_free_strarray(map->map);
	free(map);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
}
