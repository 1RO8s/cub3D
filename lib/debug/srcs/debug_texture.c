/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:02:12 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/21 03:13:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_texture(char *file, t_texture texture,
			const char *msg)
{
	int			fd;
	static int	count = 0;

	if (IS_DEBUG != true)
		return ;
	fd = texture.debug.fd;
	if (count == 0)
		ft_dprintf(fd,
			"\n\n>>> func debug_texture() ... call by '%s' <<<\n", msg);
	ft_dprintf(fd, "---- [%d] ... [%s] ----\n", count, file);
	ft_dprintf(fd, "\timg_tex.img = %p\n", texture.img_tex.img);
	ft_dprintf(fd, "\twidth = %d\n", texture.width);
	ft_dprintf(fd, "\theight = %d\n", texture.height);
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
	const char	*key[4] = {"NO ", "WE ", "EA ", "SO "};

	if (IS_DEBUG != true)
		return ;
	if (i == 0)
		ft_dprintf(fd,
			"\n\n>>> func debug_texture() ... call by '%s' <<<\n", msg);
	ft_dprintf(fd, "---- [%s] ... img_tex[%d] ----\n", key[i], i);
	ft_dprintf(fd, "\timg[%d].img[%p]\n\taddr[%p]\n\tbpp[%d]\n",
		i, img.img, img.addr, img.bpp);
	ft_dprintf(fd, "\tline_length[%d]\n\tendian[%d]\n",
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
//
// Note : Comment out because with using sleep (Forbidden function)
//void	debug_put_texture_image(t_frame *frame)
//{
//	void	*mlx;
//	void	*win;
//	void	*img;
//
//	mlx = frame->debug.game->mlx;
//	win = frame->debug.game->win;
//	img = frame->texture[0].img_tex.img;
//	mlx_put_image_to_window(mlx, win, img, 0, 0);
//	img = frame->texture[1].img_tex.img;
//	mlx_put_image_to_window(mlx, win, img, 200, 50);
//	img = frame->texture[2].img_tex.img;
//	mlx_put_image_to_window(mlx, win, img, 50, 200);
//	img = frame->texture[3].img_tex.img;
//	mlx_put_image_to_window(mlx, win, img, 250, 250);
//	sleep(10);
//}
