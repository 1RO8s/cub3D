/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/14 02:11:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_type_wall	get_texture_direction(int type_of_grid_line, t_vector ray_dir)
{
	if (type_of_grid_line == 1)
	{
		if (ray_dir.y < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (ray_dir.x < 0)
			return (WEST);
		else
			return (EAST);
	}
}
//texture[NORTH]
//type_of_grid_line == 1
//ray_dir.y < 0
//
//texture[EAST]
//type_of_grid_line == 0
//ray_dir.x < 0
//
//texture[WEST]
//type_of_grid_line == 0
//ray_dir.x >= 0
//
//texture[SOUTH]
//type_of_grid_line == 1
//ray_dir.y >= 0

/**
 * @brief Calculate wall texture's X-coordinate ( wall_x : 0.0 ~ 1.0 )
 */
void	set_texture_x_coordinate(t_frame *frame, int x)
{
	double		wall_x;
	t_vector	view_point;
	t_vector	ray_dir;
	t_dda		*dda;
	t_type_wall	type_wall;

	dda = &frame->dda;
	view_point = frame->player->view_point;
	ray_dir = frame->ray_cast.ray_dir;
	if (dda->type_of_grid_line == 0)
		wall_x = view_point.y + dda->perp_wall_dist * ray_dir.y;
	else
		wall_x = view_point.x + dda->perp_wall_dist * ray_dir.x;
	wall_x -= floor(wall_x);
	type_wall = get_texture_direction(dda->type_of_grid_line, ray_dir);
	dda->texture = frame->texture[type_wall];
	dda->tex_x = (int)(wall_x * (double)dda->texture.width);
	if (dda->type_of_grid_line == 0 && ray_dir.x > 0)
		dda->tex_x = dda->texture.width - dda->tex_x - 1;
	if (dda->type_of_grid_line == 1 && ray_dir.y < 0)
		dda->tex_x = dda->texture.width - dda->tex_x - 1;
	debug_texture_coordinate(frame->debug.fd, wall_x, frame,
		"end set_texture_x_coordinage()");//debug
	//debug_put_texture_image(frame);//debug
	(void)x;
}
// reference cub3.h
//typedef struct s_dda {
//	int		type_of_grid_line;
//	double	perp_wall_dist;
//	int		tex_x;
//	t_texture	texture;
//}	t_dda;

/**
 * @brief wall_slice calculation 
 */
void	set_wall_slice(t_frame *frame, int x)
{
	t_wall_slice	wall_slice;

	wall_slice.line_height = (int)(WIN_HEIGHT / frame->dda.perp_wall_dist);
	wall_slice.draw_start = -wall_slice.line_height / 2 + IMG_3D_HEIGHT / 2;
	wall_slice.draw_end = wall_slice.line_height / 2 + IMG_3D_HEIGHT / 2;
	if (wall_slice.draw_start < 0)
		wall_slice.draw_start = 0;
	if (wall_slice.draw_end >= WIN_HEIGHT)
		wall_slice.draw_end = WIN_HEIGHT - 1;
	frame->wall_slice = wall_slice;
	debug_wall_slice(frame->debug.fd,
		frame->dda.perp_wall_dist, wall_slice, "set_wall_slice()");//debug
	(void)x;
}
