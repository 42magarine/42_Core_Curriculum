/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:28:04 by mott              #+#    #+#             */
/*   Updated: 2024/06/22 18:53:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_coords texture_calculation(t_game *game, int x, int wall_height)
{
	t_ray		*ray;
	t_coords	tex;

	ray = game->ray;
	tex.x = (double)game->map->wall[ray->dir[x]]->width / F_SIZE;
	tex.y = (double)game->map->wall[ray->dir[x]]->height / wall_height;
	if (ray->dir[x] == EAST)
		tex.x *= ray->hit[x].y - (((int)ray->hit[x].y >> 6) << 6);
	else if (ray->dir[x] == NORTH)
		tex.x *= ray->hit[x].x - (((int)ray->hit[x].x >> 6) << 6);
	else if (ray->dir[x] == WEST)
		tex.x *= F_SIZE - (ray->hit[x].y - (((int)ray->hit[x].y >> 6) << 6));
	else if (ray->dir[x] == SOUTH)
		tex.x *= F_SIZE - (ray->hit[x].x - (((int)ray->hit[x].x >> 6) << 6));
	return (tex);
}

// y_step < 0 = texture_height < wall_height = scaling up
// y_step > 0 = texture_height > wall_height = scaling down
void	draw_wall(t_game *game, int x)
{
	t_coords	tex;
	int			wall_height;
	int			wall_offset;
	int			y;
	int			i;
	double		new_y;

	wall_height = F_SIZE * HEIGHT / game->ray->len[x];
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	wall_offset = (HEIGHT - wall_height) >> 1;
	tex = texture_calculation(game, x, wall_height);
	y = 0;
	new_y = 0;
	while (y < wall_height)
	{
		// i = ((int)tex.y * game->map->wall[game->ray->dir[x]]->width + (int)tex.x) * 4;
		i = ((int)new_y * game->map->wall[game->ray->dir[x]]->width + (int)tex.x) * 4;
		mlx_put_pixel(game->window->image, x, y + wall_offset,
				get_rgba(game->map->wall[game->ray->dir[x]]->pixels[i + 0],
				game->map->wall[game->ray->dir[x]]->pixels[i + 1],
				game->map->wall[game->ray->dir[x]]->pixels[i + 2],
				game->map->wall[game->ray->dir[x]]->pixels[i + 3]));
		new_y +=tex.y;
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
