/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:55:16 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/01 15:29:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	free_texture(t_texture *tex)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (tex->wall[i])
			mlx_delete_texture(tex->wall[i]);
		i++;
	}
	i = 0;
	while (i < 40)
	{
		if (tex->portal[i])
			mlx_delete_texture(tex->portal[i]);
		i++;
	}
	free(tex);
}

static void	free_map(t_map *map)
{
	if (map->map)
		ft_free_strarray(map->map);
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
	if (game->window)
		free_window(game->window);
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
	if (game->ray)
		free(game->ray);
	if (game->tex)
		free_texture(game->tex);
	if (game->minimap)
		free(game->minimap);
	if (game->parsed)
		free(game->parsed);
	free(game);
}
