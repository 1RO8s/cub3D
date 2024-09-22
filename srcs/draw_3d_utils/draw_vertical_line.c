/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:47:33 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/10 10:40:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw the vertical line from wall_slice ( drawStart to drawEnd )
 */
void	draw_vertical_line(t_img *img, int x, t_wall_slice *wall_slice)
{
	int	y;

	if (x < 0 || x >= WIN_WIDTH / 2)
		return ;
	if (wall_slice->drawStart < 0)
		wall_slice->drawStart = 0;
	if (wall_slice->drawEnd >= WIN_HEIGHT)
		wall_slice->drawEnd = WIN_HEIGHT - 1;
	y = wall_slice->drawStart;
	while (y <= wall_slice->drawEnd)
	{
		my_mlx_pixel_put(img, x, y, wall_slice->color);
		y++;
	}
}
