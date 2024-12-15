/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/16 05:43:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map_element(const char *str)
{
	const char	*identifier = " 10NWES";
	size_t		i;
	size_t		len;

	if (*str == '\n')
		return (false);
	len = ft_strlen(identifier);
	while (*str != '\n')
	{
		i = 0;
		while (i < len)
		{
			if (ft_strncmp(str, identifier + i, (size_t)1) == 0)
				break ;
			i++;
		}
		if (i == len)
			return (false);
		str++;
	}
	return (true);
}

int	check_last_map(const char *line, t_parse *parse)
{
	bool	is_checking_in_map_element;

	while (line != NULL)
	{
		is_checking_in_map_element = false;
		while (is_map_element(line) == true)
		{
			is_checking_in_map_element = true;
			line = find_next_line(line);
			if (line == NULL)
				return (EXIT_SUCCESS);
		}
		if (is_checking_in_map_element == true && *line != '\n')
		{
			// NOT MAP ELEMENT ... print line
			return (EXIT_FAILURE);
		}
		if (is_checking_in_map_element == false && *line != '\n')
		{
			printf("%s%s\n", ERR_PROMPT, EMSG_MAP_NOT_LAST);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	(void)parse;
	return (EXIT_SUCCESS);
}

static void	put_error_map_size_over(int cols, int rows)
{
	ft_dprintf(STDERR_FILENO, "%s%s: ", ERR_PROMPT, EMSG_MAP_TOO_LARGE);
	ft_dprintf(STDERR_FILENO, "%d x %d", cols, rows);
	ft_dprintf(STDERR_FILENO, " (within %d x %d)\n", MAX_COLS, MAX_ROWS);
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

static void	debug_parse_map_fail(int fd, int i)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, "fail : parse_map func[%d]\n", i);
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
		{
			debug_parse_map_fail(parse->game->debug.fd, i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	parse->flag |= BIT_MAP;
	return (EXIT_SUCCESS);
}
