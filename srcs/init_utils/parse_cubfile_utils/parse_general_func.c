/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:52:53 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 15:56:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_until_ch(int fd, const char *str, int c)
{
	size_t	len;
	const char	*end;

	if (str == NULL)
		return (EXIT_FAILURE);
	end = ft_strchr(str, c);
	if (end == NULL)
		len = ft_strlen(str);
	else
		len = end - str;
	write(fd, str, len);
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

// unnessesary ?
char	*strdup_until_ch(const char *line, int until_ch)
{
	size_t	len;
	char	*file;

	len = ft_strchr(line, until_ch) - line;
	file = ft_strndup(line, len);
	return (file);
}

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char	*strdup_trimmed_line(const char *str)
{
    const char *start = str;
    const char *end;

    // Find the position of the newline character or string termination
    while (*str && *str != '\n') {
        str++;
    }
    end = str - 1; // Start from the last character before newline

    // Trim trailing non-printable characters (including spaces)
    while (end >= start && (!isprint(*end) || isspace(*end))) {
        end--;
    }

    // Calculate the length of the trimmed line
    size_t length = (end >= start) ? (end - start + 1) : 0;

    // Allocate memory for the duplicated string
    char *result = (char *)malloc(length + 1);
    if (!result) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy the trimmed string into the new memory
    strncpy(result, start, length);
    result[length] = '\0'; // Null-terminate the string

    return result;
}
