/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:52:53 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 18:53:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_until_nl(int fd, const char *str)
{
	size_t	len;

	if (str == NULL)
		return (EXIT_FAILURE);
	len = ft_strchr(str, '\n') - str;
	write(fd, str, len);
	return (EXIT_SUCCESS);
}

char	*find_next_line(const char *contents)
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

bool	is_key_line(const char *line, const char *key)
{
	size_t	len;

	len = ft_strlen(key);
	return (ft_strncmp(line, key, len) == 0);
}

char	*strdup_until_ch(const char *line, int until_ch)
{
	size_t	len;
	char	*file;

	len = ft_strchr(line, until_ch) - line;
	file = ft_strndup(line, len);
	return (file);
}
