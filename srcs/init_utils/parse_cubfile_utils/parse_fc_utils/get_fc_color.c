/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fc_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:51:51 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/16 21:30:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_color_entry(const char *line, t_parse *parse)
{
	char		*color_str;
	t_enum_fc	type;

	type = parse->entry.type;
	if (is_key_line(line, parse->entry.key[type]) == false)
		return (CONTINUE);
	color_str = strdup_until_ch(&line[2], '\n');
	if (color_str == NULL)
		return (EXIT_FAILURE);
	if ((parse->flag & parse->entry.bit[type]) > 0)
	{
		ft_dprintf(STDERR_FILENO, "%s%c: %s\n",
			ERR_PROMPT, *parse->entry.key[type], EMSG_ENTRY_DUP);
		free(color_str);
		return (EXIT_FAILURE);
	}
	parse->entry.color[type] = get_rgb_color(
			type, parse->entry.key[type], color_str, parse->game->debug.fd);
	if (parse->entry.color[type] == -1)
		return (EXIT_FAILURE);
	parse->flag |= parse->entry.bit[type];
	free(color_str);
	return (EXIT_SUCCESS);
}

int	get_fc_color_line(const char *line, t_parse *parse)
{
	int	status;

	parse->entry.type = ENUM_F;
	while (parse->entry.type <= ENUM_C)
	{
		status = parse_color_entry(line, parse);
		if (status == CONTINUE)
		{
			parse->entry.type++;
			continue ;
		}
		else if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
		break ;
	}
	return (EXIT_FAILURE);
}

int	get_fc_color(const char *line, t_parse *parse)
{
	while (line != NULL && *line != '\n')
	{
		if (get_fc_color_line(line, parse) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (parse->entry.type == ENUM_C + 1)
		{
			put_error_msg(line, EMSG_ENTRY_INVAL);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	return (EXIT_SUCCESS);
}
