/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:32:18 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/22 11:02:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_x_side(t_ray_cast *ray_cast, t_vector *view_point)
{
	t_point		grid;
	t_vector	delta_distance;

	grid = ray_cast->grid;
	delta_distance = ray_cast->delta_distance;
	if (ray_cast->ray_dir.x < 0)
	{
		ray_cast->step_dir.x = -1;
		ray_cast->next_distance.x
			= (view_point->x - (double)grid.x) * delta_distance.x;
	}
	else
	{
		ray_cast->step_dir.x = 1;
		ray_cast->next_distance.x
			= ((double)grid.x + 1.0 - view_point->x) * delta_distance.x;
	}
}

static void	set_y_side(t_ray_cast *ray_cast, t_vector *view_point)
{
	t_point		grid;
	t_vector	delta_distance;

	grid = ray_cast->grid;
	delta_distance = ray_cast->delta_distance;
	if (ray_cast->ray_dir.y < 0)
	{
		ray_cast->step_dir.y = -1;
		ray_cast->next_distance.y
			= (view_point->y - (double)grid.y) * delta_distance.y;
	}
	else
	{
		ray_cast->step_dir.y = 1;
		ray_cast->next_distance.y
			= ((double)grid.y + 1.0 - view_point->y) * delta_distance.y;
	}
}

/**
 * @brief set distance and direction for using dda algorithm
 *
 * @note
 *  next_distance is distance until next grid line
 *  step_dir is direction in which the ray will step along the x,y axes.
 */
static void	set_direction_and_distance_for_dda(
				t_ray_cast *ray_cast, t_vector *view_point)
{
	set_x_side(ray_cast, view_point);
	set_y_side(ray_cast, view_point);
}

static t_vector	get_delta_distance(t_ray_cast ray_cast)
{
	t_vector	delta_distance;

	if (ray_cast.ray_dir.x == 0)
		delta_distance.x = 1e30;
	else
		delta_distance.x = fabs(1 / ray_cast.ray_dir.x);
	if (ray_cast.ray_dir.y == 0)
		delta_distance.y = 1e30;
	else
		delta_distance.y = fabs(1 / ray_cast.ray_dir.y);
	return ((t_vector)delta_distance);
}

/**
 * @brief initialize t_ray_cast for perspective (represent 3D object)
 * reference t_ray_cast
 * camera_plane_x : normalized (-1 ~ 1) on the camera plane
 * ray_dir : directon of x coordinate on the camera plane
 * grid : map cordinate (int value) ... map->data[grid.y][grid.x]
 * step_dir : direction for next grid ... -1 or 1 (both step_dir.x, step_dir.y)
 * next_distance : distance to next x-side(HORIZONTAL_LINE) or
 *  y-side(VERTICAL_LINE)
 * delta_distance : used to incrementally move the ray across the grid
 */
void	init_ray(t_frame *frame, int x)
{
	t_ray_cast	ray_cast;
	t_vector	camera_forcal_plane;
	t_vector	ray_dir;

	camera_forcal_plane = frame->player->camera_forcal_plane;
	ray_dir = frame->player->ray_dir;
	ray_cast.camera_plane_x = 2 * x / (double)IMG_3D_WIDTH - 1;
	ray_cast.ray_dir.x
		= ray_dir.x + camera_forcal_plane.x * ray_cast.camera_plane_x;
	ray_cast.ray_dir.y
		= ray_dir.y + camera_forcal_plane.y * ray_cast.camera_plane_x;
	ray_cast.grid.x = (int)frame->player->view_point.x;
	ray_cast.grid.y = (int)frame->player->view_point.y;
	ray_cast.delta_distance = (t_vector)get_delta_distance(ray_cast);
	set_direction_and_distance_for_dda(&ray_cast, &frame->player->view_point);
	frame->ray_cast = ray_cast;
	//debug_ray_cast(frame, "after init_ray()", x);
}
