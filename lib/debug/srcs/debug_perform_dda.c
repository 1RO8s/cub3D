/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_perform_dda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:52:26 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 13:43:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_ray_cast(int fd, t_ray_cast ray_cast)
{
	int	original_stdout_fd;

	original_stdout_fd = set_stdout_fd(fd);
	printf("\tnext_distance.x[%f] grid.x[%d]\n",
		ray_cast.next_distance.x, ray_cast.grid.x);
	printf("\tnext_distance.y[%f] grid.y[%d]\n",
		ray_cast.next_distance.y, ray_cast.grid.y);
	if (dup2(original_stdout_fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	close(original_stdout_fd);
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
		dprintf(fd, "\n>>> func debug_dda() ... call by '%s' <<<\n", msg);
	}
	dprintf(fd,
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
	dprintf(fd, "\tmap->data[%d][%d] = '%d'\n",
		ray_cast.grid.y, ray_cast.grid.x, is_hit);
}
