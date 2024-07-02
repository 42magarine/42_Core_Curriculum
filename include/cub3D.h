/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/07/02 15:21:46 by mott             ###   ########.fr       */
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

# define MM_BLUE		0x224fbcff	// (34, 79, 188, 255)
# define MM_WHITE		0xffffffff	// (255, 255, 255, 255)
# define MM_GOLD		0xffd700ff	// (255, 215, 0, 255)
# define MM_ORANGE		0xffa500ff	// (255, 165, 0, 255)
# define MM_RED			0x800080ff	// (128, 0, 32, 255)
# define MM_ROSE		0x9b1b30ff	// (155, 27, 48, 255)
# define MM_GRAY		0x696969ff	// (105, 105, 105, 255)

# define WIDTH			1920
# define HEIGHT			1080
# define MM_SIZE		448
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
	char		**map;
	int			floor;
	int			ceiling;
	t_coords	max;
	t_coords	portal[2];
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

// key_movement.c
void	key_hook(t_game *game);
void	rotate_player(t_game *game, char dir);

// key_special.c
void	special_key_hook(mlx_key_data_t keydata, void *param);

// loop.c
void	loop_hook(void *param);

// mouse.c
void	mouse_hook(t_game *game);
void	init_mouse(t_game *game);

// ray.c
void	ray_calculation(t_game *game, double radian, int x);

// teleport_check.c
void	teleport_check(t_game *game, double x, double y);

// teleport_dir.c
bool	teleport_east(t_game *game, t_coords dest);
bool	teleport_west(t_game *game, t_coords dest);
bool	teleport_north(t_game *game, t_coords dest);
bool	teleport_south(t_game *game, t_coords dest);

// init
// init_game.c
void	init_window(t_game *game);
void	init_player(t_map *map, t_player *player);
void	init_door_tex(t_game *game);
void	init_ray(t_ray *ray);
void	init_minimap(t_map *map, t_minimap *minimap);

// init_portal.c
void	init_portal_tex(t_game *game);

// parser
// parsing
void	parse_mapsize(t_game *game, char *filename);
void	parse_map(t_game *game, char *line);
void	parse_player(t_game	*game, char *line);
void	parse_tex(t_game *game, char *line);
void	parse_floor_ceiling(t_game *game, char *line);
void	parse_mapfile(t_game *game, char *filename);
void	validate_map(t_game *game);

// utils
mlx_texture_t	*set_texture(t_game *game, char *line);
int				get_rgba(int r, int g, int b, int a);
double			pi_overflow(double radian);

//error.c
void	ft_error(t_game *game, const char *error);
void	ft_error_parse(t_game *game, char *line, const char *error);
void	ft_error_floodfill(t_game *game, char **temp, const char *error);

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
