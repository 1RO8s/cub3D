/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_entry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:02:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 16:02:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_texture_entry(t_type_wall type, const char *line)
{
	if (type > ENUM_SOUTH)
	{
		put_error_msg(line, EMSG_ENTRY_INVAL);
		return (false);
	}
	return (true);
}

static bool	is_duplicate_texture_entry(int flag, const int bit, const char *key)
{
	if ((flag & bit) > 0x0)
	{
		put_error_msg(key, EMSG_ENTRY_DUP);
		return (false);
	}
	return (true);
}

static bool	is_empty_value_texture_entry(const char first_char, const char *key)
{
	if (first_char == '\n' || first_char == '\0')
	{
		put_error_msg(key, EMSG_XPM_FILE);
		return (false);
	}
	return (true);
}

int	check_texture_entry(t_type_wall type, const char *line, t_parse *parse)
{
	int			flag;
	const int	*bit;
	const char	*key;

	flag = parse->flag;
	bit = &parse->tex_info.bit[type];
	key = parse->tex_info.key[type];
	if (is_valid_texture_entry(type, line) != true)
		return (EXIT_FAILURE);
	if (is_duplicate_texture_entry(flag, *bit, key) != true)
		return (EXIT_FAILURE);
	if (is_empty_value_texture_entry(line[3], key) != true)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
