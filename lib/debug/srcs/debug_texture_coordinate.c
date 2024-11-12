/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture_coordinate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:37:25 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 14:38:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_x_y_coordinate(int type_of_grid_line,
			t_vector view_point, t_vector ray_dir)
{
	printf("\ttype_of_grid_line[%d]\tview_point.y[%f]\tray_dir.y[%f]\n",
		type_of_grid_line, view_point.y, ray_dir.y);
	printf("\ttype_of_grid_line[%d]\tview_point.x[%f]\tray_dir.x[%f]\n",
		type_of_grid_line, view_point.x, ray_dir.x);
}

static void	put_texture_coordinate(int fd, double wall_x, t_frame *frame)
{
	int			original_stdout_fd;
	t_dda		dda;
	t_type_wall	type_wall;
	static char	*direction[4] = {"NORTH", "WEST", "EAST", "SOUTH"};

	original_stdout_fd = set_stdout_fd(fd);
	dda = frame->dda;
	printf("\twall_x[%f]\ttype_of_grid_line[%d]\n",
		wall_x, dda.type_of_grid_line);
	put_x_y_coordinate(dda.type_of_grid_line,
		frame->player->view_point, frame->ray_cast.ray_dir);
	printf("\ttex_x[%d]\n", dda.tex_x);
	type_wall = get_texture_direction(
			dda.type_of_grid_line, frame->ray_cast.ray_dir);
	printf("\ttype_wall[%d] -> [%s]\n", type_wall, direction[type_wall]);
	if (dup2(original_stdout_fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	close(original_stdout_fd);
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
