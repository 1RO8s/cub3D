/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:50:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 21:51:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_lines(const char *str)
{
	size_t	lines;

	lines = 0;
	while (*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return (lines + 1);
}

static char	*extract_next_line(const char **str)
{
	const char	*start;
	size_t		len;
	char		*line;

	start = *str;
	while (**str && **str != '\n')
		(*str)++;
	len = *str - start;
	line = ft_strndup(start, len);
	if (line == NULL)
		return (NULL);
	if (**str == '\n')
		(*str)++;
	return (line);
}

char	**split_lines(const char *str)
{
	size_t	line_count;
	char	**lines;
	size_t	i;

	if (str == NULL)
		return (NULL);
	line_count = count_lines(str);
	lines = (char **)malloc((line_count + 1) * sizeof(char *));
	if (lines == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
		lines[i++] = extract_next_line(&str);
	lines[i] = NULL;
	return (lines);
}
