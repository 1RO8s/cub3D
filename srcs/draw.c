/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:07:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/01 10:51:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// Function to perform isometric projection
static void	set_screen_point(t_Point3D points,
		int *new_x, int *new_y, int *new_color)
{
	int	old_x;
	int	old_y;
	int	old_z;

	old_x = points.x * TILE_SIZE;
	old_y = points.y * TILE_SIZE;
	old_z = points.z * TILE_SIZE;
	*new_x = (int)(cos(ANGLE_Y) * (old_x) - cos(ANGLE_Y) * (old_y)) + OFFSET_X;
	*new_y = (int)(sin(ANGLE_X) * (old_x) + sin(ANGLE_X) * (old_y)) + OFFSET_Y
		- old_z;
	*new_color = points.color;
}

static void	connect_two_points(t_data *data, t_wire screen,
		t_Point3D next_point)
{
	set_screen_point(next_point, &screen.x1, &screen.y1, &screen.color1);
	draw_line(data, &screen);
}

void	draw_wireframe_model(t_data *data, t_Point3D **points,
		int rows, int cols)
{
	t_wire	screen;
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			set_screen_point(points[i][j], &screen.x0, &screen.y0,
				&screen.color0);
			if (j < cols - 1)
				connect_two_points(data, screen, points[i][j + 1]);
			if (i < rows - 1)
				connect_two_points(data, screen, points[i + 1][j]);
			j++;
		}
		i++;
	}
}
//#include "ft_printf.h"
//	ft_printf("rows:%d cols:%d\tin draw_wireframe_model()\n", rows, cols);
