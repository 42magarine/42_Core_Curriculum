/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/10 20:22:03 by fwahl            ###   ########.fr       */
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

static bool	parse_floor_ceiling(t_map *map, char *line)
{
	int		i;
	int		j;
	bool	parsed;

	parsed = false;
	i = 0;
	j = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'F')
	{
		i++;
		parsed = true;
		while (line[i] != '\0' && j < 3)
		{
			while (ft_isspace(line[i]) || line[i] == ',')
				i++;
			if (!ft_isdigit(line[i]))
				ft_error();
			map->floor_color[j] = ft_atoi(&line[i]);
			j++;
		}
		while (ft_isspace(line[i]) || line[i] == ',')
			i++;
		if (line[i] != '\0')
			ft_error();
	}
	if (line[i] == 'C')
	{
		i++;
		parsed = true;
		while (line[i] != '\0' && j < 3)
		{
			while (ft_isspace(line[i]) || line[i] == ',')
				i++;
			if (!ft_isdigit(line[i]))
				ft_error();
			map->ceiling_color[j] = ft_atoi(&line[i]);
			j++;
		}
		while (ft_isspace(line[i]) || line[i] == ',')
			i++;
		if (line[i] != '\0')
			ft_error();
	}
	return (parsed);
}
static mlx_texture_t	*set_texture(char *line)
{
	char			*filepath;
	mlx_texture_t	*texture;
	int				i;

	i = 0;
	while (line[i] != '\0')
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
	if (texture == NULL)
		ft_error();
	free(filepath);
	return (texture);
}

static bool	parse_textures(t_map *map, char	*line)
{
	int		i;
	bool	parsed;

	parsed = false;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) || ft_strncmp(&line[i], "EA", 2)
		|| ft_strncmp(&line[i], "SO", 2) || ft_strncmp(&line[i], "WE", 2))
		parsed = true;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		map->walls[0] = set_texture(&line[i + 2]);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		map->walls[1] = set_texture(&line[i + 2]);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		map->walls[2] = set_texture(&line[i + 2]);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		map->walls[3] = set_texture(&line[i + 2]);
	return (parsed);
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
		if (line)
			free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (parse_textures(map, line) == true)
			continue ;
		if (parse_floor_ceiling(map, line) == true)
			continue ;
		parse_map(map, line);
	}
	close(fd);
	if (line)
		free(line);
	return(map);
}
