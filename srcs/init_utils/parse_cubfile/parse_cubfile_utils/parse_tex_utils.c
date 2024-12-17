/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:51:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/18 02:09:34 by kamitsui         ###   ########.fr       */
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
	file = strdup_trimmed_line(next_word);
	if (file == NULL)
		return (EXIT_FAILURE);
	texture->img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file, &texture->width, &texture->height);
	if (texture->img_tex.img == NULL)
	{
		ft_eprintf("%s%s: %s\n", ERR_PROMPT, EMSG_MLX_XPM_TO_IMG, file);
		free(file);
		return (EXIT_FAILURE);
	}
	debug_texture(file, *texture, "get_texture_image()");
	free(file);
	return (EXIT_SUCCESS);
}

// Probably Unnessesary
/**
 * @brief initialize tex_info structure
 */

int	create_texture_image(const char *line, t_parse *parse, t_type_wall type)
{
	void		*mlx;
	t_texture	*texture;

	mlx = parse->game->mlx;
	texture = parse->game->texture;
	if (get_texture_image(mlx, line, &texture[type]) != EXIT_SUCCESS)
	{
		destroy_texture_image(mlx, texture, parse->flag);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
// debug code
//	debug_tex_info(parse->game->debug.fd, parse->tex_info);
