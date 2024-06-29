/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:55:16 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/29 14:18:00 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	free_map(t_map *map)
{
	int	i;

	if (map->map)
		ft_free_strarray(map->map);
	i = 0;
	while (i < 4)
	{
		if (map->wall[i])
			mlx_delete_texture(map->wall[i]);
		i++;
	}
	i = 0;
	while (i < 40)
	{
		if (map->portal[i])
			mlx_delete_texture(map->portal[i]);
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
