/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/15 01:08:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_parse_fc(int fd, int color[2], const char *msg)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, ">>> func debug_get_rgb_color <<< ... call by %s\n", msg);
	ft_dprintf(fd, "\tF color[%x]\n", color[0]);
	ft_dprintf(fd, "\tC color[%x]\n", color[1]);
}

// Probably unnessesary ?
//t_fc_info	create_fc_info(const char **key, const int *bit, int *color)
//{
//	color[ENUM_F] = -1;
//	color[ENUM_C] = -1;
//	return ((t_fc_info)
//		{.key = key, .bit = bit, .type = ENUM_F, .color = color});
//}
//typedef struct s_fc_info {
//	const char	**key;
//	const int	*bit;
//	t_enum_fc	type;
//	int			*color;
//}	t_fc_info;

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

void	set_fc_color(t_game *game, int *color)
{
	game->floor_color = color[ENUM_F];
	game->ceiling_color = color[ENUM_C];
	game->frame.ceiling_color = &game->ceiling_color;
	game->frame.floor_color = &game->floor_color;
}

int	get_fc_color(const char *first_word, int *color)
{
	const char	*next_word;
	char		*str;
	t_result	result;

	next_word = find_next_word(first_word);
	if (next_word == NULL)
	{
		printf("%s%c: %s\n",
			ERR_PROMPT, *first_word, EMSG_RGB_EMPTY);
		return (EXIT_FAILURE);
	}
	str = strdup_until_ch(next_word, '\n');
	if (str == NULL)
		return (EXIT_FAILURE);
	result = get_rgb_color(str);
	if (result.value == -1)
	{
		printf("%s%c: %s %s\n",
			ERR_PROMPT, *first_word, EMSG_RGB_MISS, result.err_msg);
		return (EXIT_FAILURE);
	}
	if (result.value == -2)
	{
		printf("%s%c: \"", ERR_PROMPT, *first_word);
		print_until_ch(STDOUT_FILENO, result.err_msg, ',');
		printf("\" %s\n", EMSG_RGB_RANGE_OUT);
		return (EXIT_FAILURE);
	}
	if (result.value == -3)
	{
		printf("%s%c: \"", ERR_PROMPT, *first_word);
		print_until_ch(STDOUT_FILENO, result.err_msg, ',');
		printf("\" %s\n", EMSG_RGB_NOT_NUM);
		return (EXIT_FAILURE);
	}
	if (result.value == -4)
	{
		printf("%s%c: %s %s\n",
			ERR_PROMPT, *first_word, EMSG_UP_TO_THREE_RGB, result.err_msg);
		return (EXIT_FAILURE);
	}
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

	//parse->fc_info = create_fc_info(key, bit, color);
	parse->fc_info = (t_info){.key = key, .bit = bit};
	type = get_type_of_fc(line, parse->fc_info.key);
	if (check_duplicate_info(bit[type], parse->flag, line) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (get_fc_color(line, &color[type]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	parse->flag |= parse->fc_info.bit[type];
	debug_parse_fc(parse->game->debug.fd, color, "parse_fc()");
	if (check_flags(parse->flag, BIT_F | BIT_C) == 0)
	{
		set_fc_color(parse->game, color);
		parse->flag |= BIT_INIT_FC;
	}
	return (EXIT_SUCCESS);
}
