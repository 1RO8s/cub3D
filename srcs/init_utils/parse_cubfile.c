/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cubfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/30 16:00:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_find_element(const char *element)
{
	if (element == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_EMPTY_CUB);
		return (false);
	}
	return (true);
}

/**
 * @brief Parse the cub file contents
 */
int	parse_cubfile(t_parse *parse, t_game *game, const char *element)
{
	static t_parse_elem	func[3] = {parse_tex, parse_fc, parse_map};
	t_enum_elem			type;

	if (*element == '\n')
		element = find_next_element(element);
	if (is_find_element(element) == false)
		return (EXIT_FAILURE);
	while (element != NULL)
	{
		type = get_type_element(element);
		debug_element_type(game->debug.fd, element, "parse_cubfile()");
		if (type == ENUM_ELEMENT_ERR)
		{
			put_error_msg(element, EMSG_ENTRY_INVAL);
			return (EXIT_FAILURE);
		}
		if (func[type](element, parse) != EXIT_SUCCESS)
		{
			if (is_hit_flag(parse->flag, BIT_INIT_TEX) == true)
				destroy_texture_image(game->mlx, game->texture, 4);
			if (is_hit_flag(parse->flag, BIT_INIT_MAP) == true)
				free_double_pointer(game->map.data);
			return (EXIT_FAILURE);
		}
		element = find_next_element(element);
	}
	return (EXIT_SUCCESS);
}
