/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/31 22:16:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_slice(t_wall_slice	*wall_slice, t_ray *ray)
{
    int	h;
	int	lineHeight;
//	int	color;
	
	h = WIN_HEIGHT;
	lineHeight = (int)(h / ray->perpWallDist);
	wall_slice->drawStart = -lineHeight / 2 + h / 2;
	wall_slice->drawEnd = lineHeight / 2 + h / 2;
	if (wall_slice->drawStart < 0)
		wall_slice->drawStart = 0;
	if (wall_slice->drawEnd >= h)
		wall_slice->drawEnd = h - 1;
	if (ray->side == 1)
		wall_slice->color = 0xAAAAAA;  // Grey for north-south walls
	else
		wall_slice->color = 0xFFFFFF;            // White for east-west walls
}
