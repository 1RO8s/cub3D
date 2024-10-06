/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/05 19:20:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_coordinate(t_one_shot_3d *one_shot_3d)
{
	double	wall_x;
	t_vector	view_point;
	t_vector	ray_dir;

	double	perp_wall_dist;
	int		side;
	int		fd;

	fd = one_shot_3d->debug.fd;
	perp_wall_dist = one_shot_3d->dda.perp_wall_dist;
	view_point = one_shot_3d->player.view_point;
	ray_dir = one_shot_3d->ray_cast.ray_dir;
	side = one_shot_3d->dda.type_of_grid_line;
	if (side == 0)
		wall_x = view_point.y + perp_wall_dist * ray_dir.y;
	else
		wall_x = view_point.x + perp_wall_dist * ray_dir.x;
	wall_x -= floor(wall_x);
	dprintf(fd, "---- texture debug ----\n");
	dprintf(fd, "\twall_x[%f]\tside[%d]\n", wall_x, side);
	dprintf(fd, "\tside[%d]\tview_point.y[%f]\tray_dir.y[%f]\n", side, view_point.y, ray_dir.y);
	dprintf(fd, "\tside[%d]\tview_point.x[%f]\tray_dir.x[%f]\n", side, view_point.x, ray_dir.x);
	int	tex_x;
	double	tex_width;
	tex_width = 200;// example
	tex_x = (int)(wall_x * (double)tex_width);
	if (side == 0 && ray_dir.x > 0) tex_x = tex_width - tex_x - 1;
	if (side == 1 && ray_dir.y < 0) tex_x = tex_width - tex_x - 1;
	dprintf(fd, "\ttex_x[%d]\n", tex_x);

}



void	set_wall_slice(t_one_shot_3d *one_shot_3d, int x)
{
	int				h;
	int				line_height;
	t_dda			dda;
	t_wall_slice	wall_slice;

	h = WIN_HEIGHT;
//	debug_texture_coordinate(one_shot_3d);
	dda = one_shot_3d->dda;
	line_height = (int)(h / dda.perp_wall_dist);
	wall_slice.draw_start = -line_height / 2 + h / 2;
	wall_slice.draw_end = line_height / 2 + h / 2;
	if (wall_slice.draw_start < 0)
		wall_slice.draw_start = 0;
	if (wall_slice.draw_end >= h)
		wall_slice.draw_end = h - 1;
	if (dda.type_of_grid_line == ON_HORIZONTAL_LINE)
		wall_slice.color = COLOR_WHITE; // north-south walls
	else
		wall_slice.color = COLOR_GREY; // east-west walls
	one_shot_3d->wall_slice = wall_slice;
	debug_wall_slice(one_shot_3d, line_height, "set_wall_slice()");
	set_texture_coordinate(one_shot_3d);
	(void)x;
}
