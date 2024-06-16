/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:06 by mott              #+#    #+#             */
/*   Updated: 2024/06/16 19:05:24 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// static int	ft_math(t_game *game)
// {
// 	double	g_kathete;
// 	double	a_kathete;
// 	double	fov;

// 	g_kathete = game->window->width / 2;
// 	fov = game->player->fov * M_PI / 180;

// 	a_kathete = g_kathete / tan(fov / 2);
// 	return (a_kathete);
// 	// printf("Ankathete: %f\n", a_kathete);
// }

static t_point	check_wall(t_point map, t_point pos, t_point pos_add)
{
	while (pos.x >= 0 && pos.x / 64 < map.x && pos.y >= 0 && pos.y / 64 < map.y)
	{
		if (g_map[pos.y / 64][pos.x / 64] == '1')
			break ;
		else
		{
			pos.x += pos_add.x;
			pos.y += pos_add.y;
		}
	}
	return (pos);
}

static t_point	horizontal_line(t_map *map, t_player *player, double radian)
{
	t_point	pos;
	t_point	pos_add;

	if (radian > 0 && radian < PI_ONE) // up
	{
		pos.y = (player->pos.y / 64) * 64 - 1;
		pos.x = (player->pos.y - pos.y) / tan(radian) + player->pos.x;
		pos_add.y = -64;
		pos_add.x = 64 / tan(radian);
		pos = check_wall(map->pos, pos, pos_add);
	}
	else if (radian > M_PI && radian < 2 * M_PI) // down
	{
		pos.y = (player->pos.y / 64) * 64 + 64;
		pos.x = (player->pos.y - pos.y) / tan(radian) + player->pos.x;
		pos_add.y = 64;
		pos_add.x = -64 / tan(radian);
		pos = check_wall(map->pos, pos, pos_add);
	}
	else // left and right
	{
		pos.x = player->pos.x;
		pos.y = player->pos.y;
	}
	return (pos);
}

static t_point	vertical_line(t_map *map, t_player *player, double radian)
{
	t_point	pos;
	t_point	pos_add;

	if (radian < PI_HALF || radian > PI_THREE_HALF) // right
	{
		pos.x = (player->pos.x / 64) * 64 + 64;
		pos.y = (player->pos.x - pos.x) * tan(radian) + player->pos.y;
		pos_add.x = 64;
		pos_add.y = -64 * tan(radian);
		pos = check_wall(map->pos, pos, pos_add);
	}
	else if (radian > PI_HALF && radian < PI_THREE_HALF) // left
	{
		pos.x = (player->pos.x / 64) * 64 - 1;
		pos.y = (player->pos.x - pos.x) * tan(radian) + player->pos.y;
		pos_add.x = -64;
		pos_add.y = 64 * tan(radian);
		pos = check_wall(map->pos, pos, pos_add);
	}
	else // up and down
	{
		pos.x = player->pos.x;
		pos.y = player->pos.y;
	}
	return (pos);
}

static int	wall_distance(t_window *window, t_point player, t_point horizontal, t_point vertical)
{
	double	distance_h;
	double	distance_v;

	(void)window;
	distance_h = sqrt((player.x - horizontal.x) * (player.x - horizontal.x)
		+ (player.y - horizontal.y) * (player.y - horizontal.y));
	if (distance_h == 0)
		distance_h = MAXFLOAT;

	distance_v = sqrt((player.x - vertical.x) * (player.x - vertical.x)
		+ (player.y - vertical.y) * (player.y - vertical.y));
	if (distance_v == 0)
		distance_v = MAXFLOAT;

	if (distance_h < distance_v)
	{
		// draw_line(window, player, horizontal);
		return (distance_h);
	}
	else
	{
		// draw_line(window, player, vertical);
		return (distance_v);
	}
}

void	ray_caster(t_window *window, t_map *map, t_player *player)
{
	double	radian;
	double	radian_add;
	t_point	horizontal;
	t_point	vertical;
	double	shortest;
	int		i;

	radian = player->dir + FOV / 2 * PI_ONE / 180;
	radian_add = FOV / window->width * PI_ONE / 180;
	i = 0;
	while (i < window->width)
	{
		if (radian < 0)
			radian += PI_TWO;
		else if (radian >= PI_TWO)
			radian -= PI_TWO;

		horizontal = horizontal_line(map, player, radian);
		vertical = vertical_line(map, player, radian);
		shortest = wall_distance(window, player->pos, horizontal, vertical);

		radian += radian_add;
		i++;
	}
}
