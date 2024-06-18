/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:27:53 by mott              #+#    #+#             */
/*   Updated: 2024/06/18 18:18:24 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_mlx(t_game *game)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	game->window = window;
	window->width = 1024;
	window->height = 512;
	window->mlx = mlx_init(window->width, window->height, "cub3D", false);
	if (window->mlx == NULL)
		ft_exit(mlx_strerror(mlx_errno));
	window->image = mlx_new_image(window->mlx, window->width, window->height);
	if (window->image == NULL)
		ft_exit(mlx_strerror(mlx_errno));
}
