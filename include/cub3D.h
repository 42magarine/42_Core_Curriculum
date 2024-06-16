/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/16 15:46:04 by mott             ###   ########.fr       */
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
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define BLACK		0x000000	// (0, 0, 0)
# define WHITE		0xFFFFFF	// (255, 255, 255)
# define RED		0xFF0000	// (255, 0, 0)
# define LIME		0x00FF00	// (0, 255, 0)
# define BLUE		0x0000FF	// (0, 0, 255)
# define YELLOW		0xFFFF00	// (255, 255, 0)
# define CYAN		0x00FFFF	// (0, 255, 255)
# define MAGENTA	0xFF00FF	// (255, 0, 255)
# define SILVER		0xC0C0C0	// (192, 192, 192)
# define GRAY		0x808080	// (128, 128, 128)
# define MAROON		0x800000	// (128, 0, 0)
# define OLIVE		0x808000	// (128, 128, 0)
# define GREEN		0x008000	// (0, 128, 0)
# define PURPLE		0x800080	// (128, 0, 128)
# define TEAL		0x008080	// (0, 128, 128)
# define NAVY		0x000080	// (0, 0, 128)

# define PLAYER_SIZE	8
# define FIELD_SIZE		64
# define PI_ONE			M_PI
# define PI_TWO			2 * M_PI
# define PI_HALF		M_PI / 2
# define PI_THREE_HALF	3 * M_PI / 2

extern char *g_map[];

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_player
{
	t_point		*pos;
	int			fov;
	double		dir;
}	t_player;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
}	t_window;

typedef struct s_game
{
	t_player	*player;
	t_window	*window;
	t_point		*point;
}	t_game;

// init.c
void	init_var(t_game *game, t_player *player, t_window *window, t_point *map);
void	init_mlx(t_window *window);

// draw.c
void	ft_draw_square(t_game *game, int map_x, int map_y, int size_x, int size_y, int color);
void	ft_draw_map_2D(t_game *game);
void	ft_draw_player(t_game *game);
void	draw_line(t_game *game, t_point start, t_point stop);
void	ft_draw_background(t_game *game);

// hook.c
void	ft_key_hook(void *param);
void	ft_loop_hook(void *param);


// main.c
int		main(void);
int		ft_exit(const char *str);

// ray.c
void	ft_ray_caster(t_game *game);

#endif
