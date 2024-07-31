/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:09:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/04 21:48:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ft_printf.h"
#include "fdf.h"

static int	close_window(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->map->rows)
	{
		free(fdf->points[i]);
		i++;
	}
	free(fdf->points);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_data->img);
	exit(0);
}

static int	my_key_function(int keycode, t_fdf *fdf)
{
	int		i;

	if (keycode == KEY_ESC)
	{
		i = 0;
		while (i < fdf->map->rows)
		{
			free(fdf->points[i]);
			i++;
		}
		free(fdf->points);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_data->img);
		exit(0);
	}
	return (0);
}

static void	error_arg(char *program_name)
{
	ft_printf("Usage : %s <filename> [ case_size z_size ]\n", program_name);
	exit (1);
}

int	main(int ac, char *av[])
{
	t_fdf	fdf;
	t_data	data;
	t_Map	map;

	fdf.img_data = &data;
	fdf.map = &map;
	if (ac != 2)
		error_arg(av[0]);
	read_map(av[1], &fdf);
	fdf.mlx_ptr = mlx_init();
	if (fdf.mlx_ptr == NULL)
		error_fdf(ERR_MLX);
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, NAME);
	if (fdf.win_ptr == NULL)
		error_fdf(ERR_WIN);
	data.img = mlx_new_image(fdf.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.size_line, &data.endian);
	draw_wireframe_model(&data, fdf.points, fdf.map->rows, fdf.map->cols);
	mlx_clear_window(fdf.mlx_ptr, fdf.win_ptr);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, data.img, WIN_X, WIN_Y);
	mlx_key_hook(fdf.win_ptr, &my_key_function, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
//	mlx_hook(fdf.win_ptr, 17, 1L << 0, close_window, &fdf);
//	ft_printf("Bits per pixel: %d\n", data.bits_per_pixel);
//	ft_printf("Size of each line: %d bytes\n", data.size_line);
//	ft_printf("Endianness: %d\n", data.endian);
//#include <keysymdef.h> // not found file
