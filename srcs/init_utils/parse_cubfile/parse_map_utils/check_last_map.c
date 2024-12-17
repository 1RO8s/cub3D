/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:20:57 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 19:21:06 by kamitsui         ###   ########.fr       */
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
			ft_printf("%s%s\nNG line: [", ERR_PROMPT, EMSG_MAP_CHAR);
			print_until_ch(STDOUT_FILENO, line, '\n');
			ft_printf("]\n");
			return (EXIT_FAILURE);
		}
		if (is_checking_in_map_element == false && *line != '\n')
		{
			ft_printf("%s%s\n", ERR_PROMPT, EMSG_MAP_NOT_LAST);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	(void)parse;
	return (EXIT_SUCCESS);
}
