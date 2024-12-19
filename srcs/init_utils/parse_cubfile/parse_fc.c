/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 19:38:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief get infomation type (floor or ceiling)
 *
 * @return ENUM_F or ENUM_C
 */
static t_type_fc	get_type_of_fc(const char *line, const char *key[])
{
	t_type_fc	type;

	type = ENUM_F;
	while (type < ENUM_C)
	{
		if (is_key_line(line, key[type]) == true)
			break ;
		type++;
	}
	return (type);
}

static void	set_fc_color(t_game *game, int *color)
{
	game->floor_color = color[ENUM_F];
	game->ceiling_color = color[ENUM_C];
	game->frame.ceiling_color = &game->ceiling_color;
	game->frame.floor_color = &game->floor_color;
}

static int	check_error_rgb_value(t_result result, const char rgb_type)
{
	if (result.value >= 0)
		return (EXIT_SUCCESS);
	if (result.value == -1)
		ft_printf("%s%c: %s %s\n",
			ERR_PROMPT, rgb_type, EMSG_RGB_MISS, result.err_msg);
	if (result.value == -2)
	{
		ft_printf("%s%c: \"", ERR_PROMPT, rgb_type);
		print_until_ch(STDOUT_FILENO, result.err_msg, ',');
		ft_printf("\" %s\n", EMSG_RGB_RANGE_OUT);
	}
	if (result.value == -3)
	{
		ft_printf("%s%c: \"", ERR_PROMPT, rgb_type);
		print_until_ch(STDOUT_FILENO, result.err_msg, ',');
		ft_printf("\" %s\n", EMSG_RGB_NOT_NUM);
	}
	if (result.value == -4)
		ft_printf("%s%c: %s %s\n",
			ERR_PROMPT, rgb_type, EMSG_UP_TO_THREE_RGB, result.err_msg);
	return (EXIT_FAILURE);
}

int	get_fc_color(const char *first_word, int *color)
{
	const char	*next_word;
	char		*str;
	t_result	result;

	next_word = find_next_word(first_word);
	if (next_word == NULL)
	{
		ft_printf("%s%c: %s\n",
			ERR_PROMPT, *first_word, EMSG_RGB_EMPTY);
		return (EXIT_FAILURE);
	}
	str = strdup_trimmed_line(next_word);
	if (str == NULL)
		return (EXIT_FAILURE);
	result = get_rgb_color(str);
	if (check_error_rgb_value(result, *first_word) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	*color = result.value;
	free(str);
	return (EXIT_SUCCESS);
}
//Reference error_cub3d.h
//# define EMSG_RGB_EMPTY		"Empty RGB component"
//// EX: "F"
//// 		- result.value : not use
//// 		- Out : "Error: F: Empty RGB component"
//
//# define EMSG_RGB_MISS		"Missing RGB component"
//// EX: "F 10, 10, ,", "F 10, 10 ", and more ...
//// 		- result.value : -1
//// 		- Out : "Error: F: Missing RGB component B"
//
//# define EMSG_RGB_RANGE_OUT	"Out of range (0 ~ 255)"
//// EX: "F 8523, 42, 42"
//// 		- result.value : -2
//// 		- Out : "Error: F: "8523" Out of range"
//
//# define EMSG_RGB_NOT_NUM	"is not a number"
//// EX: "F i, 42, 42"
//// 		- result.value : -3
//// 		- Out : "Error: F: "i" is not a number"
//
//# define EMSG_UP_TO_THREE_RGB	"Up to three RGB value"
//// EX: "F 0,255,0,0"
//// 		- result.value : -4
//// 		- Out : "Error: F: Up to three RGB value"

int	parse_fc(const char *line, t_parse *parse)
{
	t_type_fc	type;
	const char	*key[2] = {"F ", "C "};
	const int	bit[2] = {BIT_F, BIT_C};
	static int	color[2] = {-1, -1};

	parse->fc_info = (t_info){.key = key, .bit = bit};
	type = get_type_of_fc(line, parse->fc_info.key);
	if (check_duplicate_info(parse->flag, bit[type], line) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (get_fc_color(line, &color[type]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	parse->flag |= parse->fc_info.bit[type];
	debug_parse_fc(parse->game->debug.fd, color, "parse_fc()");
	if (check_for_not_matching_bit(parse->flag, BIT_F | BIT_C) == 0x00)
	{
		set_fc_color(parse->game, color);
		parse->flag |= BIT_INIT_FC;
	}
	return (EXIT_SUCCESS);
}
