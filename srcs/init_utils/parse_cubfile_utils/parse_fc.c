/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/17 23:55:48 by kamitsui         ###   ########.fr       */
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

t_entry	create_fc_info(const char **key, const int *bit, int *color)
{
	color[ENUM_F] = -1;
	color[ENUM_C] = -1;
	return ((t_entry){.key = key, .bit = bit, .type = ENUM_F, .color = color});
}
//typedef struct s_entry {
//	const char	**key;
//	const int	*bit;
//	t_enum_fc	type;
//	int			*color;
//}	t_entry;

void	set_fc_color(t_game *game, int *color)
{
	game->floor_color = color[ENUM_F];
	game->ceiling_color = color[ENUM_C];
	game->frame.ceiling_color = &game->ceiling_color;
	game->frame.floor_color = &game->floor_color;
}

int	parse_fc(const char *line, t_parse *parse)
{
	t_enum_fc	type;
	int			color[2];
	const char	*key[2] = {"F ", "C "};
	const int	bit[2] = {BIT_F, BIT_C};

	parse->entry = create_fc_info(key, bit, color);
	if (get_fc_color(line, parse) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	debug_parse_fc(parse->game->debug.fd, color, "parse_fc()");
	type = ENUM_F;
	while (type < ENUM_C + 1)
	{
		if (color[type] == -1)
		{
			ft_dprintf(STDERR_FILENO, "%s%c: %s\n",
				ERR_PROMPT, *key[type], EMSG_ENTRY_MISS);
			return (EXIT_FAILURE);
		}
		type++;
	}
	set_fc_color(parse->game, color);
	return (EXIT_SUCCESS);
}
