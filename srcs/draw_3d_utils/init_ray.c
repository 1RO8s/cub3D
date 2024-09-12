/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:32:18 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 15:52:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief set distance (next_side) and step_dir
 *
 * @note step_dir is direction in which the ray will step along the x,y axes.
 */
static void	set_ray_will_step_along(t_ray_cast *ray_cast)
{
	ray_cast->hit = 0;
	if (ray_cast->ray_dir.x < 0)
	{
		ray_cast->step_dir.x = -1;
		ray_cast->next_side.x
			= (player->x - ray_cast->grid.x) * ray_cast->delta_distance.x;
	}
	else
	{
		ray_cast->step_dir.x = 1;
		ray_cast->next_side.x
			= (ray_cast->grid.x + 1.0 - player->x) * ray_cast->delta_distance.x;
	}
	if (ray_cast->ray_dir.y < 0)
	{
		ray_cast->step_dir.y = -1;
		ray_cast->next_side.y
			= (player->y - ray_cast->grid.y) * ray_cast->delta_distance.y;
	}
	else
	{
		ray_cast->step_dir.y = 1;
		ray_cast->next_side.y
			= (ray_cast->grid.y + 1.0 - player->y) * ray_cast->delta_dist.y;
	}
}

static void	set_delta_distance(t_ray_cast *ray_cast)
{
	if (ray_cast->ray_dir.x == 0)
		ray_cast->delta_distance.x = 1e30;
	else
		ray_cast->delta_distance.x = fabs(1 / ray_cast->ray_dir.x);
	if (ray_cast->ray_dir.y == 0)
		ray_cast->delta_distance.y = 1e30;
	else
		ray_cast->delta_distance.y = fabs(1 / ray_cast->ray_dir.y);
}

/**
 * @brief initialize t_ray_cast for perspective (represent 3D object)
 *
 * @note 
 *
 * member
 * camera_plane_x: x-coordinate on the camera plane (-1 to 1)
 * ray_dir:        Ray Direction
 * grid:           current grid position
 * next_side:      distance to next x-side or y-side
 * delta_distance: used to incrementally move the ray across the grid
 * perpWallDist:   Perpendicular distance to the wall
 * step_dir:       step direction will xxx along
 * hit:            Whether a wall was hit
 * side:           Was a NS or EW wall hit?
 *
 * plane:          FOV (field of view) / 2
 */
void	init_ray(t_ray_cast *ray_cast, t_player *player, int x)
{
	t_vector	view_point;
	t_vector	ray_dir;
	t_vector	camera_forcal_plane;

	ray_cast->camera_plane_x = 2 * x / (double)(WIN_WIDTH / 2) - 1;
	view_point = player->view_point;
	camera_forcal_plane = player->camera_forcal_plane;
	ray_cast->ray_dir.x
		= view_point.x + camera_forcal_plane.x * ray_cast->camera_plane_x;
	ray_cast->ray_dir.y = ray_dir.y + plane_y * ray_cast->camera_plane_x;
	ray_cast->grid.x = (int)view_point->x;
	ray_cast->grid.y = (int)view_point->y;
	set_delta_distance(ray_cast);
	set_ray_will_step_along(ray_cast);
}
