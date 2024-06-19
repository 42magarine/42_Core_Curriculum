/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:06 by mott              #+#    #+#             */
/*   Updated: 2024/06/19 19:39:52 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_coords	check_wall(t_game *game, t_coords pos, t_coords pos_add)
{
	t_coords	map;

	map = game->map->max;
	while (pos.x >= 0 && pos.x >> 6 < map.x && pos.y >= 0 && pos.y >> 6 < map.y)
	{
		if (game->map->map[pos.y >> 6][pos.x >> 6] == '1')
			break ;
		else
		{
			pos.x += pos_add.x;
			pos.y += pos_add.y;
		}
	}
	return (pos);
}

// 0 < radian < ONE_PI = up
// ONE_PI < radian < TWO_PI = down
// 0 or TWO_PI = right
// ONE_PI = left
static t_coords	horizontal_line(t_game *game, double radian)
{
	t_coords	pos;
	t_coords	pos_add;

	if (radian > 0 && radian < ONE_PI)
	{
		pos.y = ((game->player->pos.y >> 6) << 6) - 1;
		pos.x = (game->player->pos.y - pos.y) / tan(radian)
			+ game->player->pos.x;
		pos_add.y = -F_SIZE;
		pos_add.x = F_SIZE / tan(radian);
		return (check_wall(game, pos, pos_add));
	}
	else if (radian > ONE_PI && radian < TWO_PI)
	{
		pos.y = ((game->player->pos.y >> 6) << 6) + F_SIZE;
		pos.x = (game->player->pos.y - pos.y) / tan(radian)
			+ game->player->pos.x;
		pos_add.y = F_SIZE;
		pos_add.x = -F_SIZE / tan(radian);
		return (check_wall(game, pos, pos_add));
	}
	return ((t_coords){game->player->pos.x, game->player->pos.y});
}

// radian < HALF_PI or radian > THREE_HALF_PI = right
// HALF_PI < radian < THREE_HALF_PI	= left
// HALF_PI = up
// THREE_HALF_PI = down
static t_coords	vertical_line(t_game *game, double radian)
{
	t_coords	pos;
	t_coords	pos_add;

	if (radian < HALF_PI || radian > THREE_HALF_PI)
	{
		pos.x = ((game->player->pos.x >> 6) << 6) + F_SIZE;
		pos.y = (game->player->pos.x - pos.x) * tan(radian)
			+ game->player->pos.y;
		pos_add.x = F_SIZE;
		pos_add.y = -F_SIZE * tan(radian);
		return (check_wall(game, pos, pos_add));
	}
	else if (radian > HALF_PI && radian < THREE_HALF_PI)
	{
		pos.x = ((game->player->pos.x >> 6) << 6) - 1;
		pos.y = (game->player->pos.x - pos.x) * tan(radian)
			+ game->player->pos.y;
		pos_add.x = -F_SIZE;
		pos_add.y = F_SIZE * tan(radian);
		return (check_wall(game, pos, pos_add));
	}
	return ((t_coords){game->player->pos.x, game->player->pos.y});
}

static double	shortest_distance(t_game *game, double radian, int i)
{
	t_coords	point_h;
	t_coords	point_v;
	double		line_h;
	double		line_v;

	point_h = horizontal_line(game, radian);
	point_v = vertical_line(game, radian);
	line_h = sqrt(pow(game->player->pos.x - point_h.x, 2)
			+ pow(game->player->pos.y - point_h.y, 2));
	line_v = sqrt(pow(game->player->pos.x - point_v.x, 2)
			+ pow(game->player->pos.y - point_v.y, 2));
	if (line_h == 0 || isnan(line_h))
		line_h = INT64_MAX;
	if (line_v == 0 || isnan(line_v))
		line_v = INT64_MAX;
	if (line_h < line_v)
	{
		game->map->wall[i] = point_h;
		return (line_h);
	}
	else
	{
		game->map->wall[i] = point_v;
		return (line_v);
	}
}

void	ray_caster(t_game *game)
{
	double		line;
	double		radian;
	double		radian_add;
	int			i;

	radian = game->player->dir + FOV / 2 * ONE_PI / 180;
	radian_add = FOV / WIDTH * ONE_PI / 180;
	i = 0;
	while (i < WIDTH)
	{
		if (game->player->radian < 0)
			game->player->radian += TWO_PI;
		else if (game->player->radian >= TWO_PI)
			game->player->radian -= TWO_PI;
		line = shortest_distance(game, radian, i);
		radian -= radian_add;
		i++;
	}
}
