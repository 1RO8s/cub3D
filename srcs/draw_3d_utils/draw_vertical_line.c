/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:47:33 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/14 21:35:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_frame *frame, int x, int ceiling_end)
{
	int	y;

	y = 0;
	while (y < ceiling_end)
	{
		my_mlx_pixel_put(frame->img_3d, x, y, *frame->ceiling_color);
		y++;
	}
}

void	draw_floor(t_frame *frame, int x, int floor_start)
{
	int	y;

	y = floor_start;
	while (y < IMG_3D_HEIGHT)
	{
		my_mlx_pixel_put(frame->img_3d, x, y, *frame->floor_color);
		y++;
	}
}

static int	get_color_texture_pixel(t_frame *frame, int tex_x, int tex_y)
{
	int		offset;
	int		color;
	t_img	img_tex;

	img_tex = frame->dda.texture.img_tex;
	offset = (tex_y * img_tex.line_length) + (tex_x * (img_tex.bpp / 8));
	color = *(int *)(img_tex.addr + offset);// compatibility ??
	return (color);
}

static int	get_texture_y_coordinate(t_frame *frame, int y)
{
	int	d;
	int	line_height;
	int	tex_height;

	line_height = frame->wall_slice.line_height;
	tex_height = frame->dda.texture.height;
	d = (y * 256) - (IMG_3D_HEIGHT * 128) + (line_height * 128);
	return (((d * tex_height) / line_height) / 256);
}

/**
 * @brief Draw the vertical line from wall_slice ( draw_start to draw_end )
 */
void	draw_vertical_line(t_frame *frame, int x)
{
	int				y;
	int				tex_x;
	int				tex_y;
	int				color;
	t_wall_slice	wall_slice;

	tex_x = frame->dda.tex_x;
	wall_slice = (t_wall_slice)frame->wall_slice;
	if (x < 0 || x >= IMG_3D_WIDTH)
		return ;
	if (wall_slice.draw_start < 0)
		wall_slice.draw_start = 0;
	if (wall_slice.draw_end >= IMG_3D_HEIGHT)
		wall_slice.draw_end = IMG_3D_HEIGHT - 1;
	y = wall_slice.draw_start;
	draw_ceiling(frame, x, wall_slice.draw_start);
	y = wall_slice.draw_start;
	//draw_wall(frame);
	while (y <= frame->wall_slice.draw_end)
	{
		tex_y = get_texture_y_coordinate(frame, y);
		color = get_color_texture_pixel(frame, tex_x, tex_y);
		my_mlx_pixel_put(frame->img_3d, x, y, color);
		y++;
	}
	draw_floor(frame, x, wall_slice.draw_end);
}
