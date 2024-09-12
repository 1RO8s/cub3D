/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:50:44 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 12:02:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx_and_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
}

static void	init_3d_image(void *mlx, t_img *img_3d)
{
	void	*img_ptr;
	char	*addr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;

	img_3d->img = mlx_new_image(mlx, WIN_WIDTH / 2, WIN_HEIGHT);
	bits_per_pixel = &img_3d->bpp;
	size_line = &img_3d->line_length;
	endian = &img_3d->endian;
	addr = mlx_get_data_addr(img_ptr, bits_per_pixel, size_line, endian);
	img_3d->img = img_ptr;
	img_3d->addr = addr;
}

static void	init_2d_image(void *mlx, t_img *img_2d)
{
	void	*img_ptr;
	char	*addr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;

	img_2d->img = mlx_new_image(mlx, WIN_WIDTH / 2, WIN_HEIGHT);
	bits_per_pixel = &img_2d->bpp;
	size_line = &img_2d->line_length;
	endian = &img_2d->endian;
	addr = mlx_get_data_addr(img_ptr, bits_per_pixel, size_line, endian);
	img_2d->img = img_ptr;
	img_2d->addr = addr;
}

/**
 * @brief Initialize Cub3d game
 */
int	init_game(t_game *game, int argc, char *argv[])
{
	if (argc != 2)
		return (EXIT_FAILURE);
	init_mlx_window(game);
	init_3d_image(game->mlx, game->img_3d);
	init_2d_image(game->mlx, game->img_2d);
	read_map_data(game->map);
	// Parse the map to find the player's initial position and direction
	parse_map(&game->map, &game->player);
	return (EXIT_SUCCESS);
}
