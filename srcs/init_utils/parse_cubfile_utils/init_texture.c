/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:21:58 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 16:25:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_value_from_file_contents(char *file_contents, const char *key)
{
	char	*line;

	line = get_element_line(file_contents, (char *)key);// leak check ??
	if (line == NULL)
		return (NULL);
	return (extract_value(line, (char *)key));// leak check ??
}

static int	get_image_from_xpm_file(
		void *mlx, char *file_name, t_texture *texture, int i)
{
	texture[i].img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file_name, &texture[i].width, &texture[i].height);
	if (texture[i].img_tex.img == NULL)
	{
		free(file_name);
		destroy_texture_image(mlx, texture, i);
		return (EXIT_FAILURE);
	}
	debug_texture(file_name, texture[i], i,
		"after mlx_xpm_file_to_image");
	return (EXIT_SUCCESS);
}

// for debug
//#define TEST_NO "./texture/planks.xpm"
//#define TEST_SO "./texture/planks.xpm"
//#define TEST_WE "./texture/planks.xpm"
//#define TEST_EA "./texture/planks.xpm"

static int	get_texture_images(
		void *mlx, t_texture *texture, char *file_contents)
{
	const char	*key[4] = {"NO", "SO", "WE", "EA"};
	int			i;
	char		*xpm_file_name;
	//static char	*test_textures[4] = {TEST_NO, TEST_SO, TEST_WE, TEST_EA};//debug

	i = 0;
	while (i < 4)
	{
		//xpm_file_name = ft_strdup(test_textures[i]);// debug
		//(void)key;// debug
		//(void)file_contents;// debug
		xpm_file_name = get_value_from_file_contents(file_contents, key[i]);// leak check??
		if (xpm_file_name == NULL)
		{
			destroy_texture_image(mlx, texture, i);
			return (EXIT_FAILURE);
		}
		if (get_image_from_xpm_file(mlx, xpm_file_name, texture, i)
			!= EXIT_SUCCESS)
			return (EXIT_FAILURE);
		free(xpm_file_name);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	enable_texture_image(t_texture *texture)
{
	int		i;
	t_img	*img;

	i = 0;
	while (i < 4)
	{
		img = (t_img *)&texture[i].img_tex;
		img->addr = (char *)mlx_get_data_addr(
				img->img, &img->bpp, &img->line_length, &img->endian);
		if (img->addr == NULL)
			return (EXIT_FAILURE);
		debug_img_tex(texture[i].debug.fd, texture[i].img_tex, i,
			"after mlx_get_data_addr()");
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_texture(void *mlx, t_texture *texture, char *file_contents)
{
	if (get_texture_images(mlx, texture, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (enable_texture_image(texture) != EXIT_SUCCESS)
	{
		destroy_texture_image(mlx, texture, 4);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
