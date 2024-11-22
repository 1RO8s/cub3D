/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/22 12:07:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MIN_PERP_WALL_DIST 1e-4
/**
 * @brief wall_slice calculation 
 */
void	set_wall_slice(t_frame *frame, int x)
{
	t_wall_slice	wall_slice;
	double safe_perp_wall_dist;

	//wall_slice.line_height = (int)(WIN_HEIGHT / frame->dda.perp_wall_dist);// overflow
	safe_perp_wall_dist = frame->dda.perp_wall_dist;
	if (frame->dda.perp_wall_dist < MIN_PERP_WALL_DIST)
		safe_perp_wall_dist = MIN_PERP_WALL_DIST;
	wall_slice.line_height = (int)(WIN_HEIGHT / safe_perp_wall_dist);
	wall_slice.draw_start = -wall_slice.line_height / 2 + IMG_3D_HEIGHT / 2;
	wall_slice.draw_end = wall_slice.line_height / 2 + IMG_3D_HEIGHT / 2;
	if (wall_slice.draw_start < 0)
		wall_slice.draw_start = 0;
	if (wall_slice.draw_end >= WIN_HEIGHT)
		wall_slice.draw_end = WIN_HEIGHT - 1;
	frame->wall_slice = wall_slice;
	debug_wall_slice(frame->debug.fd,
		frame->dda.perp_wall_dist, wall_slice, "set_wall_slice()");
	(void)x;
}
