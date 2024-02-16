/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:20:16 by mott              #+#    #+#             */
/*   Updated: 2024/02/16 20:47:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> // open
# include <unistd.h> // close, read, write
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // perror
# include <string.h> // strerror
# include <math.h>
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_textures
{
	mlx_texture_t	*board1;
	mlx_texture_t	*board2;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*enemy;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*board1;
	mlx_image_t	*board2;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*enemy;
}	t_images;

typedef struct s_game
{
	t_xy		*map_size;
	char		**map;
	mlx_t		*window;
	t_xy		*player_position;
	t_textures	*textures;
	t_images	*images;
}	t_game;

// so_long.c
int		main(int argc, char **argv);
void	run_game(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	so_exit(char *exit_type, t_game *game);

// png.c
void	load_png(t_game *game);
void	create_images(t_game *game);
void	display_board(t_game *game);
void	display_objects(t_game *game);

// map.c
void	so_load_map(t_game *game, char *filename);
void	so_map_size(t_game *game, char *filename);
void	so_read_map(t_game *game, char *filename);
int		so_strlen(char *str);

// map_valid.c
void	so_map_rectangular(t_game *game);
void	so_map_wall(t_game *game);
void	so_map_objects(t_game *game, char object);

#endif
