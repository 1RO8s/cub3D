/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:47:33 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/26 20:16:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw the vertical line from wall_slice ( draw_start to draw_end )
 */
void	draw_vertical_line(t_img *img, int x, t_wall_slice *wall_slice)
{
	int	y;

	if (x < 0 || x >= WIN_WIDTH / 2)
		return ;
	if (wall_slice->draw_start < 0)
		wall_slice->draw_start = 0;
	if (wall_slice->draw_end >= WIN_HEIGHT)
		wall_slice->draw_end = WIN_HEIGHT - 1;
	y = wall_slice->draw_start;
	while (y <= wall_slice->draw_end)
	{
		my_mlx_pixel_put(img, x, y, wall_slice->color);
		y++;
	}
}
