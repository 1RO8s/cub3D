/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/04 22:02:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_last_map(const char *line, t_parse *parse)
{
	(void)parse;
	if (find_next_element(line) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

#define MAX_ROWS 100
#define MAX_COLS 100
int	check_range_map(const char *line, t_parse *parse)
{
	size_t	rows;
	size_t	cols;
	size_t	len;
	
	rows = 0;
	cols = 0;
	while (line != NULL)
	{
		len = ft_strchr(line, '\n') - line;
		if (cols < len)
			cols = len;
		rows++;
		if (cols > MAX_COLS || rows > MAX_ROWS)
			return (false);
		line = find_next_line(line);
	}
	(void)parse;
	return (true);
}

int	parse_map(const char *line, t_parse *parse)
{
	static t_parse_map	func[5] = {
			check_last_map, check_range_map, get_map_data,
			get_player_info, check_enclosed_by_walls};
	int						i;
	int						status;

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
