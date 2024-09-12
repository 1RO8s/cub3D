/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 15:52:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_camera_plane_and_ray_dir(int fd, t_ray_cast ray_cast)
{
	ft_dprintf(fd, "X-cordinate on the camera plane (-1.0 to 1.0)\n");
	ft_dprintf(fd, "\tcamera_plane_x = [%f]\n", ray_cast.camera_plane_x);
	ft_dprintf(fd, "Direction in the ray vector ... double\n");
	ft_dprintf(fd, "\tray_dir.x = [%f]\n", ray_cast.ray_dir.x);
	ft_dprintf(fd, "\tray_dir.y = [%f]\n", ray_cast.ray_dir.y);
}

static void	debug_grid_and_nex_side(int fd, t_ray_cast ray_cast)
{
	ft_dprintf(fd, "Current grid position (x, y) ... int\n");
	ft_dprintf(fd, "\tgrid.x = [%d]\n", ray_cast.grid.x);
	ft_dprintf(fd, "\tgrid.y = [%d]\n", ray_cast.grid.y);
	ft_dprintf(fd, "Distance to the next side ... double\n");
	ft_dprintf(fd, "\tnext_side.x = [%f]\n", ray_cast.next_side.x);
	ft_dprintf(fd, "\tnext_side.y = [%f]\n", ray_cast.next_side.y);
	ft_dprintf(fd, "Distance between grid to next_side ... double   ???\n");
	ft_dprintf(fd, "\tdelta_distance = [%f]\n", ray_cast.delta_distance.x);
	ft_dprintf(fd, "\tdelta_distance = [%f]\n", ray_cast.delta_distance.y);
	ft_dprintf(fd, "Step direction in X, Y (-1 or 1) ... int\n");
	ft_dprintf(fd, "\tstepX = [%d]\n", ray_cast.step.x);
	ft_dprintf(fd, "\tstepY = [%d]\n", ray_cast.step.y);
}

void	debug_ray_cast(t_ray_cast ray_cast, const char *msg)
{
	int	fd;

	if (IS_DEBUG != true)
		return ;
	fd = open_log(LOG_FILE, O_APPEND);
	if (fd == -1)
		exit(1);
	ft_dprintf(fd, "\n>> call by '%s'\n", msg);
	ft_dprintf(fd, "\tx [%d], window_width / 2 [%f]\n", x, (double)(WIN_WIDTH / 2));
	ft_dprintf(fd, "---- ray_cast ----\n");
	debug_camera_plane_and_ray_dir(fd, ray_cast);
	debug_grid_and_next_side(fd, ray_cast);
	ft_dprintf(fd, "Is hit the wall ?\n");
	ft_dprintf(fd, "\thit = [%d]\n", ray_cast.hit);
	ft_dprintf(fd, "Is NS or EW wall hit ?\n");
	ft_dprintf(fd, "\tside = [%d]\n", ray_cast.side);
	ft_dprintf(fd, "Perpendicular distance to the wall ... double\n");
	ft_dprintf(fd, "\tperp_wall_dist = [%f]\n", ray_cast.perp_wall_dist);
	if (close(fd) == -1)
		exit(1);
}
