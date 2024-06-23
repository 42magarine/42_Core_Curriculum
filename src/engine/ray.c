/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:06 by mott              #+#    #+#             */
/*   Updated: 2024/06/23 16:09:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// a² + b² = c²
static double	ray_length(t_game *game, t_coords ray_hit)
{
	double	ray_len;

	ray_len = (sqrt(pow(game->player->pos.x - ray_hit.x, 2)
				+ pow(game->player->pos.y - ray_hit.y, 2)));
	if (ray_len == 0 || isnan(ray_len))
		ray_len = INT64_MAX;
	return (ray_len);
}

static t_coords	check_wall(t_game *game, t_coords pos, t_coords add)
{
	while ((int)pos.x >> 6 >= 0 && (int)pos.x >> 6 < game->map->max.x
		&& (int)pos.y >> 6 >= 0 && (int)pos.y >> 6 < game->map->max.y)
	{
		if (game->map->map[(int)pos.y >> 6][(int)pos.x >> 6] == '1')
			break ;
		else
		{
			pos.x += add.x;
			pos.y += add.y;
		}
	}
	return (pos);
}

// 0		<	radian	<	ONE_PI	= up
// ONE_PI	<	radian	<	TWO_PI	= down
static t_coords	horizontal_line(t_game *game, double radian, int *ray_dir)
{
	t_coords	pos;
	t_coords	pos_add;

	if (radian > 0 && radian < ONE_PI)
	{
		pos.y = (((int)game->player->pos.y >> 6) << 6) - 1;
		pos.x = (game->player->pos.y - pos.y) / tan(radian)
			+ game->player->pos.x;
		pos_add.y = -F_SIZE;
		pos_add.x = F_SIZE / tan(radian);
		*ray_dir = NORTH;
		return (check_wall(game, pos, pos_add));
	}
	else if (radian > ONE_PI && radian < TWO_PI)
	{
		pos.y = (((int)game->player->pos.y >> 6) << 6) + F_SIZE;
		pos.x = (game->player->pos.y - pos.y) / tan(radian)
			+ game->player->pos.x;
		pos_add.y = F_SIZE;
		pos_add.x = -F_SIZE / tan(radian);
		*ray_dir = SOUTH;
		return (check_wall(game, pos, pos_add));
	}
	*ray_dir = NORTH;
	return ((t_coords){game->player->pos.x, game->player->pos.y});
}

// HALF_PI	>	radian	>	THREE_HALF_PI	= right
// HALF_PI	<	radian	<	THREE_HALF_PI	= left
static t_coords	vertical_line(t_game *game, double radian, int *ray_dir)
{
	t_coords	pos;
	t_coords	pos_add;

	if (radian < HALF_PI || radian > THREE_HALF_PI)
	{
		pos.x = (((int)game->player->pos.x >> 6) << 6) + F_SIZE;
		pos.y = (game->player->pos.x - pos.x) * tan(radian)
			+ game->player->pos.y;
		pos_add.x = F_SIZE;
		pos_add.y = -F_SIZE * tan(radian);
		*ray_dir = EAST;
		return (check_wall(game, pos, pos_add));
	}
	else if (radian > HALF_PI && radian < THREE_HALF_PI)
	{
		pos.x = (((int)game->player->pos.x >> 6) << 6) - 1;
		pos.y = (game->player->pos.x - pos.x) * tan(radian)
			+ game->player->pos.y;
		pos_add.x = -F_SIZE;
		pos_add.y = F_SIZE * tan(radian);
		*ray_dir = WEST;
		return (check_wall(game, pos, pos_add));
	}
	*ray_dir = EAST;
	return ((t_coords){game->player->pos.x, game->player->pos.y});
}

// tan (0°)		=  0
// tan (90°)	=  undefined
// tan (180°)	=  0
// tan (270°)	=  undefined
void	ray_calculation(t_game *game, double radian, int x)
{
	t_coords	ray_hit[2];
	double		ray_len[2];
	int			ray_dir[2];

	ray_hit[0] = horizontal_line(game, radian, &ray_dir[0]);
	ray_hit[1] = vertical_line(game, radian, &ray_dir[1]);
	ray_len[0] = ray_length(game, ray_hit[0]);
	ray_len[1] = ray_length(game, ray_hit[1]);
	if (ray_len[0] < ray_len[1])
	{
		game->ray->hit[x] = ray_hit[0];
		game->ray->len[x] = ray_len[0];
		game->ray->dir[x] = ray_dir[0];
	}
	else
	{
		game->ray->hit[x] = ray_hit[1];
		game->ray->len[x] = ray_len[1];
		game->ray->dir[x] = ray_dir[1];
	}
}
