/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_slice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:34:03 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/17 19:55:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
