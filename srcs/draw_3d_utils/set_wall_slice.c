/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/11 21:12:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_coordinate(t_one_shot_3d *one_shot_3d)
{
	double	wall_x;
	t_vector	view_point;
	t_vector	ray_dir;
	t_dda	*dda;
	int		fd;

	fd = one_shot_3d->debug.fd;
	dda = &one_shot_3d->dda;
	view_point = one_shot_3d->player.view_point;
	ray_dir = one_shot_3d->ray_cast.ray_dir;
	if (dda->type_of_grid_line == 0)
		wall_x = view_point.y + dda->perp_wall_dist * ray_dir.y;
	else
		wall_x = view_point.x + dda->perp_wall_dist * ray_dir.x;
	wall_x -= floor(wall_x);
	dprintf(fd, "---- texture debug ----\n");
	dprintf(fd, "\twall_x[%f]\ttype_of_grid_line[%d]\n", wall_x, dda->type_of_grid_line);
	dprintf(fd, "\ttype_of_grid_line[%d]\tview_point.y[%f]\tray_dir.y[%f]\n", dda->type_of_grid_line, view_point.y, ray_dir.y);
	dprintf(fd, "\ttype_of_grid_line[%d]\tview_point.x[%f]\tray_dir.x[%f]\n", dda->type_of_grid_line, view_point.x, ray_dir.x);

	// Get texture width from hit wall texture
	if (dda->type_of_grid_line == 0 && ray_dir.x > 0)
		dda->texture = one_shot_3d->texture[NORTH];
	if (dda->type_of_grid_line == 1 && ray_dir.y < 0)
		dda->texture = one_shot_3d->texture[NORTH];

	dda->tex_x = (int)(wall_x * (double)dda->texture.width);
	if (dda->type_of_grid_line == 0 && ray_dir.x > 0)
	{
		dda->tex_x = dda->texture.width - dda->tex_x - 1;
	}
	if (dda->type_of_grid_line == 1 && ray_dir.y < 0)
	{
		dda->tex_x = dda->texture.width - dda->tex_x - 1;
	}
	dprintf(fd, "\ttex_x[%d]\n", dda->tex_x);
}
//typedef struct s_dda {
//	int		type_of_grid_line;
//	double	perp_wall_dist;
//	int		tex_x;
//	t_texture	texture;
////	t_img	img_tex;
////	int		tex_width;
////	int		tex_height;
//}	t_dda;



void	set_wall_slice(t_one_shot_3d *one_shot_3d, int x)
{
	int				h;
	double			perp_wall_dist;
	t_wall_slice	wall_slice;
	int				type_of_grid_line;

	h = WIN_HEIGHT;
	perp_wall_dist = one_shot_3d->dda.perp_wall_dist;
//	debug_texture_coordinate(one_shot_3d);
	wall_slice.line_height = (int)(h / perp_wall_dist);
	wall_slice.draw_start = -wall_slice.line_height / 2 + h / 2;
	wall_slice.draw_end = wall_slice.line_height / 2 + h / 2;
	if (wall_slice.draw_start < 0)
		wall_slice.draw_start = 0;
	if (wall_slice.draw_end >= h)
		wall_slice.draw_end = h - 1;
	type_of_grid_line = one_shot_3d->dda.type_of_grid_line;
	if (type_of_grid_line == ON_HORIZONTAL_LINE)
		wall_slice.color = COLOR_WHITE; // north-south walls
	else
		wall_slice.color = COLOR_GREY; // east-west walls
	one_shot_3d->wall_slice = wall_slice;
	debug_wall_slice(one_shot_3d->debug.fd,
		perp_wall_dist, wall_slice, "set_wall_slice()");//debug
	set_texture_coordinate(one_shot_3d);
	(void)x;
}
