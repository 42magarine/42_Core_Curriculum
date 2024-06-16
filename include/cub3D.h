/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/12 18:13:49 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <string.h>	// strerror
# include <stdbool.h>
# include <stdint.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	char			**map;
	int				x_max;
	int				y_max;
	uint8_t			bot_rgb[3];
	uint8_t			top_rgb[3];
	mlx_texture_t	*walls[4]; //NESW
}	t_map;

typedef struct s_game
{
	t_map	*map;
}	t_game;

//parsing
void	parse_textures(t_game *game, char *line);
void	parse_floor_ceiling(t_game *game, char *line);
void	parse_map(t_game *game, char *line);
void	set_map_size(t_game *game, char *filename);

//debug
void	debug_map(t_map *map);

//error
void	ft_error(t_game *game, char *errormsg);

//free
void	free_game(t_game *game);

#endif
