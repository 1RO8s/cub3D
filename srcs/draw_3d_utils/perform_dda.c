/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:33:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/30 15:46:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_line_type(t_ray_cast ray_cast)
{
	if (ray_cast.next_distance.x < ray_cast.next_distance.y)
		return (ON_VERTICAL_LINE);
	else
		return (ON_HORIZONTAL_LINE);
}

static bool	is_hit_wall(t_map *map, t_ray_cast *ray_cast)
{
	return (map->data[ray_cast->grid.y][ray_cast->grid.x] == '1');
}

static void	move_next_grid_line(t_ray_cast *ray_cast, int type)
{
	if (type == ON_VERTICAL_LINE)
	{
		ray_cast->next_distance.x += ray_cast->delta_distance.x;
		ray_cast->grid.x += ray_cast->step_dir.x;
	}
	else
	{
		ray_cast->next_distance.y += ray_cast->delta_distance.y;
		ray_cast->grid.y += ray_cast->step_dir.y;
	}
}

static double	calculate_distance(t_ray_cast ray_cast, int type)
{
	if (type == ON_VERTICAL_LINE)
		return (ray_cast.next_distance.x - ray_cast.delta_distance.x);
	else
		return (ray_cast.next_distance.y - ray_cast.delta_distance.y);
}

/**
 * @brief Digital Differential Analysis (DDA) Loop
 * @note
 * The DDA algorithm incrementally steps through a grid
 * to determine the intersection points with lines or rays.
 */
void	perform_dda(t_frame *frame, int x)
{
	bool		hit;
	int			type;

	hit = false;
	type = START_POINT;
	while (hit == 0)
	{
		type = get_line_type(frame->ray_cast);
		move_next_grid_line(&frame->ray_cast, type);
		hit = is_hit_wall(frame->map, &frame->ray_cast);
	}
	frame->dda.type_of_grid_line = type;
	frame->dda.perp_wall_dist = calculate_distance(frame->ray_cast, type);
	(void)x;
}
// debug code
//{
//	bool		hit;
//	int			type;
//
//	hit = false;
//	type = START_POINT;
//	debug_dda(frame, type, "perform_dda() ... start");
//	while (hit == 0)
//	{
//		type = get_line_type(frame->ray_cast);
//		move_next_grid_line(&frame->ray_cast, type);
//		hit = is_hit_wall(frame->map, &frame->ray_cast);
//		debug_dda(frame, type, "perform_dda() ... loop until hit wall");
//	}
//	frame->dda.type_of_grid_line = type;
//	frame->dda.perp_wall_dist = calculate_distance(frame->ray_cast, type);
//	(void)x;
//}
// reference cub3d.h 
//# define START_POINT -1
//# define ON_VERTICAL_LINE 0
//# define ON_HORIZONTAL_LINE 1
