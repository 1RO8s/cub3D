/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_x_coordinate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:55:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/21 09:43:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_type_wall	get_texture_direction(
						int type_of_grid_line, t_vector ray_dir)
{
	if (type_of_grid_line == 1)
	{
		if (ray_dir.y < 0)
			return (ENUM_SOUTH);
		else
			return (ENUM_NORTH);
	}
	else
	{
		if (ray_dir.x < 0)
			return (ENUM_EAST);
		else
			return (ENUM_WEST);
	}
}
// reference type_cub3d.h
//typedef enum e_type_wall {
//	NORTH,
//	WEST,
//	EAST,
//	SOUTH
//}	t_type_wall;

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
	if (dda->type_of_grid_line == 0 && ray_dir.x < 0)
		dda->tex_x = dda->texture.width - dda->tex_x - 1;
	if (dda->type_of_grid_line == 1 && ray_dir.y >= 0)
		dda->tex_x = dda->texture.width - dda->tex_x - 1;
	(void)x;
}
//	debug code
	//debug_texture_coordinate(frame->debug.fd, wall_x, frame,
	//	"end set_texture_x_coordinage()");
//	debug_put_texture_image(frame);
//	Note : comment out in source file because using forbidden function
//
// reference cub3.h
//typedef struct s_dda {
//	int		type_of_grid_line;
//	double	perp_wall_dist;
//	int		tex_x;
//	t_texture	texture;
//}	t_dda;
