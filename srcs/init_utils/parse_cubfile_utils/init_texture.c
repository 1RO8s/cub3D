/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:21:58 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/18 05:24:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_value_from_file_contents(char *file_contents, const char *key)
{
	char	*line;
	char	*value;

	line = get_element_line(file_contents, (char *)key);
	if (line == NULL)
		return (NULL);
	value = extract_value(line, (char *)key);
	return (value);
}
// line is freed in extract_value()

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

static int	get_texture_images(
		void *mlx, t_texture *texture, char *file_contents)
{
	const char	*key[4] = {"NO", "WE", "EA", "SO"};
	int			i;
	char		*xpm_file_name;

	i = 0;
	while (i < 4)
	{
		xpm_file_name = get_value_from_file_contents(file_contents, key[i]);
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
