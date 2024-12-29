/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:42:41 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/29 17:31:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_entry_char(const char c)
{
	return (c != ' ' && c != '\0' && c != '\n');
}

void	put_error_msg(const char *entry, const char *msg)
{
	size_t	len;
	ssize_t	result;

	ft_eprintf("%s", ERR_PROMPT);
	len = 0;
	while (is_entry_char(entry[len]) == true)
		len++;

	result = write(STDERR_FILENO, entry, len);
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
	ft_eprintf(": %s\n", msg);
}
