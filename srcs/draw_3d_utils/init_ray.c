/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:32:18 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/28 00:19:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_ray(t_ray *ray, t_player *player, int x)
{
	ray->cameraX = 2 * x / (double)(WIN_WIDTH / 2) - 1;
	ray->rayDirX = player->dir_x + player->plane_x * ray->cameraX;
	ray->rayDirY = player->dir_y + player->plane_y * ray->cameraX;
	// here?
	ray->mapX = (int)player->x;
	ray->mapY = (int)player->y;

	ray->deltaDistX = (ray->rayDirX == 0) ? 1e30 : fabs(1 / ray->rayDirX);
	ray->deltaDistY = (ray->rayDirY == 0) ? 1e30 : fabs(1 / ray->rayDirY);
	ray->hit = 0;
	if (ray->rayDirX < 0)
	{
	    ray->stepX = -1;
	    ray->sideDistX = (player->x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player->x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
	    ray->stepY = -1;
	    ray->sideDistY = (player->y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
	    ray->stepY = 1;
	    ray->sideDistY = (ray->mapY + 1.0 - player->y) * ray->deltaDistY;
	}
}
