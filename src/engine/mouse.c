/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:12:34 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/01 16:05:59 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	mouse_button_cb(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_game	*game;

	(void)mods;
	game = param;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
		game->window->mouse_rotate = !game->window->mouse_rotate;
}

static void	mouse_move_cb(double xpos, double ypos, void *param)
{
	t_game	*game;
	float	dx;
	char	dir;

	(void)ypos;
	game = param;
	if (!game->window->mouse_rotate)
	{
		dx = xpos - (WIDTH >> 1);
		if (dx < 0)
			dir = 'L';
		else
			dir = 'R';
		rotate_player(game, dir);
		mlx_set_mouse_pos(game->window->mlx, WIDTH >> 1, HEIGHT >> 1);
	}
}

void	mouse_hook(t_game *game)
{
	mlx_mouse_hook(game->window->mlx, &mouse_button_cb, game);
	mlx_cursor_hook(game->window->mlx, &mouse_move_cb, game);
}
