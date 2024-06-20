/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/19 18:06:07 by fwahl            ###   ########.fr       */
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

# define BLACK			0x000000	// (0, 0, 0)
# define WHITE			0xFFFFFF	// (255, 255, 255)
# define WHITE_SMOKE	0xF5F5F5	// (245, 245, 245)
# define RED			0xFF0000	// (255, 0, 0)
# define LIME			0x00FF00	// (0, 255, 0)
# define BLUE			0x0000FF	// (0, 0, 255)
# define YELLOW			0xFFFF00	// (255, 255, 0)
# define CYAN			0x00FFFF	// (0, 255, 255)
# define MAGENTA		0xFF00FF	// (255, 0, 255)
# define SILVER			0xC0C0C0	// (192, 192, 192)
# define GRAY			0x808080	// (128, 128, 128)
# define MAROON			0x800000	// (128, 0, 0)
# define OLIVE			0x808000	// (128, 128, 0)
# define GREEN			0x008000	// (0, 128, 0)
# define PURPLE			0x800080	// (128, 0, 128)
# define TEAL			0x008080	// (0, 128, 128)
# define NAVY			0x000080	// (0, 0, 128)

# define PLAYER_SIZE	2
# define FIELD_SIZE		16
# define PI_ONE			M_PI
# define PI_TWO			2 * M_PI
# define PI_HALF		M_PI / 2
# define PI_THREE_HALF	3 * M_PI / 2
# define FOV			60.0

typedef struct s_coords
{
	int		x;
	int		y;
}	t_coords;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
}	t_window;

typedef struct s_map
{
	char			**map;
	int				floor;
	int				ceiling;
	t_coords		max;
	mlx_texture_t	*walls[4]; //NESW
}	t_map;

typedef struct s_player
{
	t_coords	pos;
	double		dir;
}	t_player;

typedef struct s_parse
{
	bool		walls;
	bool		floor_ceiling;
	bool		map;
}	t_parse;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_parse		*parsed;
}	t_game;

// init.c
void	init_mlx(t_game *game);

// draw.c
void	draw_line(t_window *window, t_coords start, t_coords stop);
void	draw_background(t_window *window, t_map *map);
void	draw_minimap(t_window *window, t_map *map, t_coords player);
void	draw_game(t_window *window);

// hook.c
void	loop_hook(void *param);

// main.c
int		ft_exit(const char *str);

// ray.c
void	ray_caster(t_window *window, t_map *map, t_player *player);

//parsing
void	parse_walls(t_game *game, char *line);
void	parse_floor_ceiling(t_game *game, char *line);
void	parse_map(t_game *game, char *line);
void	init_map(t_game *game, char *filename);
bool	validate_map(t_game *game); //bool for improved debuging, can be changed to void later

//error
void	ft_error(t_game *game, char *errormsg);

//free
void	free_game(t_game *game);

//bools
bool	is_map_char(char c);
bool	is_map_line(char *line);
bool	is_player_char(char c);
bool	is_player_start(char *line);

//debug
void	debug_map(t_map *map);
void	debug_player(t_player *player);

#endif
