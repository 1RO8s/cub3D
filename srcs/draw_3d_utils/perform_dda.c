/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:33:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/13 16:46:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Digital Differential Analysis (DDA) Loop
//  * Incrementally checks each grid square
//    along the ray’s path until it hits a wall ('1' in the map data).
//  * Depending on whether the ray moves more in the x or y direction,
//    either sideDixtX or sideDistY is incremented.
void	perform_dda(t_ray_cast *ray_cast, t_map *map, t_player *player)
{
	bool	hit;

	hit = false;
	while (hit == 0)
	{
		if (ray_cast->next_side.x < ray_cast->next_side.y)
		{
			ray_cast->next_side.x += ray_cast->delta_distance.x;
			ray_cast->grid.x += ray_cast->step_dir.x;
			ray_cast->side = 0;
		}
		else
		{
			ray_cast->next_side.y += ray_cast->delta_distance.y;
			ray_cast->grid.y += ray_cast->step_dir.y;
			ray_cast->side = 1;
		}
		if (map->data[ray_cast->grid.y][ray_cast->grid.y] == '1')
			hit = 1;
		//if ( .... )
		// break;
	}
	if (ray_cast->side == 0)
		ray_cast->perp_wall_dist = (ray_cast->grid.x - player->view_point.x + (1 - ray_cast->step_dir.x) / 2) / ray_cast->ray_dir.x;
	else
		ray_cast->perp_wall_dist = (ray_cast->grid.y - player->view_point.y + (1 - ray_cast->step_dir.y) / 2) / ray_cast->ray_dir.y;
}
