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

#include "cub3D.h"

void	parse_map(t_map *map, char *line)
{
	
}

void	parse_floor_ceiling(t_map *map, char *line)
{

}

void	parse_textures(t_map *map, char	*line)
{
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
	line = NULL;
	while (get_next_line(fd) != NULL)
	{
		parse_textures(map, line);
		parse_floor_ceiling(map, line);
		parse_map(map, line);
	}
	return(map);
}
