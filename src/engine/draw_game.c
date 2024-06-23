/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:28:04 by mott              #+#    #+#             */
/*   Updated: 2024/06/23 14:55:56 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	texture_x_calculation(t_game *game, t_texture *tex, int x)
{
	double	scale_x;

	scale_x = (double)game->map->wall[game->ray->dir[x]]->width / F_SIZE;
	if (game->ray->dir[x] == EAST)
		tex->pos.x = scale_x * (game->ray->hit[x].y
				- (((int)game->ray->hit[x].y >> 6) << 6));
	else if (game->ray->dir[x] == NORTH)
		tex->pos.x = scale_x * (game->ray->hit[x].x
				- (((int)game->ray->hit[x].x >> 6) << 6));
	else if (game->ray->dir[x] == WEST)
		tex->pos.x = scale_x * (F_SIZE - (game->ray->hit[x].y
					- (((int)game->ray->hit[x].y >> 6) << 6)));
	else if (game->ray->dir[x] == SOUTH)
		tex->pos.x = scale_x * (F_SIZE - (game->ray->hit[x].x
					- (((int)game->ray->hit[x].x >> 6) << 6)));
}

static void	texture_y_calculation(t_game *game, t_texture *tex, int x)
{
	tex->wall_height = F_SIZE * HEIGHT / game->ray->len[x];
	tex->y_scale = (double)game->map->wall[game->ray->dir[x]]->height
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

// y_step < 0 = texture_height < wall_height = scaling up
// y_step > 0 = texture_height > wall_height = scaling down
void	draw_wall(t_game *game, int x)
{
	t_texture	tex;
	int			dir;
	int			y;
	int			i;

	texture_x_calculation(game, &tex, x);
	texture_y_calculation(game, &tex, x);
	dir = game->ray->dir[x];
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
