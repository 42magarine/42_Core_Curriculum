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

static void	parse_rgb(t_game *game, char *line, int rgb[3])
{
	int		i;
	int		j;
	int		value;

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
	if (ft_strlen(&line[i]) > 0)
		ft_error(game, "parse_rgb error - line too long");
}

void	parse_bot_top_rgb(t_game *game, char *line)
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
			game->map->bot_rgb[0] = rgb[0];
			game->map->bot_rgb[1] = rgb[1];
			game->map->bot_rgb[2] = rgb[2];
		}
		if (line[i] == 'C')
		{
			game->map->top_rgb[0] = rgb[0];
			game->map->top_rgb[1] = rgb[1];
			game->map->top_rgb[2] = rgb[2];
		}
	}
}
