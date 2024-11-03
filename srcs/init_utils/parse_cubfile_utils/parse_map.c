/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/03 23:16:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_last_map(const char *line)
{
	return (find_next_element(line) == NULL);
}

#define MAX_ROWS 100
#define MAX_COLS 100
bool	is_range_map(const char *line)
{
	size_t	row;
	size_t	culom;
	
	row = 0;
	col = 0;
	while (line != NULL)
	{
		len = ft_strchr(line, '\n') - line;
		if (col < len)
			col = len;
		row++;
		if (col > MAX_COLS || row > MAX_ROWS)
			return (false);
		line = find_next_line(line);
	}
	return (true);
}

int	parse_map(const char *line, t_parse *parse)
{
	static t_is_valid_map	func[3] = {
			is_last_map, is_range_map, get_map_data,
			get_plater_info, is_enclosed_by_wall};
	int						i;

	i = 0;
	while (i < 3)
	{
		status = func[i](line, parse);
		if (status != EXIT_SUCCESS)
		{
			// print error:msg
			return (EXIT_FAILURE);
		}
		i++;
	}
	//printf("line[%s]\n", line);
//	if (get_map_data(&parse->game->map, line) != EXIT_SUCCESS)
//		return (EXIT_FAILURE);
//	if (get_player_info(&parse->game->map, &parse->game->player) != EXIT_SUCCESS)
//		return (EXIT_FAILURE);
	parse->flag |= BIT_MAP;
	return (EXIT_SUCCESS);
}
