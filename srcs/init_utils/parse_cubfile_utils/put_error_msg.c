/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:42:41 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 17:31:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_entry_char(const char c)
{
	return (c != ' ' && c != '\0' && c != '\n');
}

void	put_error_msg(const char *entry, const char *msg)
{
	size_t	count;

	ft_dprintf(STDERR_FILENO, ERR_PROMPT);
	count = 0;
	while (is_entry_char(*entry) == true)
		count++;
	write(STDERR_FILENO, entry, count);
	ft_dprintf(STDERR_FILENO, ": %s\n", msg);
}
