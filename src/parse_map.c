/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/09 18:23:10 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	parse_map(t_map *map, char *line)
{
	static int	i = 0;

	if (line[0] == '1' || line[0] == ' ')
	{
		map->map[i] = ft_strdup(line);
	}
}

static void	parse_floor_ceiling(t_map *map, char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (line[0] == 'F')
	{
		while (line[i] != NULL && j < 3)
		{
			while (!ft_isdigit(line[i]))
				i++;
			map->floor_color[j] = ft_atoi(&line[i]);
			j++;
		}
	}
	else if (line[0] == 'C')
	{
		while (line[i] != NULL && j < 3)
		{
			while (!ft_isdigit(line[i]))
				i++;
			map->ceiling_color[j] = ft_atoi(&line[i]);
			j++;
		}
	}
}

static void	parse_textures(t_map *map, char	*line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		map->n_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		map->e_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		map->s_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		map->w_texture = ft_strdup(line + 3);
}

t_map	*parse_mapfile(char	*filename)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = ft_calloc(1, sizeof(t_map));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error();
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		parse_textures(map, line);
		parse_floor_ceiling(map, line);
		parse_map(map, line);
		free(line);
	}
	close(fd);
	return(map);
}
