/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:20:16 by mott              #+#    #+#             */
/*   Updated: 2024/02/17 20:50:09 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // perror
# include <string.h> // strerror
# include <math.h> // ???

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# ifndef PIXEL
#  define PIXEL 64
# endif

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

// typedef struct s_map
// {
// 	char	**map;
// 	t_xy	map_size;
// }	t_map;

typedef struct s_textures
{
	mlx_texture_t	*board1;
	mlx_texture_t	*board2;
	mlx_texture_t	*wall;
	mlx_texture_t	*coll;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	// mlx_texture_t	*enemy;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*board1;
	mlx_image_t	*board2;
	mlx_image_t	*wall;
	mlx_image_t	*coll;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	// mlx_image_t	*enemy;
}	t_images;

typedef struct s_game
{
	mlx_t		*window;
	int			**cmap;
	char		**map;
	t_xy		map_size;
	t_xy		player;
	t_textures	*png;
	t_images	*img;
}	t_game;

// so_long.c
int		main(int argc, char **argv);
void	so_run_game(t_game *game);
void	so_key_hook(mlx_key_data_t keydata, void *param);
void	so_move_player(t_game *game, int x, int y);
void	so_exit(char *exit_type, t_game *game);

// png.c
void	so_load_png(t_game *game);
void	so_create_images(t_game *game);
void	so_display_board(t_game *game);
void	so_display_objects(t_game *game);

// map.c
void	so_load_map(t_game *game, char *filename);
void	so_map_size(t_game *game, char *filename);
void	so_read_map(t_game *game, char *filename);
char	**so_copy_map(char **map, t_xy map_size);
void	so_find_start(t_game *game);

// map_valid.c
void	so_map_rectangular(t_game *game);
void	so_map_wall(t_game *game);
int		so_object_counter(char **map, t_xy map_size, char c);
void	so_map_wrong_character(t_game *game);

// utils.c
void	so_flood_fill(char **map, t_xy size, t_xy pos);
int		so_strlen(char *str);
void	so_free_strs(char **strs);

//collect.c

void	so_create_cmap(t_game *game);

#endif
