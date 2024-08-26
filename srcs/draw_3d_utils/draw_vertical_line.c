/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:47:33 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/26 22:52:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw the vertical line from wall_slice ( drawStart to drawEnd )
 */
void	draw_vertical_line(t_img *img, int x, t_wall_slice *wall_slice)
{
    if (x < 0 || x >= WIN_WIDTH / 2)
        return;
    if (drawStart < 0)
		drawStart = 0;
    if (drawEnd >= WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
    int y;
	y = drawStart;
	while (y <= drawEnd)
	{
        my_mlx_pixel_put(img, x, y, color);
		y++;
    }
}
