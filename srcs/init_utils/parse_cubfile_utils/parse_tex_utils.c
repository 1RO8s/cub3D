/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:51:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/16 03:13:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_image(
		void *mlx, const char *first_word, t_texture *texture)
{
	const char	*next_word;
	char		*file;

	next_word = find_next_word(first_word);
	if (next_word == NULL)
	{
		put_error_msg(first_word, EMSG_XPM_FILE);
		return (EXIT_FAILURE);
	}
	file = strdup_until_ch(next_word, '\n');
	if (file == NULL)
		return (EXIT_FAILURE);
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

// fix and remove
// is_complite_init() ... ***_utils.c
//static bool	is_created_all_tex_image(t_parse *parse)
//{
//	int			i;
//	int			flag;
//	const int	*bit;
//	const char	**key;
//
//	flag = parse->flag;
//	bit = parse->tex_info.bit;
//	key = parse->tex_info.key;
//	i = 0;
//	while (i < ENUM_SOUTH + 1)
//	{
//		if ((flag & bit[i]) == 0x00)
//		{
//			put_error_msg(key[i], EMSG_ENTRY_MISS);
//			return (false);
//		}
//		i++;
//	}
//	return (true);
//}

// Probably Unnessesary
/**
 * @brief initialize tex_info structure
 */
//static t_tex_info	create_tex_info(const char **key, const int *bit)
//{
//	return ((t_tex_info){.key = key, .bit = bit});
//}

int	create_texture_image(const char *line, t_parse *parse, t_type_wall type)
{
	void		*mlx;
	t_texture	*texture;

	//parse->tex_info = create_tex_info(key, bit);
	//parse->tex_info = (t_tex_info){.key = key, .bit = bit};
	mlx = parse->game->mlx;
	texture = parse->game->texture;
	if (get_texture_image(mlx, line, &texture[type]) != EXIT_SUCCESS)
	{
		destroy_texture_image(mlx, texture, parse->flag);// refactor ??
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
// debug code
//	debug_tex_info(parse->game->debug.fd, parse->tex_info);
