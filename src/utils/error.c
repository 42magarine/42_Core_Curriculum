/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:07:23 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/01 20:09:33 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_error(t_game *game, const char *error)
{
	printf("Error\n");
	printf("%s\n", error);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	ft_error_parse(t_game *game, char *line, const char *error)
{
	printf("Error\n");
	printf("%s\n", error);
	if (line)
		free(line);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	ft_error_floodfill(t_game *game, char **temp, const char *error)
{
	printf("Error\n");
	printf("%s\n", error);
	if (temp)
		ft_free_strarray(temp);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}
