/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:33:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/26 22:33:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void perform_dda(t_ray *ray, t_game *game)
{
	bool	hit;
	int		map_x;
	int		map_y;

	hit = false;
    while (hit == 0) {
        if (ray->sideDistX < ray->sideDistY) {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
        } else {
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
        }

        if (game->map[ray->mapY][ray->mapX] == '1')
            hit = 1;
    }

    if (ray->side == 0)
        ray->perpWallDist = (ray->mapX - game->player_x + (1 - ray->stepX) / 2) / ray->rayDirX;
    else
        ray->perpWallDist = (ray->mapY - game->player_y + (1 - ray->stepY) / 2) / ray->rayDirY;
}
