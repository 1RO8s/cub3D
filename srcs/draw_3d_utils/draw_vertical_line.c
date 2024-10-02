/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:47:33 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 17:29:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw the vertical line from wall_slice ( draw_start to draw_end )
 */
void	draw_vertical_line(t_one_shot_3d *one_shot_3d, int x)
{
	int				y;
	t_wall_slice	wall_slice;
	t_img			img_3d;

	wall_slice = (t_wall_slice)one_shot_3d->wall_slice;
	img_3d = (t_img)one_shot_3d->img_3d;
	if (x < 0 || x >= IMG_3D_WIDTH)
		return ;
	if (wall_slice.draw_start < 0)
		wall_slice.draw_start = 0;
	if (wall_slice.draw_end >= WIN_HEIGHT)
		wall_slice.draw_end = WIN_HEIGHT - 1;
	y = wall_slice.draw_start;
	while (y <= wall_slice.draw_end)
	{
		my_mlx_pixel_put(&img_3d, x, y, wall_slice.color);
		y++;
	}
}
