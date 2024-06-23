/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:55:16 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/23 17:31:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	free_map(t_map *map)
{
	int	i;

	if (map->map)
		ft_free_strarray(map->map);
	i = 0;
	while (i <= 3)
	{
		if (map->wall[i])
			mlx_delete_texture(map->wall[i]);
		i++;
	}
	free(map);
}

static void	free_window(t_window *window)
{
	if (window->image)
		mlx_delete_image(window->mlx, window->image);
	if (window->mlx)
		mlx_terminate(window->mlx);
	free(window);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
	if (game->parsed)
		free(game->parsed);
	if (game->window)
		free_window(game->window);
}
