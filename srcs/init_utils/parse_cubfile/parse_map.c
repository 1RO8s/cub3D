/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/20 17:59:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_error_map_size_over(int cols, int rows)
{
	ft_eprintf("%s%s: ", ERR_PROMPT, EMSG_MAP_TOO_LARGE);
	ft_eprintf("%d x %d", cols, rows);
	ft_eprintf(" (within %d x %d)\n", MAX_COLS, MAX_ROWS);
}

int	check_range_map(const char *line, t_parse *parse)
{
	size_t	rows;
	size_t	cols;
	size_t	len;
	bool	is_over_size;

	is_over_size = false;
	rows = 0;
	cols = 0;
	while (line != NULL && ft_strchr(line, '\n') != NULL)
	{
		len = ft_strchr(line, '\n') - line;
		if (cols < len)
			cols = len;
		rows++;
		if (cols > MAX_COLS || rows > MAX_ROWS)
			is_over_size = true;
		line = find_next_line(line);
	}
	if (is_over_size == true)
	{
		put_error_map_size_over((int)cols, (int)rows);
		return (EXIT_FAILURE);
	}
	(void)parse;
	return (EXIT_SUCCESS);
}

int	parse_map(const char *line, t_parse *parse)
{
	static t_parse_map	func[5] = {
		check_last_map, check_range_map, get_map_data,
		get_player_info, check_enclosed_by_walls};
	int					i;
	int					status;

	i = 0;
	while (i < 5)
	{
		status = func[i](line, parse);
		if (status != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	parse->flag |= BIT_MAP;
	return (EXIT_SUCCESS);
}
		//status = func[i](line, parse);
		//if (status != EXIT_SUCCESS)
		//{
		//	debug_parse_map_fail(parse->game->debug.fd, i);
		//	return (EXIT_FAILURE);
		//}
