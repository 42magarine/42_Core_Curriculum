/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:12:34 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/26 16:48:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	mouse_button_cb(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;

	(void)mods;
	game = (t_game *)param;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
		game->mouse_rotate = !game->mouse_rotate;
}

void	mouse_move_cb(double x, double y, void *param)
{
	t_game	*game;
	double	dx;
	char	dir;

	(void)y;
	game = (t_game *)param;
	if (!game->mouse_rotate)
	{
		dx = x - WIDTH / 2;
		if (dx < 0)
			dir = 'L';
		else
			dir = 'R';
		rotate_player(game, dir);
		mlx_set_mouse_pos(game->window->mlx, WIDTH / 2, HEIGHT / 2);
		game->recalculate = true;
	}
}

void	mouse_hook(t_game *game)
{
	mlx_mouse_hook(game->window->mlx, mouse_button_cb, game);
	mlx_cursor_hook(game->window->mlx, mouse_move_cb, game);
}
