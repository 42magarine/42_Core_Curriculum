/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:21:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/18 14:14:55 by mott             ###   ########.fr       */
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

void	ft_error(t_game *game, const char *errormsg)
{
	printf("Error\n");
	printf("%s\n", errormsg);
	free_all(game);
	exit(EXIT_FAILURE);
}
