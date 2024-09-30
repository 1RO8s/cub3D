/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:33:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 16:27:24 by kamitsui         ###   ########.fr       */
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
 *
 * @note
 * The DDA algorithm incrementally steps through a grid
 * to determine the intersection points with lines or rays.
 */
void	perform_dda(t_one_shot_3d *one_shot_3d, int x)
{
	bool	hit;
	int		type;
	t_ray_cast	ray_cast;
	t_map		map;

	hit = false;
	type = -1;
	ray_cast = one_shot_3d->ray_cast;
	map = one_shot_3d->map;
	debug_dda(one_shot_3d, type, "perform_dda() ... start");// debug
	while (hit == 0)
	{
		type = get_line_type(ray_cast);
		move_next_grid_line(&ray_cast, type);
		hit = is_hit_wall(&map, &ray_cast);
		debug_dda(one_shot_3d, type, "perform_dda() ... loop until hit wall");// debug
	}
	one_shot_3d->dda.type_of_grid_line = type;
	one_shot_3d->dda.perp_wall_dist = calculate_distance(ray_cast, type);
	(void)x;
}
