/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/12 21:29:04 by mott             ###   ########.fr       */
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

extern char *g_map[];

typedef struct s_player
{
	int			x;
	int			y;
	int			fov;
	double		direction;
	int			size;
}	t_player;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
}	t_window;

typedef struct s_map
{
	int		x;
	int		y;
	int		field_size;
}	t_map;

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

typedef struct s_game
{
	t_player	*player;
	t_window	*window;
	t_map		*map;
	int			x;
	int			y;
}	t_game;

// draw.c
void	ft_draw_square(t_game *game, int map_x, int map_y, int size, int color);
void	ft_draw_map_2D(t_game *game);
void	ft_draw_player(t_game *game);
void	ft_draw_line(t_game *game, int rx, int ry);

// hook.c
void	ft_key_hook(void *param);
void	ft_loop_hook(void *param);

// init.c
void	init_var(t_game *game, t_player *player, t_window *window, t_map *map);
int		init_mlx(t_game *game);

// main.c
int		main(void);
int		ft_exit(const char *str);

// ray.c
void	ft_ray_caster(t_game *game);

#endif
