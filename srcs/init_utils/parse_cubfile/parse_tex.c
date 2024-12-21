/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:43:41 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/20 18:00:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief get texture address from the specific type texture
 *
 * @return EXIT_SUCCESS(0) , EXIT_FAILURE(1)
 */
static int	get_texture_addr(t_texture *texture, t_type_wall type)
{
	t_img	*img;

	img = (t_img *)&texture[type].img_tex;
	img->addr = (char *)mlx_get_data_addr(
			img->img, &img->bpp, &img->line_length, &img->endian);
	if (img->addr == NULL)
	{
		ft_eprintf("%s%s\n", ERR_PROMPT, EMSG_IMG_DATA_ADDR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
	//debug_img_tex(texture[type].debug.fd, texture[type].img_tex, type,
	//	"after mlx_get_data_addr()");

/**
 * @brief get direction of wall
 *
 * @return ENUM_NORTH or ENUM_WEST or ENUM_EAST or ENUM_SOUTH
 */
static t_type_wall	get_type_of_wall(const char *line, const char *key[])
{
	t_type_wall	type;

	type = ENUM_NORTH;
	while (type < ENUM_SOUTH)
	{
		if (is_key_line(line, key[type]) == true)
			break ;
		type++;
	}
	return (type);
}

int	parse_tex(const char *line, t_parse *parse)
{
	void				*mlx;
	t_texture			*texture;
	t_type_wall			type;
	static const char	*key[4] = {"NO ", "WE ", "EA ", "SO "};
	static const int	bit[4] = {BIT_NORTH, BIT_WEST, BIT_EAST, BIT_SOUTH};

	mlx = parse->game->mlx;
	texture = parse->game->texture;
	type = get_type_of_wall(line, key);
	if (check_duplicate_info(parse->flag, bit[type], line) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (create_texture_image(line, parse, type) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (get_texture_addr(texture, type) != EXIT_SUCCESS)
	{
		destroy_texture_image(mlx, texture, parse->flag);
		return (EXIT_FAILURE);
	}
	parse->flag |= bit[type];
	if (check_for_not_matching_bit(parse->flag,
			BIT_NORTH | BIT_SOUTH | BIT_EAST | BIT_WEST) == 0x00)
		parse->flag |= BIT_INIT_TEX;
	return (EXIT_SUCCESS);
}
