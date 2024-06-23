/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:21:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/23 16:16:44 by mott             ###   ########.fr       */
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
