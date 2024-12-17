/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:20:57 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/18 02:12:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map_line(const char *str)
{
	const char	*identifier = " 10NWES";
	size_t		i;
	size_t		len;

	if (*str == '\n')
		return (false);
	len = ft_strlen(identifier);
	while (*str != '\n' && *str != '\0')
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

static int	check_continue_of_map(bool is_map_line, const char *line)
{
	if (is_map_line == true && *line != '\n')
	{
		ft_eprintf("%s%s\nNG line: [", ERR_PROMPT, EMSG_MAP_CHAR);
		print_until_ch(STDOUT_FILENO, line, '\n');
		ft_eprintf("]\n");
		return (EXIT_FAILURE);
	}
	if (is_map_line == false && *line != '\n')
	{
		ft_eprintf("%s%s\n", ERR_PROMPT, EMSG_MAP_NOT_LAST);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_last_map(const char *line, t_parse *parse)
{
	bool	is_find_map;

	while (line != NULL)
	{
		is_find_map = false;
		while (is_map_line(line) == true)
		{
			is_find_map = true;
			line = find_next_line(line);
			if (line == NULL)
				return (EXIT_SUCCESS);
		}
		if (check_continue_of_map(is_find_map, line) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		line = find_next_line(line);
	}
	(void)parse;
	return (EXIT_SUCCESS);
}
