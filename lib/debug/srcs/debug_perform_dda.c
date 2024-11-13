/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_perform_dda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:52:26 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/14 02:22:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_ray_cast(int fd, t_ray_cast ray_cast)
{
	char	str[SIZE_DOUBLE_TO_STR];

	double_to_string(ray_cast.next_distance.x, str, sizeof(str));
	ft_dprintf(fd, "\tnext_distance.x[%s] grid.x[%d]", str, ray_cast.grid.x);
	double_to_string(ray_cast.next_distance.y, str, sizeof(str));
	ft_dprintf(fd, "\tnext_distance.y[%s] grid.y[%d]", str, ray_cast.grid.y);
}

/**
 * @brief print out next step through grid line
 */
void	debug_dda(t_frame *frame, int type, const char *msg)
{
	int			fd;
	t_ray_cast	ray_cast;

	if (IS_DEBUG != true)
		return ;
	fd = frame->debug.fd;
	ray_cast = frame->ray_cast;
	if (ray_cast.grid.x == (int)frame->player->view_point.x
		&& ray_cast.grid.y == (int)frame->player->view_point.y)
	{
		ft_dprintf(fd, "\n>>> func debug_dda() ... call by '%s' <<<\n", msg);
	}
	ft_dprintf(fd,
		"type[%d] ... 0:VERTICAL\t1:HORIZONTAL\t-1:START\n", type);
	put_ray_cast(fd, ray_cast);
}

/**
 * @brief print out map->data[y][x], and is_hit value
 */
void	debug_is_hit_wall(t_frame *frame)
{
	int			fd;
	bool		is_hit;
	t_map		*map;
	t_ray_cast	ray_cast;

	if (IS_DEBUG != true)
		return ;
	fd = frame->debug.fd;
	map = (t_map *)frame->map;
	ray_cast = (t_ray_cast)frame->ray_cast;
	is_hit = (map->data[ray_cast.grid.y][ray_cast.grid.x] == '1');
	ft_dprintf(fd, "\tmap->data[%d][%d] = '%d'\n",
		ray_cast.grid.y, ray_cast.grid.x, is_hit);
}
