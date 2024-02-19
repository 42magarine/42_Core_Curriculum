/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:42:22 by mott              #+#    #+#             */
/*   Updated: 2024/02/19 20:16:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// floodfile with only way through enemy

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		so_exit(ERR_SYS, "malloc", NULL);
	ft_memset(game, 0, sizeof(t_game));
	so_init_map(game, argv[1]);
	so_init_game(game);
	free(game);
	system("leaks so_long_bonus");
	return (EXIT_SUCCESS);
}

// Frees everything, writes an error message and exit the program.
void	so_exit(int error, char *message, t_game *game)
{
	so_free_strs(game->map);
	if (game->png != NULL)
		so_free_png(game->png);
	if (game->img != NULL)
		so_free_img(game);
	free(game);
	if (error == ERR_SYS)
		perror(message);
	else if (error == ERR_USE)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
	}
	else if (error == ERR_MLX)
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}

// frees an array of strings.
void	so_free_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

// Frees all png-files.
void	so_free_png(t_textures *png)
{
	if (png->board1 != NULL)
		mlx_delete_texture(png->board1);
	if (png->board2 != NULL)
		mlx_delete_texture(png->board2);
	if (png->wall != NULL)
		mlx_delete_texture(png->wall);
	if (png->collect != NULL)
		mlx_delete_texture(png->collect);
	if (png->exit != NULL)
		mlx_delete_texture(png->exit);
	if (png->player != NULL)
		mlx_delete_texture(png->player);
	if (png->enemy1 != NULL)
		mlx_delete_texture(png->enemy1);
	if (png->enemy2 != NULL)
		mlx_delete_texture(png->enemy2);
	free(png);
}

// Frees all img-files.
void	so_free_img(t_game *game)
{
	if (game->img->board1 != NULL)
		mlx_delete_image(game->window, game->img->board1);
	if (game->img->board2 != NULL)
		mlx_delete_image(game->window, game->img->board2);
	if (game->img->wall != NULL)
		mlx_delete_image(game->window, game->img->wall);
	if (game->img->collect != NULL)
		mlx_delete_image(game->window, game->img->collect);
	if (game->img->exit != NULL)
		mlx_delete_image(game->window, game->img->exit);
	if (game->img->player != NULL)
		mlx_delete_image(game->window, game->img->player);
	if (game->img->enemy1 != NULL)
		mlx_delete_image(game->window, game->img->enemy1);
	if (game->img->enemy2 != NULL)
		mlx_delete_image(game->window, game->img->enemy2);
	free(game->img);
}
