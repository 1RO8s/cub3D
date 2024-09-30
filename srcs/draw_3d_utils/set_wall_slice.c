/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 17:07:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_slice(t_one_shot_3d *one_shot_3d, int x)
{
	int		h;
	int		line_height;
	t_dda	dda;
	t_wall_slice	wall_slice;

	h = WIN_HEIGHT;
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
	(void)x;
}
