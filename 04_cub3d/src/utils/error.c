/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:07:23 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/02 17:46:42 by mott             ###   ########.fr       */
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

void	ft_error_ff(t_game *game, char **temp, const char *error)
{
	printf("Error\n");
	printf("%s\n", error);
	if (temp)
		ft_free_strarray(temp);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}
