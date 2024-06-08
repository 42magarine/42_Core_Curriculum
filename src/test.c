/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:35:47 by mott              #+#    #+#             */
/*   Updated: 2024/06/08 19:32:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	map[]=
{
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,
 1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};
// map as int array or as array of strings?

int			width = 1024;
int			height = 512;
int			map_x = 16;
int			map_y = 8;
int			field_size = 64;
int			player_size = 8;
char		player_direction = 'S';
int			player_x = 0;
int			player_y = 0;
mlx_image_t	*player;

static int	ft_exit(const char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

// static int	ft_get_rgba(int r, int g, int b, int a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

static void ft_draw_map_2D(mlx_t *mlx)
{
	mlx_image_t	*zero;
	mlx_image_t	*one;
	// int			color_zero;
	// int			color_one;
	int			x;
	int			y;

	zero = mlx_new_image(mlx, field_size, field_size);
	if (zero == NULL)
		ft_exit(mlx_strerror(mlx_errno));
	one = mlx_new_image(mlx, field_size, field_size);
	if (one == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	ft_memset(zero->pixels, 0, zero->width * zero->height * sizeof(int));
	ft_memset(one->pixels, 255, zero->width * zero->height * sizeof(int));
	// color_zero = ft_get_rgba(34, 139, 34, 255); // forestgreen
	// color_one = ft_get_rgba(135, 206, 235, 255); // skyblue

	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			if (map[y * map_x + x] == 1)
			{
				if (mlx_image_to_window(mlx, one, x * field_size, y * field_size) == -1)
					ft_exit(mlx_strerror(mlx_errno));
			}
			else
				if (mlx_image_to_window(mlx, zero, x * field_size, y * field_size) == -1)
					ft_exit(mlx_strerror(mlx_errno));
			x++;
		}
		y++;
	}
}

static void	ft_draw_player(mlx_t *mlx)
{
	// mlx_image_t	*player;
	int			player_color;
	int			x;
	int			y;

	player = mlx_new_image(mlx, player_size, player_size);
	if (player == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	player_color = 0;
	if (player_direction == 'N')
		player_color = 128;
	else if (player_direction == 'S')
		player_color = 160;
	else if (player_direction == 'E')
		player_color = 192;
	else if (player_direction == 'W')
		player_color = 224;

	ft_memset(player->pixels, player_color, player->width * player->height * sizeof(int));

	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			if (map[y * map_x + x] == 2)
			{
				player_x =  x * field_size + (field_size - player_size) / 2;
				player_y =  y * field_size + (field_size - player_size) / 2;
				if (mlx_image_to_window(mlx, player, player_x, player_y) == -1)
					ft_exit(mlx_strerror(mlx_errno));
			}
			x++;
		}
		y++;
	}
}

static int ft_wie_weit_ist_die_wand_weg()
{
	int	wand_x;

	wand_x = player_x;

	printf("player_x: %d\n", player_x);
	printf("player_y: %d\n", player_y);
	printf("x: %d\n", player_x / field_size);
	printf("y: %d\n", player_y / field_size);

	while (true)
	{
		if (map[(player_y / field_size) * map_x + (wand_x / field_size)] == 1)
			break ;
		wand_x += player_size;
	}
	return (wand_x - player_x);
}

static void ft_draw_line(void *param)
{
	mlx_t		*mlx;
	mlx_image_t	*line;
	int			x;
	int			y;
	int			wand_x;

	mlx = param;
	wand_x = ft_wie_weit_ist_die_wand_weg();

	printf("wand_x: %d\n", wand_x);

	line = mlx_new_image(mlx, wand_x, player_size);
	if (line == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	y = 0;
	while (y < player_size)
	{
		x = 0;
		while (x < wand_x)
		{
			mlx_put_pixel(line, x, y, 255);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(mlx, line, player_x, player_y) == -1)
		ft_exit(mlx_strerror(mlx_errno));
}

static void	ft_move_player(mlx_t *mlx, int x, int y)
{
	player->instances[0].x += x;
	player->instances[0].y += y;
	player_x +=x;
	player_y +=y;
}

static void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);

	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		printf("left\n");
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		printf("right\n");

	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_player(mlx, 0, -player_size);
	if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_player(mlx, -player_size, 0);
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_player(mlx, 0, player_size);
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move_player(mlx, player_size, 0);
}

static int	init_mlx(void)
{
	mlx_t	*mlx;

	// mlx_set_setting(MLX_MAXIMIZED, true);

	mlx = mlx_init(width, height, "cub3D", false); // true?
	if (mlx == NULL)
		ft_exit(mlx_strerror(mlx_errno));

 	ft_draw_map_2D(mlx);
	ft_draw_player(mlx);
	// ft_draw_line(mlx);

	mlx_key_hook(mlx, &ft_key_hook, mlx);
	// or mlx_loop_hook() with mlx_is_key_down()

	// mlx_loop_hook(mlx, &ft_draw_line, mlx);

	mlx_loop(mlx);

	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}


int	main(void)
{
	init_mlx();
	return (EXIT_SUCCESS);
}
