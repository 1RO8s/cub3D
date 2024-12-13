/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture_images.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:51:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:03:37 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_image(
		void *mlx, const char *file_line, t_texture *texture)
{
	char	*file;

	file = strdup_until_ch(file_line, '\n');
	if (file == NULL)
		return (EXIT_FAILURE);
	texture->img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file, &texture->width, &texture->height);
	if (texture->img_tex.img == NULL)
	{
		printf( "%s%s: %s\n",
			ERR_PROMPT, EMSG_MLX_XPM_TO_IMG, file);
		free(file);
		return (EXIT_FAILURE);
	}
	debug_texture(file, *texture, "get_texture_image()");
	free(file);
	return (EXIT_SUCCESS);
}

static bool	is_created_all_tex_image(t_parse *parse)
{
	int			i;
	int			flag;
	const int	*bit;
	const char	**key;

	flag = parse->flag;
	bit = parse->tex_info.bit;
	key = parse->tex_info.key;
	i = 0;
	while (i < ENUM_SOUTH + 1)
	{
		if ((flag & bit[i]) == 0x00)
		{
			put_error_msg(key[i], EMSG_ENTRY_MISS);
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @brief get direction of wall
 *
 * @return ENUM_NORTH or ENUM_WEST or ENUM_EAST or ENUM_SOUTH
 */
static t_type_wall	get_dir_of_wall(const char *line, const char *key[])
{
	t_type_wall	type;

	type = ENUM_NORTH;
	while (type < ENUM_SOUTH)
	{
		if (is_key_line(line, key[type]) != true)
		{
			type++;
			continue ;
		}
		break ;
	}
	return (type);
}

/**
 * @brief initialize tex_info structure
 */
static t_tex_info	create_tex_info(const char **key, const int *bit)
{
	return ((t_tex_info){.key = key, .bit = bit});
}

int	create_texture_images(const char *line, t_parse *parse)
{
	void		*mlx;
	t_texture	*texture;
	t_type_wall	type;
	const char	*key[4] = {"NO ", "WE ", "EA ", "SO "};
	const int	bit[4] = {BIT_NORTH, BIT_WEST, BIT_EAST, BIT_SOUTH};

	parse->tex_info = create_tex_info(key, bit);
	mlx = parse->game->mlx;
	texture = parse->game->texture;
	while (line != NULL && *line != '\n' && *line != '\0')
	{
		type = get_dir_of_wall(line, parse->tex_info.key);
		if (check_tex_info(type, line, parse) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		parse->flag |= parse->tex_info.bit[type];
		if (get_texture_image(mlx, &line[3], &texture[type]) != EXIT_SUCCESS)
		{
			destroy_texture_image(mlx, texture, (int)type);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	if (is_created_all_tex_image(parse) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
// debug code
//	debug_tex_info(parse->game->debug.fd, parse->tex_info);
