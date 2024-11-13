/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/14 01:59:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_camera_plane_and_ray_dir(int fd, t_ray_cast ray_cast)
{
	char	str[32];

	ft_dprintf(fd, "X-cordinate on the camera plane (-1.0 to 1.0)\n");
	double_to_string(ray_cast.camera_plane_x, str, sizeof(str));
	ft_dprintf(fd, "\tcamera_plane_x = [%d]\n", str);
	ft_dprintf(fd, "Direction in the ray vector ... double\n");
	double_to_string(ray_cast.ray_dir.x, str, sizeof(str));
	ft_dprintf(fd, "\tray_dir.x = [%s]\n", str);
	double_to_string(ray_cast.ray_dir.y, str, sizeof(str));
	ft_dprintf(fd, "\tray_dir.y = [%s]\n", str);
}

static void	debug_grid_and_next_distance(int fd, t_ray_cast ray_cast)
{
	char	str[32];

	ft_dprintf(fd, "Current grid position (x, y) ... int\n");
	ft_dprintf(fd, "\tgrid.x = [%d]\n", ray_cast.grid.x);
	ft_dprintf(fd, "\tgrid.y = [%d]\n", ray_cast.grid.y);
	ft_dprintf(fd, "Step direction in X, Y (-1 or 1) ... int\n");
	ft_dprintf(fd, "\tstep_dir.x = [%d]\n", ray_cast.step_dir.x);
	ft_dprintf(fd, "\tstep_dir.y = [%d]\n", ray_cast.step_dir.y);
	ft_dprintf(fd, "Distance to the next side ... double\n");
	double_to_string(ray_cast.next_distance.x, str, sizeof(str));
	ft_dprintf(fd, "\tnext_distance.x = [%s]\n", str);
	double_to_string(ray_cast.next_distance.y, str, sizeof(str));
	ft_dprintf(fd, "\tnext_distance.y = [%s]\n", str);
	ft_dprintf(fd, "Distance between grid to next_distance ... double\n");
	double_to_string(ray_cast.delta_distance.x, str, sizeof(str));
	ft_dprintf(fd, "\tdelta_distance = [%s]\n", str);
	double_to_string(ray_cast.delta_distance.y, str, sizeof(str));
	ft_dprintf(fd, "\tdelta_distance = [%s]\n", str);
}

void	debug_ray_cast(t_frame *frame, const char *msg, int x)
{
	int			fd;
	t_ray_cast	ray_cast;
	char		str[32];

	if (IS_DEBUG != true)
		return ;
	fd = frame->debug.fd;
	ray_cast = frame->ray_cast;
	ft_dprintf(fd, "\n>>> func debug_ray_cast() ... call by '%s' <<<\n", msg);
	double_to_string((double)IMG_3D_WIDTH, str, sizeof(str));
	ft_dprintf(fd, "\tx [%d], window_width / 2 [%f]\n", x, str);
	ft_dprintf(fd, "---- ray_cast ----\n");
	debug_camera_plane_and_ray_dir(fd, ray_cast);
	debug_grid_and_next_distance(fd, ray_cast);
	ft_dprintf(fd, "\n\n");
}
