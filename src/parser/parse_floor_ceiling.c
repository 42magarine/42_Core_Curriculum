/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:54:29 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/11 17:27:05 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"


static void	parse_rgb(t_game *game, char *line, int rgb[3])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && j < 3)
	{
		while (ft_isspace(line[i]) || line[i] == ',')
			i++;
		if (!ft_isdigit(line[i]))
			ft_error(game, "parse_rgb error - invalid chars");
		rgb[j] = ft_atoi(&line[i]);
		if (rgb[j] < 0 || rgb[j] > 255)
			ft_error(game, "parse_rgb error - invalid range(0 to 255)");
		while (ft_isdigit(line[i]))
			i++;
		j++;
	}
	while (ft_isspace(line[i]))
		i++;
	if (ft_strlen(&line[i]) > 0)
		ft_error(game, "parse_rgb error - line too long");
}

void	parse_floor_ceiling(t_game *game, char *line)
{
	int		i;
	int		rgb[3];

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
	{
		parse_rgb(game, line + 1, rgb);
		if (line[i] == 'F')
		{
			game->map->floor_color[0] = rgb[0];
			game->map->floor_color[1] = rgb[1];
			game->map->floor_color[2] = rgb[2];
		}
		if (line[i] == 'C')
		{
			game->map->ceiling_color[0] = rgb[0];
			game->map->ceiling_color[1] = rgb[1];
			game->map->ceiling_color[2] = rgb[2];
		}
	}
}
