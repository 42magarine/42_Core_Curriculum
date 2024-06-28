/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bot_top_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:54:29 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/12 18:13:49 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	parse_rgb(t_game *game, char *line, u_int8_t rgb[3])
{
	int	i;
	int	j;
	int	value;

	i = 0;
	j = 0;
	while (line[i] != '\0' && j < 3)
	{
		while (ft_isspace(line[i]) || line[i] == ',')
			i++;
		if (!ft_isdigit(line[i]))
			ft_error(game, "parse_rgb error - invalid chars");
		value = ft_atoi(&line[i]);
		if (value < 0 || value > 255)
			ft_error(game, "parse_rgb error - invalid range(uint8_t)");
		else
			rgb[j] = value;
		while (ft_isdigit(line[i]))
			i++;
		j++;
	}
	while (ft_isspace(line[i]))
		i++;
	if (j < 3)
		ft_error(game, "parse_floor_ceiling - incorrect rgb values");
	if (ft_strlen(&line[i]) > 0)
		ft_error(game, "parse_rgb error - line too long");
}

void	parse_floor_ceiling(t_game *game, char *line)
{
	int			i;
	t_map		*map;
	uint8_t		rgb[3];

	map = game->map;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
	{
		parse_rgb(game, line + i + 1, rgb);
		if (line[i] == 'F')
			map->floor = get_rgba(rgb[0], rgb[1], rgb[2], 255);
		if (line[i] == 'C')
			map->ceiling = get_rgba(rgb[0], rgb[1], rgb[2], 255);
	}
	if (map->floor && map->ceiling)
		game->parsed->floor_ceiling = true;
}

void	parse_tex(t_game *game, char *line)
{
	t_map	*map;
	int		i;

	map = game->map;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		map->wall[0] = set_texture(game, &line[i + 2]);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		map->wall[1] = set_texture(game, &line[i + 2]);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		map->wall[2] = set_texture(game, &line[i + 2]);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		map->wall[3] = set_texture(game, &line[i + 2]);
	if (map->wall[0] && map->wall[1] && map->wall[2] && map->wall[3])
		game->parsed->walls = true;
}
