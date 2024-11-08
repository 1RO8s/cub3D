/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/08 15:41:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_last_map(const char *line, t_parse *parse)
{
	(void)parse;
	if (find_next_element(line) != NULL)
	{
		dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_MAP_NOT_LAST);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

#define MAX_ROWS 100
#define MAX_COLS 100
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
	//	printf("nl_line[%p]\n", ft_strchr(line, '\n'));
	//	printf("eof_line[%p]\n", ft_strchr(line, '\0'));
		len = ft_strchr(line, '\n') - line;
		if (cols < len)
			cols = len;
		rows++;
		if (cols > MAX_COLS || rows > MAX_ROWS)
			is_over_size = true;
		line = find_next_line(line);
	}
	//printf("here?\n");// debug
	//printf("\ncol[%zu] row[%zu] is_over[%d]\n", cols, rows, is_over_size);// debug
	if (is_over_size == true)
	{
		dprintf(STDERR_FILENO, "%s%s: ", ERR_PROMPT, EMSG_MAP_TOO_LARGE);
		dprintf(STDERR_FILENO, "%zu x %zu", cols, rows);
		dprintf(STDERR_FILENO, " (within %d x %d)\n", MAX_COLS, MAX_ROWS);
		//printf("\ncol[%zu] row[%zu] is_over[%d]\n", cols, rows, is_over_size);// debug
		return (EXIT_FAILURE);
	}
	(void)parse;
	//printf("success\n");// debug
	return (EXIT_SUCCESS);
}

void	debug_parse_map_fail(int fd, int i)
{
	if (IS_DEBUG != true)
		return ;
	dprintf(fd, "fail : parse_map func[%d]\n", i);//debug
}

int	parse_map(const char *line, t_parse *parse)
{
	static t_parse_map	func[5] = {
			check_last_map, check_range_map, get_map_data,
			get_player_info, check_enclosed_by_walls};
	int						i;
	int						status;

	i = 0;
	while (i < 5)
	{
		status = func[i](line, parse);
		if (status != EXIT_SUCCESS)
		{
			debug_parse_map_fail(parse->game->debug.fd, i);// debug
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
