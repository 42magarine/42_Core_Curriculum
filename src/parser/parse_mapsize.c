/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:14:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/01 17:47:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

#ifdef BONUS

static void	parse_portal(t_game *game, char *line)
{
	static int	p;
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'P')
		{
			if (p > 2)
				return (ft_error(game, "too many portals on the map\n"));
			else
			{
				game->map->portal[p].x = i;
				game->map->portal[p].y = game->map->max.y;
			}
			p++;
		}
		i++;
	}
}

static bool	set_map_size(t_game *game, char *line)
{
	static bool	start = false;

	if (start == true && (!is_map_line(line) || line[0] == '\0'))
		return (true);
	if (line[0] != '\0' && is_map_line(line))
	{
		start = true;
		if ((int)ft_strlen(line) > game->map->max.x)
			game->map->max.x = ft_strlen(line);
		if (is_player(line))
			parse_player(game, line);
		if (is_portal(line))
			parse_portal(game, line);
		game->map->max.y++;
	}
	return (false);
}

#else

static bool	set_map_size(t_game *game, char *line)
{
	static bool	start = false;

	if (start == true && (!is_map_line(line) || line[0] == '\0'))
		return (true);
	if (line[0] != '\0' && is_map_line(line))
	{
		start = true;
		if ((int)ft_strlen(line) > game->map->max.x)
			game->map->max.x = ft_strlen(line);
		if (is_player(line))
			parse_player(game, line);
		game->map->max.y++;
	}
	return (false);
}

#endif

void	parse_map(t_game *game, char *line)
{
	static int	i;
	static bool	start = false;

	if (is_map_line(line) && i <= game->map->max.y)
	{
		start = true;
		game->map->map[i] = ft_strdup(line);
		i++;
	}
	if (start == true && i == game->map->max.y)
		game->parsed->map = true;
}

void	parse_mapsize(t_game *game, char *filename)
{
	int			fd;
	char		*line;
	bool		stop;
	const char	*ext = ft_strrchr(filename, '.');

	if (!ext || ext == filename || ft_strcmp(ext, ".cub") != 0)
		ft_error(game, "file not ending in .cub");
	stop = false;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "filename error (argv[1])");
	line = get_next_line(fd);
	while (line != NULL)
	{
		cut_next_line(line);
		if (stop == false)
			stop = set_map_size(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->map = ft_calloc(game->map->max.y + 1, sizeof(char *));
}

