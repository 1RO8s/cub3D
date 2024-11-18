/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:02:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/19 01:36:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_tex_info(t_type_wall type, const char *line)
{
	if (type > ENUM_SOUTH)
	{
		put_error_msg(line, EMSG_ENTRY_INVAL);
		return (false);
	}
	return (true);
}

static bool	is_duplicate_tex_info(int flag, const int bit, const char *key)
{
	if ((flag & bit) > 0x0)
	{
		put_error_msg(key, EMSG_ENTRY_DUP);
		return (false);
	}
	return (true);
}

static bool	is_empty_value_tex_info(const char first_char, const char *key)
{
	if (first_char == '\n' || first_char == '\0')
	{
		put_error_msg(key, EMSG_XPM_FILE);
		return (false);
	}
	return (true);
}

int	check_tex_info(t_type_wall type, const char *line, t_parse *parse)
{
	int			flag;
	const int	*bit;
	const char	*key;

	flag = parse->flag;
	bit = &parse->tex_info.bit[type];
	key = parse->tex_info.key[type];
	if (is_valid_tex_info(type, line) != true)
		return (EXIT_FAILURE);
	if (is_duplicate_tex_info(flag, *bit, key) != true)
		return (EXIT_FAILURE);
	if (is_empty_value_tex_info(line[3], key) != true)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
