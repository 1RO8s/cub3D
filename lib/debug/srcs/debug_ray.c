/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 14:10:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_camera_plane_and_ray_dir(t_ray_cast ray_cast)
{
	printf("X-cordinate on the camera plane (-1.0 to 1.0)\n");
	printf("\tcamera_plane_x = [%f]\n", ray_cast.camera_plane_x);
	printf("Direction in the ray vector ... double\n");
	printf("\tray_dir.x = [%f]\n", ray_cast.ray_dir.x);
	printf("\tray_dir.y = [%f]\n", ray_cast.ray_dir.y);
}

static void	debug_grid_and_next_distance(t_ray_cast ray_cast)
{
	printf("Current grid position (x, y) ... int\n");
	printf("\tgrid.x = [%d]\n", ray_cast.grid.x);
	printf("\tgrid.y = [%d]\n", ray_cast.grid.y);
	printf("Step direction in X, Y (-1 or 1) ... int\n");
	printf("\tstep_dir.x = [%d]\n", ray_cast.step_dir.x);
	printf("\tstep_dir.y = [%d]\n", ray_cast.step_dir.y);
	printf("Distance to the next side ... double\n");
	printf("\tnext_distance.x = [%f]\n", ray_cast.next_distance.x);
	printf("\tnext_distance.y = [%f]\n", ray_cast.next_distance.y);
	printf("Distance between grid to next_distance ... double\n");
	printf("\tdelta_distance = [%f]\n", ray_cast.delta_distance.x);
	printf("\tdelta_distance = [%f]\n", ray_cast.delta_distance.y);
}

void	debug_ray_cast(t_frame *frame, const char *msg, int x)
{
	int			fd;
	t_ray_cast	ray_cast;
	int	original_stdout_fd;


	if (IS_DEBUG != true)
		return ;
	fd = frame->debug.fd;
	ray_cast = frame->ray_cast;
	dprintf(fd, "\n>>> func debug_ray_cast() ... call by '%s' <<<\n", msg);
	dprintf(fd, "\tx [%d], window_width / 2 [%f]\n", x, (double)IMG_3D_WIDTH);
	dprintf(fd, "---- ray_cast ----\n");
	original_stdout_fd = set_stdout_fd(fd);
	debug_camera_plane_and_ray_dir(ray_cast);
	debug_grid_and_next_distance(ray_cast);
	close(original_stdout_fd);
	dprintf(fd, "\n\n");
}
