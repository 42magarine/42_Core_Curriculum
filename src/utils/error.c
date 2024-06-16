/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:21:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/11 21:24:05 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	free_map(t_map *map)
{
	if (map->map)
		ft_free_strarray(map->map);
	free(map);
}

void	free_all(t_game	*game)
{
	if (game->map)
		free_map(game->map);
}

void	ft_error(t_game *game, char *errormsg)
{
	free_all(game);
	printf("error\n");
	exit(EXIT_FAILURE);
}
