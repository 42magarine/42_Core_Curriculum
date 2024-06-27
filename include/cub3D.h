/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/27 14:21:46 by mott             ###   ########.fr       */
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
# include <math.h>
# include "../libft/libft.h"
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define BLACK			0x000000FF	// (0, 0, 0, 255)
# define WHITE			0xFFFFFFFF	// (255, 255, 255, 255)
# define WHITE_SMOKE	0xF5F5F5FF	// (245, 245, 245, 255)
# define RED			0xFF0000FF	// (255, 0, 0, 255)
# define LIME			0x00FF00FF	// (0, 255, 0, 255)
# define BLUE			0x0000FFFF	// (0, 0, 255, 255)
# define YELLOW			0xFFFF00FF	// (255, 255, 0, 255)
# define CYAN			0x00FFFFFF	// (0, 255, 255, 255)
# define MAGENTA		0xFF00FFFF	// (255, 0, 255, 255)
# define SILVER			0xC0C0C0FF	// (192, 192, 192, 255)
# define GRAY			0x808080FF	// (128, 128, 128, 255)
# define MAROON			0x800000FF	// (128, 0, 0, 255)
# define OLIVE			0x808000FF	// (128, 128, 0, 255)
# define GREEN			0x008000FF	// (0, 128, 0, 255)
# define PURPLE			0x800080FF	// (128, 0, 128, 255)
# define TEAL			0x008080FF	// (0, 128, 128, 255)
# define NAVY			0x000080FF	// (0, 0, 128, 255)

# define WIDTH			1920
# define HEIGHT			1080
# define MM_WIDTH		448
# define MM_HEIGHT		448
# define SIZE			64
# define FOV			60.0
# define ONE_PI			3.141592
# define TWO_PI			6.283185
# define HALF_PI		1.570796
# define THREE_HALF_PI	4.712388
# define W_EAST			0
# define W_NORTH		1
# define W_WEST			2
# define W_SOUTH		3
# define D_EAST			4
# define D_NORTH		5
# define D_WEST			6
# define D_SOUTH		7
# define O_EAST			8
# define O_NORTH		9
# define O_WEST			10
# define O_SOUTH		11
# define MOVE_SPEED		1.75
# define ROTATION_SPEED	0.034907

typedef struct s_coords
{
	double	x;
	double	y;
}	t_coords;

typedef struct s_parse
{
	bool		walls;
	bool		doors;
	bool		floor_ceiling;
	bool		map;
	bool		player;
}	t_parse;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_window;

typedef struct s_map
{
	char			**map;
	t_coords		max;
	int				floor;
	int				ceiling;
	mlx_texture_t	*wall[8]; //move to t_game
}	t_map;

typedef struct s_player
{
	t_coords	pos;
	t_coords	mm_pos;
	double		dir;
}	t_player;

typedef struct s_ray
{
	t_coords	hit[WIDTH];
	double		len[WIDTH];
	int			wall[WIDTH];
	double		fov_start;
	double		fov_add;
}	t_ray;

typedef struct s_texture
{
	t_coords	pos;
	double		y_scale;
	double		y_offset;
	int			wall_height;
	int			wall_offset;
}	t_texture;

typedef struct s_minimap
{
	double		factor;
	t_coords	start;
	t_coords	player;
	bool		show;

}	t_minimap;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_parse		*parsed; // raus
	t_ray		*ray;
	t_texture	*tex;
	t_minimap	*minimap;
	bool		recalculate;
	bool		mouse_rotate;
}	t_game;

// main.c
int		main(int argc, char **argv);

// engine
// draw_game.c
void	draw_background(t_game *game);
void	draw_wall(t_game *game, double radian, int x);

// draw_minimap.c
void	draw_minimap(t_game *game);

// init.c
void	init_game(t_game *game);
void	loop_hook(void *param);

// key_movement.c
void	key_hook(t_game *game);
void	rotate_player(t_game *game, char dir);

// key_special.c
void	special_key_hook(mlx_key_data_t keydata, void *param);

// mouse.c
void	mouse_hook(t_game *game);

// ray.c
void	ray_calculation(t_game *game, double radian, int x);

// parser
// parsing
void	init_map(t_game *game, char *filename);
void	parse_tex(t_game *game, char *line);
void	parse_floor_ceiling(t_game *game, char *line);
void	parse_mapfile(t_game *game, char *filename);

// utils
mlx_texture_t	*set_texture(t_game *game, char *line);
void	ft_error(t_game *game, const char *errormsg);
int		get_rgba(int r, int g, int b, int a);
double	pi_overflow(double radian);

//free.c
void	free_game(t_game *game);

// bools.c
bool	is_map_char(char c);
bool	is_map_line(char *line);
bool	is_player_char(char c);
bool	is_player_start(char *line);

// debug.c
void	debug_parse(t_game *game);

#endif
