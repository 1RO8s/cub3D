/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:42:41 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:19:07 by hnagasak         ###   ########.fr       */
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

	printf(ERR_PROMPT);
	len = 0;
	while (is_entry_char(entry[len]) == true)
		len++;
	write(STDERR_FILENO, entry, len);
	printf(": %s\n", msg);
}
