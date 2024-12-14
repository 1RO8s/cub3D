/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/14 23:15:54 by kamitsui         ###   ########.fr       */
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
		printf("%s%c: \"", ERR_PROMPT, first_world);
		print_until_ch(STDOUT_FILENO, result.err_msg, ',');
		printf("\" %s\n", EMSG_RGB_RANGE_OUT);
		return (EXIT_FAILURE);
	}
	if (result.value == -3)
	{
		printf("%s%c: \"", ERR_PROMPT, first_world);
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
//// RGB
//// If no the string for RGB					... not use result.value
//# define EMSG_RGB_EMPTY		"Empty RGB component"
//// example	"Error: F: Empty RGB component"			... F
//
//// If no value in any of the RGB				... result.value == -1
//# define EMSG_RGB_MISS		"Missing RGB component"
//// example	"Error: F: Missing RGB component B" 	... "F 10, 10, ,"  &  "F 10, 10 "
//
//// If rgb value is range over					... result.value == -2
//# define EMSG_RGB_RANGE_OUT	"Out of range (0 ~ 255)"
//// example	"Error: F: "8523" Out of range"			... F 8523, 42, 42
//
//// If the string of rgb value is not a number	... result.value == -3
//# define EMSG_RGB_NOT_NUM	"is not a number"
//// example	"Error: F: "i" is not a number"			...	F i, 42, 42
//
//// If rgb values are more three				... result.value == -4
//# define EMSG_UP_TO_THREE_RGB	"Up to three RGB value"
// example	"Error: F: Up to three RGB value"			... F 0,255,0,0

int	parse_fc(const char *line, t_parse *parse)
{
	t_enum_fc	type;
	const char	*key[2] = {"F ", "C "};
	const int	bit[2] = {BIT_F, BIT_C};
	static int	color[2] = {-1, -1};

	//parse->fc_info = create_fc_info(key, bit, color);
	parse->fc_info = (t_fc_info){.key = key, .bit = bit, .color = color};
	type = get_type_of_fc(line, parse->fc_info.key);
	if (check_fc_info(type, line, parse) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (get_fc_color(line, &color[type]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	parse->flag |= parse->tex_info.bit[type];
	debug_parse_fc(parse->game->debug.fd, color, "parse_fc()");
	if (check_flags(parse->flag, BIT_F | BIT_C) == 0)
	{
		set_fc_color(parse->game, color, type);
		parse->flag |= BIT_INIT_FC;
	}
	return (EXIT_SUCCESS);
}
