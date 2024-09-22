/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/13 21:49:47 by kamitsui         ###   ########.fr       */
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

static void	debug_grid_and_next_side(int fd, t_ray_cast ray_cast)
{
	dprintf(fd, "Current grid position (x, y) ... int\n");
	dprintf(fd, "\tgrid.x = [%d]\n", ray_cast.grid.x);
	dprintf(fd, "\tgrid.y = [%d]\n", ray_cast.grid.y);
	dprintf(fd, "Distance to the next side ... double\n");
	dprintf(fd, "\tnext_side.x = [%f]\n", ray_cast.next_side.x);
	dprintf(fd, "\tnext_side.y = [%f]\n", ray_cast.next_side.y);
	dprintf(fd, "Distance between grid to next_side ... double   ???\n");
	dprintf(fd, "\tdelta_distance = [%f]\n", ray_cast.delta_distance.x);
	dprintf(fd, "\tdelta_distance = [%f]\n", ray_cast.delta_distance.y);
	dprintf(fd, "Step direction in X, Y (-1 or 1) ... int\n");
	dprintf(fd, "\tstepX = [%d]\n", ray_cast.step_dir.x);
	dprintf(fd, "\tstepY = [%d]\n", ray_cast.step_dir.y);
}

void	debug_ray_cast(t_ray_cast ray_cast, const char *msg, int x)
{
	int	fd;

	if (IS_DEBUG != true)
		return ;
	fd = ray_cast.debug->fd;
	dprintf(fd, "\n>> call by '%s'\n", msg);
	dprintf(fd, "\tx [%d], window_width / 2 [%f]\n", x, (double)(WIN_WIDTH / 2));
	dprintf(fd, "---- ray_cast ----\n");
	debug_camera_plane_and_ray_dir(fd, ray_cast);
	debug_grid_and_next_side(fd, ray_cast);
	dprintf(fd, "Is hit the wall ?\n");
	dprintf(fd, "\thit = [%d]\n", ray_cast.hit);
	dprintf(fd, "Is NS or EW wall hit ?\n");
	dprintf(fd, "\tside = [%d]\n", ray_cast.side);
	dprintf(fd, "Perpendicular distance to the wall ... double\n");
	dprintf(fd, "\tperp_wall_dist = [%f]\n", ray_cast.perp_wall_dist);
}
