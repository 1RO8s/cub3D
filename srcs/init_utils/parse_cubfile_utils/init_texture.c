/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:21:58 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 01:02:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_value_from_file_contents(char *file_contents, const char *key)
{
	char	*line;

	line = get_element_line(file_contents, key);
	if (line == NULL)
		return (NULL);
	return (extract_value(line, key));
}

static int	get_texture_image(void *mlx, t_texture *texture, char *file_contents)
{
	const char	key[4] = {"NO", "SO", "WE", "EA"};
	int			i;
	char		*xpm_file_name;
	t_texture	texture;

	i = 0;
	while (i < 4 && (status == EXIT_SUCCESS))
	{
		xpm_file_name = get_value_from_file_contents(file_contents, key[i]);
		if (xpm_file_name == NULL)
		{
			destroy_n_image(mlx, texture->img, i);
			return (EXIT_FAILURE);
		}
		texture->img_texture[i] = mlx_xpm_file_to_image(mlx, xpm_file_name,
				&texture->width[i], &texture->height[i]);
		if (texture->img_texture[i] == NULL)
		{
			free(xpm_file_name);
			destroy_n_image(mlx, texture->img, i);
			return (EXIT_FAILURE);
		}
		free(xpm_file_name);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	enable_texture_image(t_texture *texture)
{
	int		i;
	void	*img;
	char	*addr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;

	i = 0;
	while (i < 4)
	{
		img = texture->img[i];
		if (img == NULL)
			return (EXIT_FAILURE);
		bits_per_pixel = &(img_texture[i]->bpp);
		size_line = &(img_texture[i]->line_length);
		endian = &(img_texture[i]->endian);
		addr = (char *)mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
		if (addr == NULL)
		{
			return (EXIT_FAILURE);
		}
		img_texture[i]->addr = addr;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_texture(void *mlx, t_texture *texture, char *file_contents)
{
	if (get_texture_image(mlx, texture, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (enable_texture_image(texture) == EXIT_SUCCESS)
	{
		// destroy texture image[4]
		return (EXIT_FAILURE);
	}
	debug_texture(texture->debug.fd, texture, file_contents);
	return (EXIT_SUCCESS);
}
