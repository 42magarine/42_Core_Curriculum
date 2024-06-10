/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:37:56 by mott              #+#    #+#             */
/*   Updated: 2024/06/10 15:41:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/game.h"

char	*g_map[] =
{
	"1111111111111111",
	"1010000000100001",
	"1010000000100001",
	"1010000000100001",
	"1000000000000001",
	"1000010000000101",
	"1020000000000001",
	"1111111111111111",
};

// static int	ft_get_rgba(int r, int g, int b, int a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

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

static void ft_draw_map_2D(t_game *game)
{
	mlx_image_t	*zero;
	mlx_image_t	*one;
	// int			color_zero;
	// int			color_one;
	int			x;
	int			y;

	zero = mlx_new_image(game->window->mlx, game->map->field_size, game->map->field_size);
	if (zero == NULL)
		ft_exit(mlx_strerror(mlx_errno));
	one = mlx_new_image(game->window->mlx, game->map->field_size, game->map->field_size);
	if (one == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	ft_memset(zero->pixels, 0, zero->width * zero->height * sizeof(int));
	ft_memset(one->pixels, 255, zero->width * zero->height * sizeof(int));
	// color_zero = ft_get_rgba(34, 139, 34, 255); // forestgreen
	// color_one = ft_get_rgba(135, 206, 235, 255); // skyblue

	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (g_map[y][x] == '1')
			{
				if (mlx_image_to_window(game->window->mlx, one, x * game->map->field_size, y * game->map->field_size) == -1)
					ft_exit(mlx_strerror(mlx_errno));
			}
			else
				if (mlx_image_to_window(game->window->mlx, zero, x * game->map->field_size, y * game->map->field_size) == -1)
					ft_exit(mlx_strerror(mlx_errno));
			x++;
		}
		y++;
	}
}

static void	ft_draw_player(t_game *game)
{
	int	player_color;
	int	x;
	int	y;

	game->player->image = mlx_new_image(game->window->mlx, game->player->size, game->player->size);
	if (game->player->image == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	player_color = 0;
	if (game->player->direction == 'N')
		player_color = 128;
	else if (game->player->direction == 'S')
		player_color = 160;
	else if (game->player->direction == 'E')
		player_color = 192;
	else if (game->player->direction == 'W')
		player_color = 224;

	ft_memset(game->player->image->pixels, player_color, game->player->image->width * game->player->image->height * sizeof(int));

	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (g_map[y][x] == '2')
			{
				game->player->x =  x * game->map->field_size + (game->map->field_size - game->player->size) / 2;
				game->player->y =  y * game->map->field_size + (game->map->field_size - game->player->size) / 2;
				if (mlx_image_to_window(game->window->mlx, game->player->image, game->player->x, game->player->y) == -1)
					ft_exit(mlx_strerror(mlx_errno));
			}
			x++;
		}
		y++;
	}
}

// static int ft_wie_weit_ist_die_wand_weg()
// {
// 	int	wand_x;

// 	wand_x = player_x;

// 	printf("player_x: %d\n", player_x);
// 	printf("player_y: %d\n", player_y);
// 	printf("x: %d\n", player_x / field_size);
// 	printf("y: %d\n", player_y / field_size);

// 	while (true)
// 	{
// 		if (map[(player_y / field_size) * map_x + (wand_x / field_size)] == 1)
// 			break ;
// 		wand_x += player_size;
// 	}
// 	return (wand_x - player_x);
// }

// static void ft_draw_line(void *param)
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*line;
// 	int			x;
// 	int			y;
// 	int			wand_x;

// 	mlx = param;
// 	wand_x = ft_wie_weit_ist_die_wand_weg();

// 	printf("wand_x: %d\n", wand_x);

// 	line = mlx_new_image(mlx, wand_x, player_size);
// 	if (line == NULL)
// 		ft_exit(mlx_strerror(mlx_errno));

// 	y = 0;
// 	while (y < player_size)
// 	{
// 		x = 0;
// 		while (x < wand_x)
// 		{
// 			mlx_put_pixel(line, x, y, 255);
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (mlx_image_to_window(mlx, line, player_x, player_y) == -1)
// 		ft_exit(mlx_strerror(mlx_errno));
// }

int	init_mlx(t_game *game)
{
	// mlx_set_setting(MLX_MAXIMIZED, true);

	game->window->mlx = mlx_init(game->window->width, game->window->height, "cub3D", false);
	if (game->window->mlx == NULL)
		ft_exit(mlx_strerror(mlx_errno));

 	ft_draw_map_2D(game);
	ft_draw_player(game);
	// ft_draw_line(mlx);

	// mlx_key_hook(game->window->mlx, &ft_key_hook, game);
	mlx_loop_hook(game->window->mlx, &ft_key_hook, game);
	mlx_loop_hook(game->window->mlx, &ft_loop_hook, game);
	mlx_loop(game->window->mlx);

	mlx_terminate(game->window->mlx);
	return (EXIT_SUCCESS);
}
