/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cubfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/16 11:39:18 by kamitsui         ###   ########.fr       */
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

static int	parse_element(
		const char *element, t_parse *parse, t_type_elem type, t_game *game)
{
	static t_parse_elem	func[3] = {parse_tex, parse_fc, parse_map};
	static const int	bit[3] = {BIT_INIT_TEX, BIT_INIT_FC, BIT_INIT_MAP};

	if (check_for_not_matching_bit(parse->flag, bit[type]) == 0x00)
	{
		//Error handling
		//printf("Duplicate XXX\n", type, element);
		return (EXIT_FAILURE);
	}
	if (func[type](element, parse) != EXIT_SUCCESS)
	{
		// fix trigger
		if (is_hit_flag(parse->flag, BIT_INIT_TEX) == true)
			destroy_texture_image(game->mlx, game->texture, parse->flag);// refactor func
		if (is_hit_flag(parse->flag, BIT_INIT_MAP) == true)
			free_double_pointer(game->map.data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_missing_cub_contents(int flag)
{
	int			missing_bit;
	const int	success_bit = BIT_NORTH | BIT_WEST | BIT_EAST | BIT_SOUTH | BIT_F | BIT_C | BIT_MAP;
	const char	*key[7] = {"NO", "WE", "EA", "SO", "F", "C", "MAP"};
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
				printf("%s%s: %s\n", ERR_PROMPT, key[i], EMSG_ENTRY_MISS);
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
		debug_element_type(game->debug.fd, element, "parse_cubfile()");
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
// "Error: F: Missing entry"
//# define EMSG_ENTRY_MISS	"Missing entry"
//# define BIT_NORTH	0x01	// 0000 0000 0001
//# define BIT_WEST		0x02	// 0000 0000 0010
//# define BIT_EAST		0x04	// 0000 0000 0100
//# define BIT_SOUTH	0x08	// 0000 0000 1000
//# define BIT_F		0x10	// 0000 0001 0000
//# define BIT_C		0x20	// 0000 0010 0000
//# define BIT_PLAYER	0x40	// 0000 0100 0000
//# define BIT_MAP		0x80	// 0000 1000 0000
//# define BIT_INIT_TEX	0x100	// 0001 0000 0000
//# define BIT_INIT_FC	0x200	// 0010 0000 0000
//# define BIT_INIT_MAP	0x400	// 0100 0000 0000
