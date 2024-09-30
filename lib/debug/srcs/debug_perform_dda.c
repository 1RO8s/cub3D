/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_perform_dda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:52:26 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 11:15:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief print out next step through grid line
 */
void	debug_dda(t_ray_cast *ray_cast, t_player *player, const char *msg)
{
	int	fd;

	if (IS_DEBUG != true)
		return ;
	fd = ray_cast->debug->fd;
	if (ray_cast->grid.x == (int)player->view_point.x
		&& ray_cast->grid.y == (int)player->view_point.y)
	{
		dprintf(fd, "\n>>> func debug_dda() ... call by '%s' <<<\n", msg);
	}
	dprintf(fd, "grid_line[%d] ... 0:VERTICAL\t1:HORIZONTAL\t-1:START\n",
		ray_cast->grid_line);
	dprintf(fd, "\tnext_side.x[%f] grid.x[%d]\n",
		ray_cast->next_side.x, ray_cast->grid.x);
	dprintf(fd, "\tnext_side.y[%f] grid.y[%d]\n",
		ray_cast->next_side.y, ray_cast->grid.y);
}

/**
 * @brief print out map->data[y][x], and is_hit value
 */
void	debug_is_hit_wall(t_map *map, t_ray_cast *ray_cast)
{
	int	fd;
	bool	is_hit;

	if (IS_DEBUG != true)
		return ;
	fd = ray_cast->debug->fd;
	is_hit = (map->data[ray_cast->grid.y][ray_cast->grid.x] == '1');
	dprintf(fd, "\tmap->data[%d][%d] = '%d'\n",
		ray_cast->grid.y, ray_cast->grid.x, is_hit);
}
