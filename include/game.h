/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:31:18 by mott              #+#    #+#             */
/*   Updated: 2024/06/11 17:52:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

extern char *g_map[];

typedef struct s_player
{
	int			x;
	int			y;
	int			fov;
	int 		angle;
	int			size;
	char		direction;
	mlx_image_t	*image;
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

// main.c
void	ft_ray_caster(t_game *game);

// game.c
int		init_mlx(t_game *game);
void 	ft_draw_line(void *param);

// hook.c
// void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_key_hook(void *param);
void	ft_loop_hook(void *param);

#endif
