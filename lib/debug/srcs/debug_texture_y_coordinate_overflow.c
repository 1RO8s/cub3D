/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture_y_coordinate_overflow.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:53:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 15:02:30 by kamitsui         ###   ########.fr       */
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

static void	check_overflow(t_frame *frame, int y)
{
	tex_y = get_texture_y_coordinate(frame, y);
	tex_y_ng = get_texture_y_coordinate_ng(frame, y);
	if (tex_y != tex_y_ng)
	{
		ft_dprintf(STDERR_FILENO,
			"\toverflow min y[%4d] -> tex_y[%d] , tex_y_ng[%d]",
			y, tex_y, tex_y_ng);
		ft_dprintf(STDERR_FILENO,
			"\ttexture.height[%d]\n", frame->texture->height);
	}
}

void	debug_texture_y_coordinate_overflow(t_frame *frame, int y)
{
	int			tex_y;
	int			tex_y_ng;

	if (IS_DEBUG != true)
		return ;
	check_overflow(frame, y);
	check_overflow(frame, y);
	y = frame->wall_slice.draw_end;
	tex_y = get_texture_y_coordinate(frame, y);
	tex_y_ng = get_texture_y_coordinate_ng(frame, y);
	if (tex_y != tex_y_ng)
	{
		ft_dprintf(STDERR_FILENO,
			"\toverflow max y[%4d] -> tex_y[%d] , tex_y_ng[%d]",
			y, tex_y, tex_y_ng);
		ft_dprintf(STDERR_FILENO,
			"\ttexture.height[%d]\n", frame->texture->height);
	}
}
