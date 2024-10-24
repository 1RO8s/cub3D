/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture_y_coordinate_overflow.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:53:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/20 02:54:08 by kamitsui         ###   ########.fr       */
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

void	debug_texture_y_coordinate_overflow(t_frame *frame, int y)
{
	int			tex_y;
	int			tex_y_ng;

	if (IS_DEBUG != true)
		return ;
	tex_y = get_texture_y_coordinate(frame, y);
	tex_y_ng = get_texture_y_coordinate_ng(frame, y);
	if (tex_y != tex_y_ng)
	{
		dprintf(2, "\toverflow min y[%4d] -> tex_y[%d] , tex_y_ng[%d]",
			y, tex_y, tex_y_ng);
		dprintf(2, "\ttexture.height[%d]\n", frame->texture->height);
	}
	y = frame->wall_slice.draw_end;
	tex_y = get_texture_y_coordinate(frame, y);
	tex_y_ng = get_texture_y_coordinate_ng(frame, y);
	if (tex_y != tex_y_ng)
	{
		dprintf(2, "\toverflow max y[%4d] -> tex_y[%d] , tex_y_ng[%d]",
			y, tex_y, tex_y_ng);
		dprintf(2, "\ttexture.height[%d]\n", frame->texture->height);
	}
}
