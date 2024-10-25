/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:02:12 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/26 00:29:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_texture_coordinate(int fd, double wall_x, t_frame *frame,
			const char *msg)
{
	t_vector	ray_dir;
	t_vector	view_point;
	t_dda		dda;
	t_type_wall	type_wall;
	static char	*direction[4] = {"NORTH", "WEST", "EAST", "SOUTH"};

	dda = frame->dda;
	view_point = frame->player->view_point;
	ray_dir = frame->ray_cast.ray_dir;
	dprintf(fd, ">>> func debug_texture_coordinate() <<< ... call by %s\n",
		msg);
	dprintf(fd, "\twall_x[%f]\ttype_of_grid_line[%d]\n",
		wall_x, dda.type_of_grid_line);
	dprintf(fd, "\ttype_of_grid_line[%d]\tview_point.y[%f]\tray_dir.y[%f]\n",
		dda.type_of_grid_line, view_point.y, ray_dir.y);
	dprintf(fd, "\ttype_of_grid_line[%d]\tview_point.x[%f]\tray_dir.x[%f]\n",
		dda.type_of_grid_line, view_point.x, ray_dir.x);
	dprintf(fd, "\ttex_x[%d]\n", dda.tex_x);
	type_wall = get_texture_direction(dda.type_of_grid_line, ray_dir);
	dprintf(fd, "\ttype_wall[%d] -> [%s]\n", type_wall, direction[type_wall]);
	dprintf(fd, "\n\n");
}
// reference type_cub3d.h
//typedef enum	e_type_wall {
//	NORTH,
//	WEST,
//	EAST,
//	SOUTH
//}	t_type_wall;

void	debug_texture(char *file, t_texture texture,
			const char *msg)
{
	int			fd;
	static	int	count = 0;

	if (IS_DEBUG != true)
		return ;
	fd = texture.debug.fd;
	if (count == 0)
		dprintf(fd,
			"\n\n>>> func debug_texture() ... call by '%s' <<<\n", msg);
	dprintf(fd, "---- [%d] ... [%s] ----\n", count, file);
	dprintf(fd, "\timg_tex.img = %p\n", texture.img_tex.img);
	dprintf(fd, "\twidth = %d\n", texture.width);
	dprintf(fd, "\theight = %d\n", texture.height);
	count++;
}
//typedef struct	s_texture
//{
//	t_img	img_tex;
//	int		width;
//	int		height;
//	t_debug	debug;
//}	t_texture;

void	debug_img_tex(int fd, t_img img, int i, const char *msg)
{
	const char	*key[4];

	init_tex_keys(key, 4);
	if (IS_DEBUG != true)
		return ;
	if (i == 0)
		ft_dprintf(fd,
			"\n\n>>> func debug_texture() ... call by '%s' <<<\n", msg);
	dprintf(fd, "---- [%s] ... img_tex[%d] ----\n", key[i], i);
	dprintf(fd, "\timg[%d].img[%p]\n\taddr[%p]\n\tbpp[%d]\n",
		i, img.img, img.addr, img.bpp);
	dprintf(fd, "\tline_length[%d]\n\tendian[%d]\n",
		img.line_length, img.endian);
}
//typedef struct s_img {
//	void	*img;
//	char	*addr;
//	int		bpp;
//	int		line_length;
//	int		endian;
//	t_debug	*debug;
//}	t_img;

void	debug_put_texture_image(t_frame *frame)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = frame->debug.game->mlx;
	win = frame->debug.game->win;
	img = frame->texture[0].img_tex.img;
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	img = frame->texture[1].img_tex.img;
	mlx_put_image_to_window(mlx, win, img, 200, 50);
	img = frame->texture[2].img_tex.img;
	mlx_put_image_to_window(mlx, win, img, 50, 200);
	img = frame->texture[3].img_tex.img;
	mlx_put_image_to_window(mlx, win, img, 250, 250);
	sleep(10);
}
