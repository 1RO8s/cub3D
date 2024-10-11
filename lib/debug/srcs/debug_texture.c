/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:02:12 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/11 11:16:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_texture(char *xpm_file_name, t_texture texture,
			int i, const char *msg)
{
	const char	*key[4] = {"NO", "SO", "WE", "EA"};
	int			fd;

	if (IS_DEBUG != true)
		return ;
	fd = texture.debug.fd;
	if (i == 0)
		dprintf(fd, "\n\n>>> func debug_texture_image() ... call by '%s' <<<\n", msg);
	dprintf(fd, "---- [%s] ... [%s] ----\n", key[i], xpm_file_name);
	dprintf(fd, "\timg_tex.img = %p\n", texture.img_tex.img);
	dprintf(fd, "\twidth = %d\n", texture.width);
	dprintf(fd, "\theight = %d\n", texture.height);
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
	const char	*key[4] = {"NO", "SO", "WE", "EA"};

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
