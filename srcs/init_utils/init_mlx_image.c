/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:49:12 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/18 07:00:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_3d_image(void *mlx, t_img *img_3d)
{
	void	*img;
	char	*addr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;

	img = (void *)mlx_new_image(mlx, IMG_3D_WIDTH, WIN_HEIGHT);
	if (img == NULL)
		return (EXIT_FAILURE);
	bits_per_pixel = &(img_3d->bpp);
	size_line = &(img_3d->line_length);
	endian = &(img_3d->endian);
	addr = (char *)mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
	if (addr == NULL)
	{
		mlx_destroy_image(mlx, img_3d->img);
		return (EXIT_FAILURE);
	}
	img_3d->img = img;
	img_3d->addr = addr;
	return (EXIT_SUCCESS);
}

static int	init_2d_image(void *mlx, t_img *img_2d)
{
	void	*img;
	char	*addr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;

	img = mlx_new_image(mlx, IMG_2D_WIDTH, WIN_HEIGHT);
	if (img == NULL)
		return (EXIT_FAILURE);
	bits_per_pixel = &img_2d->bpp;
	size_line = &img_2d->line_length;
	endian = &img_2d->endian;
	addr = mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
	if (addr == NULL)
	{
		mlx_destroy_image(mlx, img_2d->img);
		return (EXIT_FAILURE);
	}
	img_2d->img = img;
	img_2d->addr = addr;
	return (EXIT_SUCCESS);
}

int	init_mlx_image(t_game *game)
{
	if (init_3d_image(game->mlx, &game->img_3d) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (DISABLE_2D_MAP == false)
	{
		if (init_2d_image(game->mlx, &game->img_2d) != EXIT_SUCCESS)
		{
			mlx_destroy_image(game->mlx, game->img_3d.img);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
