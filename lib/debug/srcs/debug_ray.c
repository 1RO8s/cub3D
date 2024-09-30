/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 17:32:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_camera_plane_and_ray_dir(int fd, t_ray_cast ray_cast)
{
	dprintf(fd, "X-cordinate on the camera plane (-1.0 to 1.0)\n");
	dprintf(fd, "\tcamera_plane_x = [%f]\n", ray_cast.camera_plane_x);
	dprintf(fd, "Direction in the ray vector ... double\n");
	dprintf(fd, "\tray_dir.x = [%f]\n", ray_cast.ray_dir.x);
	dprintf(fd, "\tray_dir.y = [%f]\n", ray_cast.ray_dir.y);
}

static void	debug_grid_and_next_distance(int fd, t_ray_cast ray_cast)
{
	dprintf(fd, "Current grid position (x, y) ... int\n");
	dprintf(fd, "\tgrid.x = [%d]\n", ray_cast.grid.x);
	dprintf(fd, "\tgrid.y = [%d]\n", ray_cast.grid.y);
	dprintf(fd, "Step direction in X, Y (-1 or 1) ... int\n");
	dprintf(fd, "\tstep_dir.x = [%d]\n", ray_cast.step_dir.x);
	dprintf(fd, "\tstep_dir.y = [%d]\n", ray_cast.step_dir.y);
	dprintf(fd, "Distance to the next side ... double\n");
	dprintf(fd, "\tnext_distance.x = [%f]\n", ray_cast.next_distance.x);
	dprintf(fd, "\tnext_distance.y = [%f]\n", ray_cast.next_distance.y);
	dprintf(fd, "Distance between grid to next_distance ... double\n");
	dprintf(fd, "\tdelta_distance = [%f]\n", ray_cast.delta_distance.x);
	dprintf(fd, "\tdelta_distance = [%f]\n", ray_cast.delta_distance.y);
}

void	debug_ray_cast(t_one_shot_3d *one_shot_3d, const char *msg, int x)
{
	int	fd;
	t_ray_cast	ray_cast;

	if (IS_DEBUG != true)
		return ;
	fd = one_shot_3d->debug.fd;
	ray_cast = one_shot_3d->ray_cast;
	dprintf(fd, "\n>>> func debug_ray_cast() ... call by '%s' <<<\n", msg);
	dprintf(fd, "\tx [%d], window_width / 2 [%f]\n", x, (double)IMG_3D_WIDTH);
	dprintf(fd, "---- ray_cast ----\n");
	debug_camera_plane_and_ray_dir(fd, ray_cast);
	debug_grid_and_next_distance(fd, ray_cast);
	dprintf(fd, "\n\n");
}
