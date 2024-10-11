/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:47:33 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/11 11:12:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_pixel(t_img img_tex, int tex_x, int tex_y)
{
	int	offset = (tex_y * img_tex.line_length) + (tex_x * (img_tex.bpp / 8));
	int	color = *(int *)(img_tex.addr + offset);
	return (color);
}
//typedef struct s_img {
//	void	*img;
//	char	*addr;
//	int		bpp;
//	int		line_length;
//	int		endian;
//	t_debug	*debug;
//	//t_debug	*debug;// fix *debug -> debug
//}	t_img;

/**
 * @brief Draw the vertical line from wall_slice ( draw_start to draw_end )
 */
void	draw_vertical_line(t_one_shot_3d *one_shot_3d, int x)
{
	int				y;
	t_wall_slice	wall_slice;
	t_img			img_3d;

	wall_slice = (t_wall_slice)one_shot_3d->wall_slice;
	img_3d = (t_img)one_shot_3d->img_3d;
	if (x < 0 || x >= IMG_3D_WIDTH)
		return ;
	if (wall_slice.draw_start < 0)
		wall_slice.draw_start = 0;
	if (wall_slice.draw_end >= WIN_HEIGHT)
		wall_slice.draw_end = WIN_HEIGHT - 1;
	y = wall_slice.draw_start;
	int	line_height = wall_slice.line_height;
	int	tex_x = one_shot_3d->dda.tex_x;
	int	tex_height = one_shot_3d->dda.tex_height;
	t_img	img_tex = one_shot_3d->dda.img_tex;
	while (y <= wall_slice.draw_end)
	{
		int d = (y * 256) - (IMG_3D_HEIGHT * 128) + (line_height * 128);
		int	tex_y = ((d * tex_height) / line_height) / 256;
		int	color = get_texture_pixel(img_tex, tex_x, tex_y);
		my_mlx_pixel_put(&img_3d, x, y, color);
		//my_mlx_pixel_put(&img_3d, x, y, wall_slice.color);
		y++;
	}
}
