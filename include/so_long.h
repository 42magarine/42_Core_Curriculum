/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:20:16 by mott              #+#    #+#             */
/*   Updated: 2024/02/15 19:04:56 by mott             ###   ########.fr       */
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

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

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
	mlx_t		*window;
	t_position	*player_position;
	t_position	*map_size;
	t_textures	*textures;
	t_images	*images;
}	t_game;

// so_long.c
int			main(int argc, char **argv);
void		run_game(void);
void		key_hook(mlx_key_data_t keydata, void *param);
void		sl_error(void);

// png.c
void	load_png(t_game *game);
void	create_images(t_game *game);
void	display_board(t_game *game);
void	display_objects(t_game *game);

#endif
