/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/10 10:24:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_coordinate(t_one_shot_3d *one_shot_3d)
{
	double	wall_x;
	t_vector	view_point;
	t_vector	ray_dir;

	t_dda	dda;
	double	perp_wall_dist;
	int		type_of_grind_line;
	int		fd;

	fd = one_shot_3d->debug.fd;
	dda = one_shot_3d->dda;
	//perp_wall_dist = one_shot_3d->dda.perp_wall_dist;
	view_point = one_shot_3d->player.view_point;
	ray_dir = one_shot_3d->ray_cast.ray_dir;
	//type_of_grind_line = one_shot_3d->dda.type_of_grid_line;
	if (dda.type_of_grind_line == 0)
		wall_x = view_point.y + dda.perp_wall_dist * ray_dir.y;
	else
		wall_x = view_point.x + dda.perp_wall_dist * ray_dir.x;
	wall_x -= floor(wall_x);
	dprintf(fd, "---- texture debug ----\n");
	dprintf(fd, "\twall_x[%f]\ttype_of_grind_line[%d]\n", wall_x, dda.type_of_grind_line);
	dprintf(fd, "\ttype_of_grind_line[%d]\tview_point.y[%f]\tray_dir.y[%f]\n", dda.type_of_grind_line, view_point.y, ray_dir.y);
	dprintf(fd, "\ttype_of_grind_line[%d]\tview_point.x[%f]\tray_dir.x[%f]\n", dda.type_of_grind_line, view_point.x, ray_dir.x);
	//int	tex_x;
	//double	tex_width;
	//tex_width = 200;// example : 200

	// Get texture width from hit wall texture
	if (dda.type_of_grind_line == 0 && ray_dir.x > 0)
		dda.tex_width = one_shot_3d->texture.width[0];// unfinish
	if (dda.type_of_grind_line == 1 && ray_dir.y < 0)
		dda.tex_width = one_shot_3d->texture.width[0];// unfinish

	// one_shot_3d->texture...  texture->width[i] 0:NORTH, 1:SOUTH, 2:WEST, 3:EAST
	dda.tex_x = (int)(wall_x * (double)dda.tex_width);
	if (dda.type_of_grind_line == 0 && ray_dir.x > 0)
	{
		dda.tex_x = dda.tex_width - dda.tex_x - 1;
	}
	if (dda.type_of_grind_line == 1 && ray_dir.y < 0)
	{
		dda.tex_x = dda.tex_width - dda.tex_x - 1;
	}
	dprintf(fd, "\ttex_x[%d]\n", dda.tex_x);
}
//typedef struct s_dda {
//	int		type_of_grid_line;
//	double	perp_wall_dist;
//	int		tex_x;
//	t_img	img_tex;
//	int		tex_width;
//	int		tex_height;
//}	t_dda;



void	set_wall_slice(t_one_shot_3d *one_shot_3d, int x)
{
	int				h;
	int				line_height;
	t_dda			dda;
	t_wall_slice	wall_slice;

	h = WIN_HEIGHT;
//	debug_texture_coordinate(one_shot_3d);
	dda = one_shot_3d->dda;
	wall_slice.line_height = (int)(h / dda.perp_wall_dist);
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
	debug_wall_slice(one_shot_3d, line_height, "set_wall_slice()");//debug
	set_texture_coordinate(one_shot_3d);
	(void)x;
}
