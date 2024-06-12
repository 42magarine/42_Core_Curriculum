/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/06/12 21:39:31 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// static void ft_bottom(mlx_t *mlx)
// {
// 	mlx_image_t	*bottom;
// 	int			color;
// 	int			x;
// 	int			y;

// 	bottom = mlx_new_image(mlx, window->width, height / 2);
// 	if (bottom == NULL)
// 		ft_exit(mlx_strerror(mlx_errno));

// 	color = ft_get_rgba(34, 139, 34, 255); // forestgreen
// 	y = 0;
// 	while (y < height / 2)
// 	{
// 		x = 0;
// 		while (x < window->width)
// 		{
// 			mlx_put_pixel(bottom, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}

// 	if (mlx_image_to_window(mlx, bottom, 0, height / 2) == -1)
// 		ft_exit(mlx_strerror(mlx_errno));
// }

// static void ft_top(mlx_t *mlx)
// {
// 	mlx_image_t	*top;
// 	int			color;
// 	int			x;
// 	int			y;

// 	top = mlx_new_image(mlx, window->width, height / 2);
// 	if (top == NULL)
// 		ft_exit(mlx_strerror(mlx_errno));

// 	color = ft_get_rgba(135, 206, 235, 255); // skyblue
// 	y = 0;
// 	while (y < height / 2)
// 	{
// 		x = 0;
// 		while (x < window->width)
// 		{
// 			mlx_put_pixel(top, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}

// 	if (mlx_image_to_window(mlx, top, 0, 0) == -1)
// 		ft_exit(mlx_strerror(mlx_errno));
// }

// static int	test_mlx(void)
// {
// 	mlx_t			*mlx;
// 	mlx_texture_t	*texture;
// 	mlx_image_t		*img;

// 	mlx = mlx_init(width, height, "cub3D", true);
// 	if (mlx == NULL)
// 		ft_exit(mlx_strerror(mlx_errno));

// 	ft_bottom(mlx);
// 	ft_top(mlx);

// 	texture = mlx_load_png("./textures/north.png");
// 	if (texture == NULL)
// 		ft_exit(mlx_strerror(mlx_errno));

// 	img = mlx_texture_to_image(mlx, texture);
// 	if (img == NULL)
// 		ft_exit(mlx_strerror(mlx_errno));

// 	mlx_resize_image(img, 128, 128);

// 	if (mlx_image_to_window(mlx, img, 128, 192) == -1)
// 		ft_exit(mlx_strerror(mlx_errno));
// 	if (mlx_image_to_window(mlx, img, 256, 192) == -1)
// 		ft_exit(mlx_strerror(mlx_errno));

// 	mlx_delete_image(mlx, img);
// 	mlx_delete_texture(texture);
// }

void	ft_draw_square(t_game *game, int map_x, int map_y, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_pixel(game->window->image, map_x + x, map_y + y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_map_2D(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (g_map[y][x] == '1')
				ft_draw_square(game, x * 64, y * 64, 64, ft_get_rgba(255, 0, 0, 255));
			else
				ft_draw_square(game, x * 64, y * 64, 64, ft_get_rgba(0, 255, 0, 255));
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_game *game)
{
	ft_draw_square(game, game->player->x, game->player->y, 8, ft_get_rgba(0, 0, 255, 255));
}

void	ft_draw_line(t_game *game, int rx, int ry)
{
	int	px;
	int	py;
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	px = game->player->x + 4;
	py = game->player->y + 4;
	dx = abs(rx - px);
	dy = abs(ry - py);
	sx = px < rx ? 1 : -1;
	sy = py < ry ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;

	while (true)
	{
		mlx_put_pixel(game->window->image, px, py, 255);
		if (px == rx && py == ry)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			px += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			py += sy;
		}
	}
}
