/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:20:16 by mott              #+#    #+#             */
/*   Updated: 2024/02/13 18:36:34 by mott             ###   ########.fr       */
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

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_textures
{
	mlx_texture_t	*board1;
	mlx_texture_t	*board2;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*enemy;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*board1;
	mlx_image_t	*board2;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectibles;
	mlx_image_t	*enemy;
}	t_images;

// typedef struct s_map
// {
// 	mlx_t	*window;
// 	t_pos	*mapsize;
// }	t_map;

// so_long.c
int			main(int argc, char **argv);
void		run_game();
t_textures	*load_png(void);
t_images	*create_images(mlx_t *game, t_textures *textures);
void		display_board(mlx_t *game, t_pos *map, t_images *images);
void		sl_error(void);

#endif
