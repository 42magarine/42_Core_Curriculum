/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/10 19:47:20 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	parse_map(t_map *map, char *line)
{
	static int	i = 0;

	if (line[0] == '1' || line[0] == ' ')
	{
		map->map[i] = ft_strdup(line);
		i++;
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
static mlx_texture_t	*set_tex(char *line)
{
	char			*filepath;
	mlx_texture_t	*texture;
	int		i;

	i = 0;
	while (line[i] != NULL)
	{
		if (ft_isspace(line[i]))
			i++;
		else if (line[i] == '.')
			break ;
		else
			ft_error();
	}
	filepath = ft_strdup(line + i);
	texture = mlx_load_png(filepath);
	free(filepath);
	return (texture);
}

static void	parse_textures(t_map *map, char	*line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		map->walls[0] = set_tex(&line[i + 2]);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		map->walls[1] = set_tex(&line[i + 2]);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		map->walls[2] = set_tex(&line[i + 2]);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		map->walls[3] = set_tex(&line[i + 2]);
}

t_map	*parse_mapfile(char	*filename)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = ft_calloc(1, sizeof(t_map));
	map->map = ft_calloc(15, sizeof(char *)); //calc x/y max beforehand
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
