/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cubfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/21 15:42:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_find_element(const char *element)
{
	if (element == NULL)
	{
		ft_eprintf("%s%s\n", ERR_PROMPT, EMSG_EMPTY_CUB);
		return (false);
	}
	return (true);
}

static int	parse_element(
		const char *element, t_parse *parse, t_type_elem type, t_game *game)
{
	static t_parse_elem	func[3] = {parse_tex, parse_fc, parse_map};
	static const int	bit[3] = {BIT_INIT_TEX, BIT_INIT_FC, BIT_INIT_MAP};
	const int			tex_bit = BIT_NORTH | BIT_WEST | BIT_EAST | BIT_SOUTH;

	if (check_duplicate_info(parse->flag, bit[type], element) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (func[type](element, parse) != EXIT_SUCCESS)
	{
		if (check_for_not_matching_bit(parse->flag, tex_bit) != 0x00)
			destroy_texture_image(game->mlx, game->texture, parse->flag);
		if (is_hit_flag(parse->flag, BIT_INIT_MAP) == true)
			free_double_pointer(game->map.data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_missing_cub_contents(int flag)
{
	int			missing_bit;
	const int	success_bit = BIT_NORTH | BIT_WEST | BIT_EAST | BIT_SOUTH
		| BIT_F | BIT_C | BIT_MAP;
	const char	*key[8] = {"NO", "WE", "EA", "SO", "F", "C", NULL, "MAP"};
	int			i;
	int			bit;

	missing_bit = check_for_not_matching_bit(flag, success_bit);
	if (missing_bit != 0x00)
	{
		i = 0;
		bit = 0x01;
		while (bit <= BIT_MAP)
		{
			if (missing_bit & bit)
				ft_eprintf("%s%s: %s\n", ERR_PROMPT, key[i], EMSG_ENTRY_MISS);
			i++;
			bit <<= 1;
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Parse the cub file contents
 */
int	parse_cubfile(t_parse *parse, t_game *game, const char *element)
{
	t_type_elem			type;

	if (*element == '\n')
		element = find_next_element(element);
	if (is_find_element(element) == false)
		return (EXIT_FAILURE);
	while (element != NULL)
	{
		type = get_type_element(element);
		if (type == ENUM_ELEMENT_ERR)
		{
			put_error_msg(element, EMSG_ENTRY_INVAL);
			return (EXIT_FAILURE);
		}
		if (parse_element(element, parse, type, game) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (type == ENUM_MAP)
			break ;
		element = find_next_element(element);
	}
	if (check_missing_cub_contents(parse->flag) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
		//debug_element_type(game->debug.fd, element, "parse_cubfile()");
