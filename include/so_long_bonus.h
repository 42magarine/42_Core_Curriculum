/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:20:16 by mott              #+#    #+#             */
/*   Updated: 2024/02/20 14:19:33 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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

typedef struct s_textures
{
	mlx_texture_t	*board1;
	mlx_texture_t	*board2;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*enemy[8];
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*board1;
	mlx_image_t	*board2;
	mlx_image_t	*wall;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*enemy[8];
}	t_images;

typedef struct s_game
{
	mlx_t		*window;
	t_textures	*png;
	t_images	*img;
	char		**map;
	t_xy		map_size;
	int			collect_count;
	int			exit_count;
	int			player_count;
	t_xy		player;
	int			move_count;
	int			enemy_count;
	t_xy		enemy;
}	t_game;

enum e_error
{
	ERR_SYS,
	ERR_USE,
	ERR_MLX
};

// so_long_bonus.c
int		main(int argc, char **argv);
void	so_exit(int error, char *message, t_game *game);
void	so_free_strs(char **strs);
void	so_free_png(t_textures *png);
void	so_free_img(t_game *game);

// map_bonus.c
void	so_init_map(t_game *game, char *file);
void	so_map_size(t_game *game, char *file);
void	so_read_map(t_game *game, char *file);
void	so_loop_map(t_game *game, void (*f)(t_game *game, int x, int y));
void	so_count_objects(t_game *game, int x, int y);

// map_valid_bonus.c
void	so_map_rectangular(t_game *game);
void	so_map_wall(t_game *game);
char	**so_copy_map(t_game *game);
void	so_flood_fill(char **map, t_xy map_size, t_xy position);
void	so_valid_path(t_game *game, char **map_copy);

// game_bonus.c
void	so_init_game(t_game *game);
void	so_key_hook(mlx_key_data_t keydata, void *param);
void	so_move_player(t_game *game, int x, int y);
void	so_collect_collectible(t_game *game, int x, int y);
void	so_did_you_win(t_game *game);

// png_bonus.c
void	so_load_png(t_game *game);
void	so_create_images(t_game *game);
void	so_board_to_window(t_game *game, int x, int y);
void	so_objects_to_window(t_game *game, int x, int y);
void	so_image_to_window(t_game *game, mlx_image_t *img, int x, int y);

// enemy_bonus.c
void	so_enemy_hook(void *param);
void	so_enemy_animation(t_game *game, int i);
void	so_move_enemy(t_game *game, int x, int y);
int		so_strlen(char *str);

#endif
