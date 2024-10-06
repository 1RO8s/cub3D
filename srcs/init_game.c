/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:50:44 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 01:08:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx_and_window(t_game *game)
{
	void	*mlx;
	void	*window;

	mlx = (void *)mlx_init();
	if (mlx == NULL)
		return (EXIT_FAILURE);
	window = (void *)mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (window == NULL)
		return (EXIT_FAILURE);
	game->mlx = mlx;
	game->win = window;
	return (EXIT_SUCCESS);
}

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
		// destory img_3d
		return (EXIT_FAILURE);
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
		// destory img_2d
		return (EXIT_FAILURE);
	img_2d->img = img;
	img_2d->addr = addr;
	return (EXIT_SUCCESS);
}

static int	init_cube_contents(t_game *game, char *filename)
{
	char	*file_contents;
	int		status;

	file_contents = read_cubfile(filename);
	if (file_contents == NULL)
		return (EXIT_FAILURE);
	status = parse_cubfile(game, file_contents);
	free(file_contents);
	if (status != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief Initialize Cub3d game
 */
int	init_game(t_game *game, int argc, char *argv[])
{
	if (arg_check(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_debug_info(game) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_mlx_and_window(game) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_3d_image(game->mlx, &game->img_3d) != EXIT_SUCCESS)
	{
		// destroy window
		return (EXIT_FAILURE);
	}
	if (init_2d_image(game->mlx, &game->img_2d) != EXIT_SUCCESS)
	{
		// destroy window & 3d_image
		return (EXIT_FAILURE);
	}
	if (init_cube_contents(&game, argv[1]) != EXIT_SUCCESS)
	{
		// destroy window & 3d_image & 2d_image
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
