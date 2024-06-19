/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:31:03 by mott              #+#    #+#             */
/*   Updated: 2024/06/19 18:57:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	init_game(t_game *game)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	game->window = window;
	window->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (window->mlx == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	window->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (window->image == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	window->redraw = true;
	game->player->pos.x = game->player->pos.x * F_SIZE + F_SIZE / 2;
	game->player->pos.y = game->player->pos.y * F_SIZE + F_SIZE / 2;
}

void	loop_hook(void *param)
{
	t_game		*game;
	t_window	*window;
	static int	i = 0;

	game = (t_game *)param;
	window = game->window;
	if (window->redraw == true)
	{
		ray_caster(game);
		draw_game(game);
		draw_minimap(game);
		if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
			ft_error(game, mlx_strerror(mlx_errno));
		printf("new image %d\n", i++);
		window->redraw = false;
	}
	key_hook(game);
}
