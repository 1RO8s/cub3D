/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enable_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 15:31:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_next_line(char *contents)
{
	char	*line;

	line = ft_strchr(contents, '\n');
	if (line == NULL)
		return (NULL);
	line++;
	if (*line == '\0')
		return (NULL);
	return (line);
}

static char	*find_next_content(char *contents)
{
	char	*line;

	line = contents;
	while (line != NULL)
	{
		line = get_next_line(line);
		if (line == NULL)
			return (NULL);
		if (*line != '\n')
			break ;
	}
	return (line);
}
// behavior of line(NULL or "\n" or "exist_line"
// NULL : next line is empty
// "\n" : continue call get_next_line
// "exist_line" : return line

bool	is_last_element(char *map_content)
{
	char	*next_content;

	next_content = find_next_content(map_content);
	return (next_content == NULL);
}

bool	is_enable_map(char *file_contents, char *map_content)
{
	char	*key[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	char	*other_content;
	int		i;

	// check the place where is map content in file_contents
	i = 0;
	while (i < 6)
	{
		other_content = find_element_line(file_contents, key[i]);
		if (other_content == NULL)
			return (false);
		if (other_content > map_content)
			return (false);
		i++;
	}
	if (is_last_element(map_content) != true)
		return (false);
	// check closed map
	// check other invalid case ?
	return (true);
}
