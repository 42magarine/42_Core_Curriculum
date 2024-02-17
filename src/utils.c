/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:49:13 by mott              #+#    #+#             */
/*   Updated: 2024/02/17 17:26:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_flood_fill(char **map, t_xy size, t_xy pos)
{
	if (pos.y < 0 || pos.x < 0 || pos.y >= size.y || pos.x >= size.x
			|| map[pos.y][pos.x] == '1')
		return ;
	map[pos.y][pos.x] = '1';
	so_flood_fill(map, size, (t_xy){pos.x - 1, pos.y});
	so_flood_fill(map, size, (t_xy){pos.x + 1, pos.y});
	so_flood_fill(map, size, (t_xy){pos.x, pos.y - 1});
	so_flood_fill(map, size, (t_xy){pos.x, pos.y + 1});
}

// Calculates the length of the string until '\n'.
int	so_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	so_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}
