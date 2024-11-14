/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture_coordinate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:37:25 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 00:24:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_x_y_coordinate(int fd, int type_of_grid_line,
			t_vector view_point, t_vector ray_dir)
{
	char	str[SIZE_DOUBLE_TO_STR];

	double_to_string(view_point.y, str, sizeof(str));
	ft_dprintf(fd, "\ttype_of_grid_line[%d]\tview_point.y[%s]",
		type_of_grid_line, str);
	double_to_string(ray_dir.y, str, sizeof(str));
	ft_dprintf(fd, "\tray_dir.y[%s]\n", str);
	double_to_string(view_point.y, str, sizeof(str));
	ft_dprintf(fd, "\ttype_of_grid_line[%d]\tview_point.y[%s]",
		type_of_grid_line, str);
	double_to_string(ray_dir.x, str, sizeof(str));
	ft_dprintf(fd, "\tray_dir.x[%s]\n", str);
}

static void	put_texture_coordinate(int fd, double wall_x, t_frame *frame)
{
	t_dda		dda;
	t_type_wall	type_wall;
	static char	*direction[4] = {"NORTH", "WEST", "EAST", "SOUTH"};
	char		str[SIZE_DOUBLE_TO_STR];

	dda = frame->dda;
	double_to_string(wall_x, str, sizeof(str));
	ft_dprintf(fd, "\twall_x[%s]\ttype_of_grid_line[%d]\n",
		str, dda.type_of_grid_line);
	put_x_y_coordinate(fd, dda.type_of_grid_line,
		frame->player->view_point, frame->ray_cast.ray_dir);
	ft_dprintf(fd, "\ttex_x[%d]\n", dda.tex_x);
	type_wall = get_texture_direction(
			dda.type_of_grid_line, frame->ray_cast.ray_dir);
	ft_dprintf(fd, "\ttype_wall[%d] -> [%s]\n",
		type_wall, direction[type_wall]);
}
// reference type_cub3d.h
//typedef enum	e_type_wall {
//	NORTH,
//	WEST,
//	EAST,
//	SOUTH
//}	t_type_wall;

void	debug_texture_coordinate(int fd, double wall_x, t_frame *frame,
			const char *msg)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, ">>> func debug_texture_coordinate() <<< ... call by %s\n",
		msg);
	put_texture_coordinate(fd, wall_x, frame);
	ft_dprintf(fd, "\n\n");
}
