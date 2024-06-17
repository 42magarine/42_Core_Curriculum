/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:06 by mott              #+#    #+#             */
/*   Updated: 2024/06/17 17:59:58 by mott             ###   ########.fr       */
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
	while (pos.x >= 0 && pos.x / FIELD_SIZE < map.x && pos.y >= 0 && pos.y / FIELD_SIZE < map.y)
	{
		if (g_map[pos.y / FIELD_SIZE][pos.x / FIELD_SIZE] == '1')
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
		pos.y = (player->pos.y / FIELD_SIZE) * FIELD_SIZE - 1;
		pos.x = (player->pos.y - pos.y) / tan(radian) + player->pos.x;
		pos_add.y = -FIELD_SIZE;
		pos_add.x = FIELD_SIZE / tan(radian);
		pos = check_wall(map->pos, pos, pos_add);
	}
	else if (radian > M_PI && radian < 2 * M_PI) // down
	{
		pos.y = (player->pos.y / FIELD_SIZE) * FIELD_SIZE + FIELD_SIZE;
		pos.x = (player->pos.y - pos.y) / tan(radian) + player->pos.x;
		pos_add.y = FIELD_SIZE;
		pos_add.x = -FIELD_SIZE / tan(radian);
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
		pos.x = (player->pos.x / FIELD_SIZE) * FIELD_SIZE + FIELD_SIZE;
		pos.y = (player->pos.x - pos.x) * tan(radian) + player->pos.y;
		pos_add.x = FIELD_SIZE;
		pos_add.y = -FIELD_SIZE * tan(radian);
		pos = check_wall(map->pos, pos, pos_add);
	}
	else if (radian > PI_HALF && radian < PI_THREE_HALF) // left
	{
		pos.x = (player->pos.x / FIELD_SIZE) * FIELD_SIZE - 1;
		pos.y = (player->pos.x - pos.x) * tan(radian) + player->pos.y;
		pos_add.x = -FIELD_SIZE;
		pos_add.y = FIELD_SIZE * tan(radian);
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
	distance_h = sqrt(((player.x - horizontal.x) * (player.x - horizontal.x))
			+ ((player.y - horizontal.y) * (player.y - horizontal.y)));
	distance_v = sqrt(((player.x - vertical.x) * (player.x - vertical.x))
			+ ((player.y - vertical.y) * (player.y - vertical.y)));
	if (isnan(distance_h))
	// if (distance_h == 0 || isnan(distance_h))
		distance_h = 99999;
	if (isnan(distance_v))
	// if (distance_v == 0 || isnan(distance_v))
		distance_v = 99999;
	if (distance_h < distance_v)
	{
		draw_line(window, player, horizontal);
		return (distance_h);
	}
	else
	{
		draw_line(window, player, vertical);
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

	radian = player->dir - FOV / 2 * PI_ONE / 180;
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
