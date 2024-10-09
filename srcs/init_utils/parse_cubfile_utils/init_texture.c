/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:21:58 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/09 01:28:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define TEST_NO "./texture/planks.xpm"
#define TEST_SO "./texture/planks.xpm"
#define TEST_WE "./texture/planks.xpm"
#define TEST_EA "./texture/planks.xpm"

static char *test_textures[4] = {TEST_NO, TEST_SO, TEST_WE, TEST_EA};

char	*get_value_from_file_contents(char *file_contents, const char *key)
{
	char	*line;

	line = get_element_line(file_contents, (char *)key);// refactor
	if (line == NULL)
		return (NULL);
	return (extract_value(line, (char *)key));// refactor
}

static int	get_texture_image(void *mlx, t_texture *texture, char *file_contents)
{
	const char	*key[4] = {"NO", "SO", "WE", "EA"};
	int			i;
	char		*xpm_file_name;

	i = 0;
	while (i < 4)
	{
		xpm_file_name = ft_strdup(test_textures[i]);// debug
		(void)key;// debug
		(void)file_contents;// debug
		//xpm_file_name = get_value_from_file_contents(file_contents, key[i]);
		if (xpm_file_name == NULL)
		{
			destroy_n_image(mlx, texture->img_tex, i);
			return (EXIT_FAILURE);
		}
		texture->img_tex[i].img = (void *)mlx_xpm_file_to_image(mlx, xpm_file_name,
				&texture->width[i], &texture->height[i]);
		if (texture->img_tex[i].img == NULL)
		{
			free(xpm_file_name);
			destroy_n_image(mlx, texture->img_tex, i);
			return (EXIT_FAILURE);
		}
		debug_texture(xpm_file_name, *texture, i,
			"after mlx_xpm_file_to_image");
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
		img = (void *)texture->img_tex[i].img;
		bits_per_pixel = (int *)&(texture->img_tex[i].bpp);
		size_line = (int *)&(texture->img_tex[i].line_length);
		endian = (int *)&(texture->img_tex[i].endian);
		addr = (char *)mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
		if (addr == NULL)
			return (EXIT_FAILURE);
		texture->img_tex[i].addr = addr;
		debug_img_tex(texture->debug.fd, texture->img_tex[i], i, "after mlx_get_data_addr()");
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_texture(void *mlx, t_texture *texture, char *file_contents)
{
	if (get_texture_image(mlx, texture, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (enable_texture_image(texture) != EXIT_SUCCESS)
	{
		destroy_n_image(mlx, texture->img_tex, 4);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
