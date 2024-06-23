/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:12:34 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/23 17:25:24 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	mouse_button_cb(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;

	(void)mods;
	game = (t_game *)param;

	mlx_get_mouse_pos(game->window->mlx, &game->mouse_x, &game->mouse_y);
	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		if (action == MLX_PRESS)
		{
			game->mouse_down = true;
			// mlx_get_mouse_pos(game->window->mlx, &game->mouse_x, &game->mouse_y);
		}
		else if (action == MLX_RELEASE)
			game->mouse_down = 0;
	}
}

void	mouse_move_cb(double x, double y, void *param)
{
	t_game	*game;
	double	delta_x;

	(void)y;
	game = (t_game *)param;
	if (game->mouse_down)
	{
		// mlx_get_mouse_pos(game->window->mlx, &game->mouse_x, &game->mouse_y);
		delta_x = x - game->mouse_x;
		if (delta_x < 0)
			game->player->dir += 0.1;
		else
			game->player->dir -= 0.1;
		if (game->player->dir < 0)
			game->player->dir += TWO_PI;
		else if (game->player->dir >= TWO_PI)
			game->player->dir -= TWO_PI;
		game->recalculate = true;
	}
}

void	mouse_hook(t_game *game)
{
	mlx_mouse_hook(game->window->mlx, mouse_button_cb, game);
	mlx_cursor_hook(game->window->mlx, mouse_move_cb, game);
}
