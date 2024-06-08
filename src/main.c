/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:31:12 by mott              #+#    #+#             */
/*   Updated: 2024/06/07 19:04:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	width = 512;
int	height = 512;

static void ft_bottom(mlx_t *mlx)
{
	mlx_image_t	*bottom;
	int			color;
	int			x;
	int			y;

	bottom = mlx_new_image(mlx, width, height / 2);
	if (bottom == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	color = ft_get_rgba(34, 139, 34, 255); // forestgreen
	y = 0;
	while (y < height / 2)
	{
		x = 0;
		while (x < width)
		{
			mlx_put_pixel(bottom, x, y, color);
			x++;
		}
		y++;
	}

	if (mlx_image_to_window(mlx, bottom, 0, height / 2) == -1)
		ft_exit(mlx_strerror(mlx_errno));
}

static void ft_top(mlx_t *mlx)
{
	mlx_image_t	*top;
	int			color;
	int			x;
	int			y;

	top = mlx_new_image(mlx, width, height / 2);
	if (top == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	color = ft_get_rgba(135, 206, 235, 255); // skyblue
	y = 0;
	while (y < height / 2)
	{
		x = 0;
		while (x < width)
		{
			mlx_put_pixel(top, x, y, color);
			x++;
		}
		y++;
	}

	if (mlx_image_to_window(mlx, top, 0, 0) == -1)
		ft_exit(mlx_strerror(mlx_errno));
}

static int	test_mlx(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	mlx = mlx_init(width, height, "cub3D", true);
	if (mlx == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	ft_bottom(mlx);
	ft_top(mlx);

	texture = mlx_load_png("./textures/north.png");
	if (texture == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	img = mlx_texture_to_image(mlx, texture);
	if (img == NULL)
		ft_exit(mlx_strerror(mlx_errno));

	mlx_resize_image(img, 128, 128);

	if (mlx_image_to_window(mlx, img, 128, 192) == -1)
		ft_exit(mlx_strerror(mlx_errno));
	if (mlx_image_to_window(mlx, img, 256, 192) == -1)
		ft_exit(mlx_strerror(mlx_errno));



	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);

}
