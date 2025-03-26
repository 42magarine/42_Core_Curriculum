/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:28:59 by mott              #+#    #+#             */
/*   Updated: 2024/07/01 11:46:39 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_portal_tex_east(t_game *game, mlx_texture_t *portal[])
{
	portal[0] = mlx_load_png("./textures/e_portal1.png");
	portal[1] = mlx_load_png("./textures/e_portal2.png");
	portal[2] = mlx_load_png("./textures/e_portal3.png");
	portal[3] = mlx_load_png("./textures/e_portal4.png");
	portal[4] = mlx_load_png("./textures/e_portal5.png");
	portal[5] = mlx_load_png("./textures/e_portal6.png");
	portal[6] = mlx_load_png("./textures/e_portal7.png");
	portal[7] = mlx_load_png("./textures/e_portal8.png");
	portal[8] = mlx_load_png("./textures/e_portal9.png");
	portal[9] = mlx_load_png("./textures/e_portal10.png");
	if (portal[0] == NULL || portal[1] == NULL || portal[2] == NULL
		|| portal[3] == NULL || portal[4] == NULL || portal[5] == NULL
		|| portal[6] == NULL || portal[7] == NULL || portal[8] == NULL
		|| portal[9] == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
}

static void	init_portal_tex_north(t_game *game, mlx_texture_t *portal[])
{
	portal[10] = mlx_load_png("./textures/n_portal1.png");
	portal[11] = mlx_load_png("./textures/n_portal2.png");
	portal[12] = mlx_load_png("./textures/n_portal3.png");
	portal[13] = mlx_load_png("./textures/n_portal4.png");
	portal[14] = mlx_load_png("./textures/n_portal5.png");
	portal[15] = mlx_load_png("./textures/n_portal6.png");
	portal[16] = mlx_load_png("./textures/n_portal7.png");
	portal[17] = mlx_load_png("./textures/n_portal8.png");
	portal[18] = mlx_load_png("./textures/n_portal9.png");
	portal[19] = mlx_load_png("./textures/n_portal10.png");
	if (portal[10] == NULL || portal[11] == NULL || portal[12] == NULL
		|| portal[13] == NULL || portal[14] == NULL || portal[15] == NULL
		|| portal[16] == NULL || portal[17] == NULL || portal[18] == NULL
		|| portal[19] == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
}

static void	init_portal_tex_west(t_game *game, mlx_texture_t *portal[])
{
	portal[20] = mlx_load_png("./textures/w_portal1.png");
	portal[21] = mlx_load_png("./textures/w_portal2.png");
	portal[22] = mlx_load_png("./textures/w_portal3.png");
	portal[23] = mlx_load_png("./textures/w_portal4.png");
	portal[24] = mlx_load_png("./textures/w_portal5.png");
	portal[25] = mlx_load_png("./textures/w_portal6.png");
	portal[26] = mlx_load_png("./textures/w_portal7.png");
	portal[27] = mlx_load_png("./textures/w_portal8.png");
	portal[28] = mlx_load_png("./textures/w_portal9.png");
	portal[29] = mlx_load_png("./textures/w_portal10.png");
	if (portal[20] == NULL || portal[21] == NULL || portal[22] == NULL
		|| portal[23] == NULL || portal[24] == NULL || portal[25] == NULL
		|| portal[26] == NULL || portal[27] == NULL || portal[28] == NULL
		|| portal[29] == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
}

static void	init_portal_tex_south(t_game *game, mlx_texture_t *portal[])
{
	portal[30] = mlx_load_png("./textures/s_portal1.png");
	portal[31] = mlx_load_png("./textures/s_portal2.png");
	portal[32] = mlx_load_png("./textures/s_portal3.png");
	portal[33] = mlx_load_png("./textures/s_portal4.png");
	portal[34] = mlx_load_png("./textures/s_portal5.png");
	portal[35] = mlx_load_png("./textures/s_portal6.png");
	portal[36] = mlx_load_png("./textures/s_portal7.png");
	portal[37] = mlx_load_png("./textures/s_portal8.png");
	portal[38] = mlx_load_png("./textures/s_portal9.png");
	portal[39] = mlx_load_png("./textures/s_portal10.png");
	if (portal[30] == NULL || portal[31] == NULL || portal[32] == NULL
		|| portal[33] == NULL || portal[34] == NULL || portal[35] == NULL
		|| portal[36] == NULL || portal[37] == NULL || portal[38] == NULL
		|| portal[39] == NULL)
		ft_error(game, mlx_strerror(mlx_errno));
}

void	init_portal_tex(t_game *game)
{
	init_portal_tex_east(game, game->tex->portal);
	init_portal_tex_north(game, game->tex->portal);
	init_portal_tex_west(game, game->tex->portal);
	init_portal_tex_south(game, game->tex->portal);
	game->tex->wall[8] = game->tex->portal[0];
	game->tex->wall[9] = game->tex->portal[10];
	game->tex->wall[10] = game->tex->portal[20];
	game->tex->wall[11] = game->tex->portal[30];
}
