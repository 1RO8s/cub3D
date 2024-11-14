/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture_images.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:51:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 02:28:04 by kamitsui         ###   ########.fr       */
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
	// if (is_exist_file(file) != true)
	//{
	//	put_error_msg(file, EMSG_NOT_EXIST_FILE);
	//	return (EXIT_FAILURE);
	//}
	texture->img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file, &texture->width, &texture->height);
	if (texture->img_tex.img == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s%s: %s\n",
			ERR_PROMPT, EMSG_MLX_XPM_TO_IMG, file);
		free(file);
		return (EXIT_FAILURE);
	}
	debug_texture(file, *texture, "get_texture_image()");
	free(file);
	return (EXIT_SUCCESS);
}

bool	is_created_all_tex_image(int flag,
			const char *key[4], const int bit_tex[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((flag & bit_tex[i]) == 0x00)
		{
			put_error_msg(key[i], EMSG_ENTRY_MISS);
			//ft_dprintf(STDERR_FILENO, "%s%s: %s\n",
			//	ERR_PROMPT, key[i], EMSG_ENTRY_MISS);
			return (false);
		}
		i++;
	}
	return (true);
}

static t_type_wall	get_dir_of_wall(const char *line, const char **key)
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
// reference "type_cub3d.h"
//typedef enum e_type_wall {
//	ENUM_NORTH,
//	ENUM_WEST,
//	ENUM_EAST,
//	ENUM_SOUTH
//}	t_type_wall;

bool	is_valid_texture_entry(t_type_wall type, const char *line)
{
	if (type > ENUM_SOUTH)
	{
		put_error_msg(line, EMSG_ENTRY_INVAL);
		return (false);
	}
	return (true);
}

bool	is_duplicate_texture_entry(int flag, const int bit, const char *key)
{
	if ((flag & bit) > 0x0)
	{
		put_error_msg(key, EMSG_ENTRY_DUP);
		return (false);
	}
	return (true);
}

bool	is_empty_value_texture_entry(const char first_char, const char *key)
{
	if (first_char == '\n' || first_char == '\0')
	{
		put_error_msg(key, EMSG_XPM_FILE);
		return (false);
	}
	return (true);
}

int	check_texture_entry(t_type_wall type, const char *line, int flag, const int *bit_tex, const char **key)
{
	if (is_valid_texture_entry(type, line) != true)
		return (EXIT_FAILURE);
	if (is_duplicate_texture_entry(flag, bit_tex[type], key[type]) != true)
		return (EXIT_FAILURE);
	if (is_empty_value_texture_entry(line[3], key[type]) != true)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	create_texture_images(const char *line, t_parse *parse)
{
	const char	*key[4];
	void		*mlx;
	t_texture	*texture;
	t_type_wall	type;
	const int	bit_tex[4] = {BIT_NORTH, BIT_WEST, BIT_EAST, BIT_SOUTH};

	init_tex_keys(key, 4);
	mlx = parse->game->mlx;
	texture = parse->game->texture;
	while (line != NULL && *line != '\n' && *line != '\0')
	{
		type = get_dir_of_wall(line, key);
		if (check_texture_entry(type, line, parse->flag, bit_tex, key) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		parse->flag |= bit_tex[type];
		if (get_texture_image(mlx, &line[3], &texture[type]) != EXIT_SUCCESS)
		{
			destroy_texture_image(mlx, texture, (int)type);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	if (is_created_all_tex_image(parse->flag, key, bit_tex) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
