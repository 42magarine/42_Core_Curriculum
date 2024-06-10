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

static void	parse_map(t_game *game, char *line)
{
	static int	i = 0;

	if (line[0] == '1' || line[0] == ' ')
	{
		game->map->map[i] = ft_strdup(line);
		i++;
	}
}

static void	parse_floor_ceiling(t_game *game, char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
			game->map->floor_color = parse_rgb(game, line + 1);
		if (line[i] == 'C')
			game->map->ceiling_color = parse_rgb(game, line + 1);
	}
}

static int	*parse_rgb(t_game *game, char *line)
{
	int		i;
	int		j;
	int		rgb[3];

	i = 0;
	j = 0;
	while (line[i] != '\0' && j < 3)
	{
		while (ft_isspace(line[i]) || line[i] == ',')
			i++;
		if (!ft_isdigit(line[i]))
			ft_error(game, "parse_rgb error - invalid chars");
		rgb[j] = ft_atoi(&line[i]);
		if (rbg[j] < 0 || rgb[j] > 255)
			ft_error(game, "parse_rgb error - invalid range(0 to 255)")
		while (ft_isdigit(line[i]))
			i++;
		j++;
	}
	while (ft_isspace(line[i]))
		i++;
	if (ft_strlen(&line[i] > 0))
		ft_error(game, "parse_rgb error - line too long");
	return (rgb);
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
			ft_error(game, "parse_texture error - invalid filepath");
	}
	filepath = ft_strdup(line + i);
	texture = mlx_load_png(filepath);
	if (texture == NULL)
		ft_error(game, "parse_texture error - invalid file");
	free(filepath);
	return (texture);
}

static void	parse_textures(t_game *game, char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		game->map->walls[0] = set_texture(&line[i + 2]);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		game->map->walls[1] = set_texture(&line[i + 2]);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		game->map->walls[2] = set_texture(&line[i + 2]);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		game->map->walls[3] = set_texture(&line[i + 2]);
}

void	*parse_mapfile(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	game->map = ft_calloc(1, sizeof(t_map));
	game->map->map = ft_calloc(15, sizeof(char *)); //calc x/y max beforehand
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		parse_textures(game, line);
		parse_floor_ceiling(game, line)
		parse_map(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
