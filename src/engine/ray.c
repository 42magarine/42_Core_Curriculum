/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:06 by mott              #+#    #+#             */
/*   Updated: 2024/06/18 22:18:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_coords	check_wall(t_game *game, t_coords pos, t_coords pos_add)
{
	int	x;
	int	y;

	x = pos.x >> 6;
	y = pos.y >> 6;
	while (x >= 0 && x < game->map->max.x && y >= 0 && y < game->map->max.y)
	{
		if (game->map->map[y][x] == '1')
			break ;
		else
		{
			x += pos_add.x >> 6;
			y += pos_add.y >> 6;
		}
	}
	return ((t_coords){x, y});
}

static t_coords	horizontal_line(t_game *game, double radian)
{
	t_coords	pos;
	t_coords	pos_add;

	if (radian > 0 && radian < ONE_PI) // up
	{
		pos.y = ((game->player->pos.y >> 6) << 6) - 1;
		pos.x = (game->player->pos.y - pos.y) / tan(radian) + game->player->pos.x;
		pos_add.y = -F_SIZE;
		pos_add.x = F_SIZE / tan(radian);
		return (check_wall(game, pos, pos_add));
	}
	else if (radian > M_PI && radian < 2 * M_PI) // down
	{
		pos.y = ((game->player->pos.y >> 6) << 6) + F_SIZE;
		pos.x = (game->player->pos.y - pos.y) / tan(radian) + game->player->pos.x;
		pos_add.y = F_SIZE;
		pos_add.x = -F_SIZE / tan(radian);
		return (check_wall(game, pos, pos_add));
	}
	return ((t_coords){game->player->pos.x, game->player->pos.y});
}

static t_coords	vertical_line(t_game *game, double radian)
{
	t_coords	pos;
	t_coords	pos_add;

	if (radian < HALF_PI || radian > THREE_HALF_PI) // right
	{
		pos.x = ((game->player->pos.x >> 6) << 6) + F_SIZE;
		pos.y = (game->player->pos.x - pos.x) * tan(radian) + game->player->pos.y;
		pos_add.x = F_SIZE;
		pos_add.y = -F_SIZE * tan(radian);
		return (check_wall(game, pos, pos_add));
	}
	else if (radian > HALF_PI && radian < THREE_HALF_PI) // left
	{
		pos.x = ((game->player->pos.x >> 6) << 6) - 1;
		pos.y = (game->player->pos.x - pos.x) * tan(radian) + game->player->pos.y;
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
	line_h = sqrt((game->player->pos.x - point_h.x) * (game->player->pos.x - point_h.x)
		+ (game->player->pos.y - point_h.y) * (game->player->pos.y - point_h.y));
	if (line_h == 0 || isnan(line_h))
		line_h = INT64_MAX;
	line_v = sqrt((game->player->pos.x - point_v.x) * (game->player->pos.x - point_v.x)
		+ (game->player->pos.y - point_v.y) * (game->player->pos.y - point_v.y));
	if (line_v == 0 || isnan(line_v))
		line_v = INT64_MAX;
	if (line_h < line_v)
	{
		game->map->wall[i] = point_h;
		printf("(h) i:%d x:%d y:%d\n", i, game->map->wall[i].x, game->map->wall[i].y);
		return (line_h);
	}
	else
	{
		game->map->wall[i] = point_v;
		printf("(v) i:%d x:%d y:%d\n", i, game->map->wall[i].x, game->map->wall[i].y);
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
