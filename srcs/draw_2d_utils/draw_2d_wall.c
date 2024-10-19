/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:17:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/20 02:44:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_2d_wall_one_place(t_img *img_2d, int x, int y)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = x * MAP_SCALE;
	start_y = y * MAP_SCALE;
	i = 0;
	while (i < MAP_SCALE)
	{
		j = 0;
		while (j < MAP_SCALE)
		{
			my_mlx_pixel_put(img_2d, start_x + i, start_y + j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

static bool	is_wall_position(char map_point)
{
	return (map_point == '1');
}

void	draw_2d_wall(t_map *map, t_img *img_2d)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_wall_position(map->data[y][x]) == true)
				draw_2d_wall_one_place(img_2d, x, y);
			x++;
		}
		y++;
	}
}
