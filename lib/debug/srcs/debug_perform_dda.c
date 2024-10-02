/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_perform_dda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:52:26 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/01 02:45:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief print out next step through grid line
 */
void	debug_dda(t_one_shot_3d *one_shot_3d, int type, const char *msg)
{
	int			fd;
	t_ray_cast	ray_cast;

	if (IS_DEBUG != true)
		return ;
	fd = one_shot_3d->debug.fd;
	ray_cast = one_shot_3d->ray_cast;
	if (ray_cast.grid.x == (int)one_shot_3d->player.view_point.x
		&& ray_cast.grid.y == (int)one_shot_3d->player.view_point.y)
	{
		dprintf(fd, "\n>>> func debug_dda() ... call by '%s' <<<\n", msg);
	}
	dprintf(fd,
		"type[%d] ... 0:VERTICAL\t1:HORIZONTAL\t-1:START\n", type);
	dprintf(fd, "\tnext_distance.x[%f] grid.x[%d]\n",
		ray_cast.next_distance.x, ray_cast.grid.x);
	dprintf(fd, "\tnext_distance.y[%f] grid.y[%d]\n",
		ray_cast.next_distance.y, ray_cast.grid.y);
}

/**
 * @brief print out map->data[y][x], and is_hit value
 */
void	debug_is_hit_wall(t_one_shot_3d *one_shot_3d)
{
	int			fd;
	bool		is_hit;
	t_map		map;
	t_ray_cast	ray_cast;

	if (IS_DEBUG != true)
		return ;
	fd = one_shot_3d->debug.fd;
	map = (t_map)one_shot_3d->map;
	ray_cast = (t_ray_cast)one_shot_3d->ray_cast;
	is_hit = (map.data[ray_cast.grid.y][ray_cast.grid.x] == '1');
	dprintf(fd, "\tmap.data[%d][%d] = '%d'\n",
		ray_cast.grid.y, ray_cast.grid.x, is_hit);
}
