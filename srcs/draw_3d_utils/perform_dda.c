/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:33:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/10 11:27:31 by kamitsui         ###   ########.fr       */
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
		if (ray_cast->sideDistX < ray_cast->sideDistY)
		{
			ray_cast->sideDistX += ray_cast->deltaDistX;
			ray_cast->mapX += ray_cast->stepX;
			ray_cast->side = 0;
		}
		else
		{
			ray_cast->sideDistY += ray_cast->deltaDistY;
			ray_cast->mapY += ray_cast->stepY;
			ray_cast->side = 1;
		}
		if (map->data[ray_cast->mapY][ray_cast->mapX] == '1')
			hit = 1;
		//if ( .... )
		// break;
	}
	if (ray_cast->side == 0)
		ray_cast->perpWallDist = (ray_cast->mapX - player->x + (1 - ray_cast->stepX) / 2) / ray_cast->rayDirX;
	else
		ray_cast->perpWallDist = (ray_cast->mapY - player->y + (1 - ray_cast->stepY) / 2) / ray_cast->rayDirY;
}
