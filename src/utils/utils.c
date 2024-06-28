/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:21:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/28 20:48:22 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_error(t_game *game, const char *errormsg)
{
	printf("Error\n");
	printf("%s\n", errormsg);
	free_game(game);
	exit(EXIT_FAILURE);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	pi_overflow(double radian)
{
	if (radian < 0)
		radian += TWO_PI;
	else if (radian >= TWO_PI)
		radian -= TWO_PI;
	return (radian);
}

mlx_texture_t	*set_texture(t_game *game, char *line)
{
	char			*filepath;
	mlx_texture_t	*texture;
	int				i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]))
			i++;
		else if (line[i] == '.')
			break ;
		else
			ft_error(game, "parse_texture error - invalid filepath");
	}
	filepath = ft_strdup(&line[i]);
	texture = mlx_load_png(filepath);
	if (texture == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
	free(filepath);
	return (texture);
}
