/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:17:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/26 15:10:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_2d_wall_one_place(int x, int y, t_game *game)
{
	int	start_x;
	int start_y;
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
			// White for walls
			my_mlx_pixel_put(
				&game->img_2d, start_x + i, start_y + j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	    }
	}
}

static bool	is_wall_position(char map_point)
{
	return (map_point == '1');
}

void draw_2d_wall(t_game *game)
{
	int	x;
	int	y;
	
	// Draw the map
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
            if (is_wall_position(game->map[y][x]) == true)
				draw_2d_wall_one_place(game, x, y);
			x++;
		}
		y++;
	}
}
