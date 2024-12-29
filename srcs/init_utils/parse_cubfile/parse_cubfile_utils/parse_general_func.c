/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:52:53 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/29 17:31:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_until_ch(int fd, const char *str, int c)
{
	size_t		len;
	ssize_t		result;
	const char	*end;

	if (str == NULL)
		return (EXIT_FAILURE);
	end = ft_strchr(str, c);
	if (end == NULL)
		len = ft_strlen(str);
	else
		len = end - str;

	result = write(fd, str, len);
	if (result == -1)
	{
	    perror("write failed");
	    exit(EXIT_FAILURE);
	}
	else if ((size_t)result != len)
	{
	    ft_eprintf("Partial write. Only %lu bytes out of %lu were written.\n",
			(size_t)result, len);
	    exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Check for not matching bit
 *
 * @param variable is a value to be checked
 * @param flags_is comparative value
 *
 * @return 0x00 : Bits match,  Bit over than 0x00 : Not match
 */
int	check_for_not_matching_bit(int variable, int flags_to_check)
{
	if ((variable & flags_to_check) == flags_to_check)
		return (0x00);
	return (flags_to_check & ~variable);
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

char	*strdup_trimmed_line(const char *str)
{
	const char	*start;
	const char	*end;
	size_t		length;
	char		*result;

	start = str;
	while (*str && *str != '\n')
		str++;
	end = str - 1;
	while (end >= start && (!ft_isprint(*end) || ft_isspace(*end)))
		end--;
	length = (end >= start) * (end - start + 1);
	result = ft_strndup(start, length);
	return (result);
}
