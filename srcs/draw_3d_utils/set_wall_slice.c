/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/10 11:25:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_slice(t_wall_slice	*wall_slice, t_ray_cast *ray_cast)
{
	int	h;
	int	line_height;

	h = WIN_HEIGHT;
	line_height = (int)(h / ray_cast->perpWallDist);
	wall_slice->drawStart = -line_height / 2 + h / 2;
	wall_slice->drawEnd = line_height / 2 + h / 2;
	if (wall_slice->drawStart < 0)
		wall_slice->drawStart = 0;
	if (wall_slice->drawEnd >= h)
		wall_slice->drawEnd = h - 1;
	if (ray_cast->side == 1)
		wall_slice->color = COLOR_GREY; // north-south walls
	else
		wall_slice->color = COLOR_WHITE; // east-west walls
}
// unfinish refactoring
