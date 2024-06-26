/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:28:04 by mott              #+#    #+#             */
/*   Updated: 2024/06/26 16:35:03 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	texture_x_calculation(t_game *game, t_texture *tex, int x)
{
	double	scale_x;

	scale_x = (double)game->map->wall[game->ray->wall[x]]->width / F_SIZE;
	if (game->ray->wall[x] == EAST || game->ray->wall[x] == DOOR_EAST)
		tex->pos.x = scale_x * (game->ray->hit[x].y
				- (((int)game->ray->hit[x].y >> 5) << 5));
	else if (game->ray->wall[x] == NORTH || game->ray->wall[x] == DOOR_NORTH)
		tex->pos.x = scale_x * (game->ray->hit[x].x
				- (((int)game->ray->hit[x].x >> 5) << 5));
	else if (game->ray->wall[x] == WEST || game->ray->wall[x] == DOOR_WEST)
		tex->pos.x = scale_x * (F_SIZE - (game->ray->hit[x].y
					- (((int)game->ray->hit[x].y >> 5) << 5)));
	else if (game->ray->wall[x] == SOUTH || game->ray->wall[x] == DOOR_SOUTH)
		tex->pos.x = scale_x * (F_SIZE - (game->ray->hit[x].x
					- (((int)game->ray->hit[x].x >> 5) << 5)));
}

static void	texture_y_calculation(t_game *game, t_texture *tex, int x)
{
	tex->wall_height = F_SIZE * HEIGHT / game->ray->len[x];
	tex->y_scale = (double)game->map->wall[game->ray->wall[x]]->height
		/ tex->wall_height;
	tex->y_offset = 0.0;
	if (tex->wall_height > HEIGHT)
	{
		tex->y_offset = (tex->wall_height - HEIGHT) / 2.0;
		tex->wall_height = HEIGHT;
	}
	tex->pos.y = tex->y_offset * tex->y_scale;
	tex->wall_offset = (HEIGHT - tex->wall_height) >> 1;
}

static void	fisheye(t_game *game, double radian, int x)
{
	double	fish_radian;

	fish_radian = pi_overflow(radian - game->player->dir);
	game->ray->len[x] = game->ray->len[x] * cos(fish_radian);
}

// y_scale < 0 = texture_height < wall_height = scaling up
// y_scale > 0 = texture_height > wall_height = scaling down
void	draw_wall(t_game *game, double radian, int x)
{
	t_texture	tex;
	int			dir;
	int			y;
	int			i;

	fisheye(game, radian, x);
	texture_x_calculation(game, &tex, x);
	texture_y_calculation(game, &tex, x);
	dir = game->ray->wall[x];
	y = 0;
	while (y < tex.wall_height)
	{
		i = ((int)tex.pos.y * game->map->wall[dir]->width + (int)tex.pos.x) * 4;
		mlx_put_pixel(game->window->image, x, y + tex.wall_offset,
			get_rgba(game->map->wall[dir]->pixels[i + 0],
				game->map->wall[dir]->pixels[i + 1],
				game->map->wall[dir]->pixels[i + 2],
				game->map->wall[dir]->pixels[i + 3]));
		tex.pos.y += tex.y_scale;
		y++;
	}
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT >> 1)
				mlx_put_pixel(game->window->image, x, y, game->map->ceiling);
			else
				mlx_put_pixel(game->window->image, x, y, game->map->floor);
			x++;
		}
		y++;
	}
}
