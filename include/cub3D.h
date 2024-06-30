/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/30 17:07:47 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <string.h>	// strerror
# include <math.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define BLACK			0x000000FF	// (0, 0, 0, 255)
# define WHITE			0xFFFFFFFF	// (255, 255, 255, 255)
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
# define E_WALL			0
# define N_WALL			1
# define W_WALL			2
# define S_WALL			3
# define E_DOOR			4
# define N_DOOR			5
# define W_DOOR			6
# define S_DOOR			7
# define E_PORTAL		8
# define N_PORTAL		9
# define W_PORTAL		10
# define S_PORTAL		11
# define MOVE_SPEED		2.75
# define ROTATION_SPEED	0.069813

typedef struct s_coords
{
	double	x;
	double	y;
}	t_coords;

typedef struct s_parse
{
	bool	walls;
	bool	doors;
	bool	floor_ceiling;
	bool	map;
	bool	player;
}	t_parse;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	bool		mouse_rotate;
}	t_window;

typedef struct s_map
{
	char			**map;
	int				floor;
	int				ceiling;
	t_coords		max;
	t_coords		p_one;
	t_coords		p_two;
}	t_map;

typedef struct s_player
{
	t_coords	pos;
	double		dir;
}	t_player;

typedef struct s_ray
{
	t_coords	hit[WIDTH];
	int			wall[WIDTH];
	double		len[WIDTH];
	double		fov_start;
	double		fov_add;
}	t_ray;

typedef struct s_texture
{
	mlx_texture_t	*wall[12];
	mlx_texture_t	*portal[40];
	t_coords		pos;
	double			y_scale;
	double			y_offset;
	int				wall_height;
	int				wall_offset;
}	t_texture;

typedef struct s_minimap
{
	t_coords	start;
	t_coords	player;
	int			factor;
	bool		show;
}	t_minimap;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_ray		*ray;
	t_texture	*tex;
	t_minimap	*minimap;
	t_parse		*parsed;
}	t_game;

// main.c
int		main(int argc, char **argv);

// engine
// draw_game.c
void	draw_background(t_game *game);
void	draw_wall(t_game *game, double radian, int x);

// draw_minimap.c
void	draw_minimap(t_game *game);
void	draw_player(t_game *game);
void	draw_ray(t_game *game, t_coords player, t_coords wall);

// init.c
void	init_game(t_game *game);

// key_movement.c
void	key_hook(t_game *game);
void	rotate_player(t_game *game, char dir);

// key_special.c
void	special_key_hook(mlx_key_data_t keydata, void *param);

// loop.c
void	loop_hook(void *param);

// mouse.c
void	mouse_hook(t_game *game);

// portal.c
void	init_portal(t_game *game, char *line);
void	portal_tex(t_game *game);
void	portal_animation(t_game *game);

// ray.c
void	ray_calculation(t_game *game, double radian, int x);

// teleport.c
bool	teleport_east(t_game *game, t_coords dest);
bool	teleport_west(t_game *game, t_coords dest);
bool	teleport_north(t_game *game, t_coords dest);
bool	teleport_south(t_game *game, t_coords dest);

// teleport2.c
void	teleport_check(t_game *game, double x, double y);

// parser
// parsing
void	init_map(t_game *game, char *filename);
void	init_player(t_game	*game, char *line);
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
bool	is_player(char *line);
bool	is_portal(char *line);
bool	is_start(t_map *map, int x, int y, char c);
bool	all_parsed(t_game *game, t_parse *parse);

// debug.c
void	debug_parse(t_game *game);

#endif
