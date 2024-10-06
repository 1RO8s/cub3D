/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:02:12 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/06 23:17:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	debug_texture(int fd, t_texture *texture, char *file_contents)
{
	int	i;
	const char	key[4] = {"NO", "SO", "WE", "EA"};

	ft_dprintf(fd, "\n\n>>> func debug_wall_slice() ... call by '%s' <<<\n", msg);
	dprintf(fd, "---- texture debug ----\n");
	i = 0;
	while (i < 4)
	{
		dprintf(fd, "\t%s\twidth[%d]\theight[%d]\n",
			key[i], texture->width[i], texture->height[i]);
		img = texture->img_tex[i];
		dprintf(fd, "\timg_tex[%d]\timg[%p]\taddr[%p]\nbpp[%d]\tline_length[%d]\tendian[%d]\n",
			i, img.img, img.addr, img.bpp, img.line_length, img.endian);
		i++;
	}
}

//typedef struct	s_texture
//{
//	t_img	img_tex[4];
//	int		width[4];
//	int		height[4];
//}	t_texture;
//typedef struct s_img {
//	void	*img;
//	char	*addr;
//	int		bpp;
//	int		line_length;
//	int		endian;
//	t_debug	*debug;
//}	t_img;
