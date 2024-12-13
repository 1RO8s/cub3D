/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture_y_coordinate_overflow.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:53:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:03:32 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_y_coordinate_ng(t_frame *frame, int y)
{
	int	d;
	int	line_height;
	int	tex_height;

	line_height = frame->wall_slice.line_height;
	tex_height = frame->dda.texture.height;
	d = (y * 256) - (IMG_3D_HEIGHT * 128) + (line_height * 128);
	return (((d * tex_height) / line_height) / 256);
}

static void	check_min_overflow(t_frame *frame, int y)
{
	int			tex_y;
	int			tex_y_ng;

	tex_y = get_texture_y_coordinate(frame, y);
	tex_y_ng = get_texture_y_coordinate_ng(frame, y);
	if (tex_y != tex_y_ng)
	{
		printf(
			"\toverflow min y[%4d] -> tex_y[%d] , tex_y_ng[%d]",
			y, tex_y, tex_y_ng);
		printf(
			"\ttexture.height[%d]\n", frame->texture->height);
	}
}

static void	check_max_overflow(t_frame *frame, int y)
{
	int			tex_y;
	int			tex_y_ng;

	tex_y = get_texture_y_coordinate(frame, y);
	tex_y_ng = get_texture_y_coordinate_ng(frame, y);
	if (tex_y != tex_y_ng)
	{
		printf(
			"\toverflow max y[%4d] -> tex_y[%d] , tex_y_ng[%d]",
			y, tex_y, tex_y_ng);
		printf(
			"\ttexture.height[%d]\n", frame->texture->height);
	}
}

void	debug_texture_y_coordinate_overflow(t_frame *frame, int y)
{
	if (IS_DEBUG != true)
		return ;
	check_min_overflow(frame, y);
	y = frame->wall_slice.draw_end;
	check_max_overflow(frame, y);
}
