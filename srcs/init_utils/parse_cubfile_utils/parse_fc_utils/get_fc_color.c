/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fc_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:51:51 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:19:11 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_fc_color(const char *line, t_parse *parse)
{
	char		*color_str;
	t_enum_fc	type;

	type = parse->fc_info.type;
	if (is_key_line(line, parse->fc_info.key[type]) == false)
		return (CONTINUE);
	color_str = strdup_until_ch(&line[2], '\n');
	if (color_str == NULL)
		return (EXIT_FAILURE);
	if ((parse->flag & parse->fc_info.bit[type]) > 0)
	{
		printf("%s%c: %s\n",
			ERR_PROMPT, *parse->fc_info.key[type], EMSG_ENTRY_DUP);
		free(color_str);
		return (EXIT_FAILURE);
	}
	parse->fc_info.color[type] = get_rgb_color(
			type, parse->fc_info.key[type], color_str, parse->game->debug.fd);
	if (parse->fc_info.color[type] == -1)
		return (EXIT_FAILURE);
	parse->flag |= parse->fc_info.bit[type];
	free(color_str);
	return (EXIT_SUCCESS);
}

int	get_fc_color_line(const char *line, t_parse *parse)
{
	int	status;

	parse->fc_info.type = ENUM_F;
	while (parse->fc_info.type <= ENUM_C)
	{
		status = parse_fc_color(line, parse);
		if (status == CONTINUE)
		{
			parse->fc_info.type++;
			continue ;
		}
		else if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
		break ;
	}
	return (EXIT_SUCCESS);
}

int	get_fc_color(const char *line, t_parse *parse)
{
	while (line != NULL && *line != '\n')
	{
		if (get_fc_color_line(line, parse) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (parse->fc_info.type == ENUM_C + 1)
		{
			put_error_msg(line, EMSG_ENTRY_INVAL);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	return (EXIT_SUCCESS);
}
