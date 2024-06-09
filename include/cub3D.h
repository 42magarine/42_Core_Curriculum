/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/09 17:13:27 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <string.h>	// strerror
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	char	**map;
	char	*n_texture;
	char	*e_texture;
	char	*s_texture;
	char	*w_texture;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_map;

typedef struct s_game
{
	t_map	*map;
}	t_game;


#endif
