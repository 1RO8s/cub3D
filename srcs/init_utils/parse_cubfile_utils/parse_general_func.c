/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:52:53 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/14 23:51:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_until_ch(int fd, const char *str, int c)
{
	size_t	len;

	if (str == NULL)
		return (EXIT_FAILURE);
	p = ft_strchr(str, c);
	if (p == NULL)
		len = ft_strlen(str);
	else
		len = p - str;
	write(fd, str, len);
	return (EXIT_SUCCESS);
}

int	check_flags(int variable, int flags_to_check)
{
	if ((variable & flags_to_check) == flags_to_check)
		return (0);
	return (flags_to_check & ~variable);
}

// for debug
int	print_until_nl(int fd, const char *str)
{
	size_t	len;

	if (str == NULL)
		return (EXIT_FAILURE);
	len = ft_strchr(str, '\n') - str;
	write(fd, str, len);
	return (EXIT_SUCCESS);
}

const char	*find_next_word(const char *s)
{
	// move function -> ***_utils.c ??
	if (s == NULL || *s == '\0' || *s == '\n')
		return (NULL);
	while (*s != ' ')
	{
		s++;
		if (*s == '\0' || *s == '\n')
			return (NULL);
	}
	while (*s == ' ')
	{
		s++;
		if (*s == '\0' || *s == '\n')
			return (NULL);
	}
	return (s);
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
